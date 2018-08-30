
import numpy as np

class ldpc_encoder:
    """ LDPC Encoder 
   
    Initialize with the desired alist
    
    alist -- string, filename of alist
   
    """
    
    def __init__(self, alist, X, D, is_23B_rate):
        
        self.H, self.N, self.M = self.create_H_from_alist(alist)

        self.X = X
        self.D = D
        self.is_23B = is_23B_rate
        
        # for codes found in the 802.16e standard, 24 is the base
        # H matrix size
        self.Z = self.N / 24

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
    
    """The following 2 functions compute the correct
    shift for a given shift value
    """
    
    def shift_size(self, val, Zf, Z0 = 96):
        if (val <= 0):
            return val
        else:
            return int(np.floor((val * Zf)/Z0))
    
    # determine shift size for the 2/3 A code rate
    def shift_size_23A(self, val, Zf):
        if (val <= 0):
            return val
        else:
            return val % Zf
        
    """Compute the parity bits
    M - M dimension from alist
    Z - Z factor from alist
    X - row index of non zero value in h_b
    d - shift from the first index of h_b
    V - precomputed V 
    """
        
    def compute_parity(self, M, Z, X, d, V):
        
        p_p = np.zeros(M, dtype=np.uint8)
        p_y = np.zeros(Z, dtype=np.uint8)
        
        #fwd sub : p_i = l_i-1  + p_i-1'
        for i in range(Z, (X+1)*Z):
            p_p[i] = V[i-Z] ^ p_p[i-Z]

        #M-1 : p_i = l_m-1  + p_0'd
        for i in range(M-1, M-1 -Z, -1):
            p_p[i] = V[i] ^ p_p[(M-1)-i]
        
            
        #back sub : p_i = l_i  + p_i+1'
        for i in range(M-1-Z, (X+1)*Z -1, -1):
            p_p[i] = V[i] ^ p_p[i+Z]
        
            
        # Y : p_y = l_x + P_x+1
        for i in range(X*Z, X*Z + Z):
            p_y[i - X*Z] = V[i] ^ p_p[Z+i]
        
        # P0
        for i in range(0, Z):
            p_p[i] = p_y[i] ^ p_p[Z*X+i]

        f = np.roll(p_p[0:Z], -d)
        
        p_out = np.zeros(M, dtype=np.uint8)
        
        for i in range(M):
            if i < Z:
                p_out[i] = p_p[i]
            else:
                p_out[i] = p_p[i] ^ f[i%Z]
                
        return p_out

    def encode_data(self, infoword):
    
        """Encode inforword using the previously
        generated encoding matrices.
        
        inforword -- numpy array, incoming encode_data
        
        returns:
        
        numpy array (uint8), codeword
        
        """
        H_b1 = self.H[0::, 0:self.N-self.M]
        
        # compute V for later use
        V = np.dot(H_b1, infoword)%2
       
        if (self.is_23B):
            shift = self.shift_size_23A(self.D, self.Z)
        else:
            shift = self.shift_size(self.D, self.Z)
            
        p = self.compute_parity(self.M, self.Z, self.X, shift, V)
        
        return np.array(np.concatenate((infoword, p), axis = 0), dtype=np.uint8)


