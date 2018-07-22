
class ldpc_decoder:
    
    """ LDPC Decoder 
    
    Initialize with the desired alist
    
    See http://www.inference.org.uk/mackay/codes/alist.html for
        documentation on the .alist format
        
    alist -- string, name of alist file
    
    """
    
    def __init__(self, alist):
        
        self.checknodes, self.N, self.M = self.read_checknodes_from_alist(alist)
        
    def read_checknodes_from_alist(self, alist):
   
        """ Read check nodes from an alist file
        
        alist -- string, name of alist file to read
        
       
        returns:
        
        mlist -- list, list of checknodes
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
            mlist.append(f.readline().split('\n')[0].split(' '))
        
        return mlist, int(N), int(M)
        

    def compute_syndrome(self, checknodes = self.checknodes, rx_codeword):
        """Compute the Syndrome
        
        checknodes -- list, checknodes for the given LDPC code
        rx_codeword -- numpy array (uint8), received LDPC codeword
        
        returns:
        
        num_errors -- int, number of errors 
        """
        num_errors = 0
        
        for i in checknodes:
            indices = i
            xorsum = 0
            
            for k in indices:
                if (k != '' and int(k) != 0):
                    xorsum ^= rx_codeword[int(k)-1]
            
            if (xorsum != 0):
                num_errors += 1
        
        return num_errors
        
    def ldpc_tdmp(self, codeword, checknodes = self.checknodes, max_iter):
        
        """Correct Errors using the Turbo-decoding Message-Passing
        (TDMP) algorithm
        
        codeword -- numpy array (float), received codeword
        checknodes -- list, checknodes for LDPC code
        max_iter -- int, max number of TDMP iterations to run
        
        returns:
        result -- numpy array (uint8), resulting codeword after LDPC decoding
        
        """
        
        LMN = np.zeros((max_iter, len(checknodes), len(codeword)))

        result = np.zeros(len(codeword), dtype=np.uint8)
        float_in = np.zeros(len(codeword))
        
        for n in range(len(codeword)):
            if codeword[n] == 0:
                float_in[n] = 1.0
            else:
                float_in[n] = -1.0
        
        

        for i in range(max_iter):
            
            # loop through all checknodes
            for m in range(len(checknodes)):
                
                nodes = checknodes[m]    

                nodes = [ int(x)-1 for x in nodes if x != '0' and x != '']

                LNM = np.zeros(len(nodes))
                
                # compute LNM message
                if i == 0:
                    for n in range(len(nodes)):
                        LNM[n] = float_in[nodes[n]]
                else:
                    for n in range(len(nodes)):
                        LNM[n] = float_in[nodes[n]] - LMN[i-1][m][nodes[n]]
                        
                # compute LMN message        
                for n in range(len(nodes)):
                    node = nodes[n]
                    
                    sign = 1.0
                    minimum = 10000.0
                    
                    for d in range(len(nodes)):
                        if d != n:
                            sign *= LNM[d]
                            
                            if abs(LNM[d])< minimum:
                                minimum = abs(LNM[d])
                                
                    if sign > 0:
                        LMN[i][m][node] =  minimum
                    else:
                        LMN[i][m][node] =  -minimum
                        
                # update codeword        
                for n in range(len(nodes)):
                    float_in[nodes[n]] = LNM[n] + LMN[i][m][nodes[n]]
                    
        # hard decision    
        for n in range(len(codeword)):
            if float_in[n] <= 0:
                result[n] = 1
            else:
                result[n] = 0
                
        return result        
