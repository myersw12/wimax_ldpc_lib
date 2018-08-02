
import numpy as np

class ldpc_encoder:
    """ LDPC Encoder 
   
    Initialize with the desired alist
    
    alist -- string, filename of alist
   
    """
    
    def __init__(self, alist):
        
        self.H, self.N, self.M = self.create_H_from_alist(alist)

        # for codes found in the 802.16e standard, 24 is the base
        # H matrix size
        self.Z = self.N / 24

        self.M1, self.M2, self.M3, self.T, self.A, self.B, self.C, self.E = self.generate_encoding_matrices(self.H, self.M, self.Z)

    def create_H_from_alist(self, alist):

        """Create H matrix from a file in the .alist format
        
        See http://www.inference.org.uk/mackay/codes/alist.html for
        documentation on the .alist format
        
        alist -- string, filename of alist
        
        returns
        H -- numpy array of size MxN, H matrix
        N -- int, N parameter from alist
        M -- int, M parameter from alist
        
        """
        
        f = open(alist, 'r')
        
        line = f.readline()
        N, M = line.split(' ')
        
        line = f.readline()
        max_col_weight, max_row_weight = line.split(' ')

        line = f.readline()
        col_weights = line.split(' ')
        col_weights.pop()
        
        line = f.readline()
        row_weights = line.split(' ')
        row_weights.pop()
        
        nlist = []
        mlist = []
        
        for i in range(int(N)):
            nlist.append(f.readline().split('\n')[0])
            
        
        for i in range(int(M)):
            mlist.append(f.readline().split('\n')[0])
        
        
        # create 2304 x 1152 matrix
        H = np.zeros((int(M), int(N)), dtype=bool)
        
        for i in range(int(M)):
            indices = mlist[i].split(' ')[0:int(max_row_weight)]
            indices = [ int(x)-1 for x in indices ]
        
            #print indices
            for k in indices:
                if k != -1:
                    H[i][k] = 1
        
        f.close()
        
        return H, int(N), int(M)

    def generate_encoding_matrices(self, H, M, Z):
        
        """generate encoding matrices for modified RU 
        encoding algorithm
        
        H -- numpy array of size MxN, H matrix for LDPC code
        M -- int, M parameter for LDPC code
        Z -- int, Z parameter for LDPC code
        
        returns:
        M1 -- numpy array M1
        M2 -- numpy array M2
        M3 -- numpy array M3
        
        """
        A = H[:M-Z,:M]
        B = H[:M-Z, M:M+Z]
        C = H[M-Z::, :M]
        E = H[M-Z::, M+Z::]
        T = H[:M-Z, M+Z::]

        T = np.linalg.inv(T) %2
        
        M1 = np.dot(E,T)%2
        M1 = np.dot(M1, A)%2
        M1 = (M1 + C)%2

        M2 = np.dot(T, A)%2

        M3 = np.dot(T, B)%2
        
        return M1, M2, M3, T, A, B, C, E

    def encode_data(self, infoword):
    
        """Encode inforword using the previously
        generated encoding matrices.
        
        inforword -- numpy array, incoming encode_data
        
        returns:
        
        numpy array (uint8), codeword
        
        """
        p1 = np.dot(self.M1, infoword)%2
        
        p2 = (np.dot(self.M2, infoword)%2 + np.dot(self.M3, p1)%2)%2
        
        return np.array(np.concatenate((infoword, p1, p2), axis = 0), dtype=np.uint8)


