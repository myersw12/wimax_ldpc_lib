import numpy as np


""" All of the base matrices from the 802.16e standard are included here.  If you want to make your own
    base matrix you should include it here.  If it follows the same rules as the matrices in the 802.16e
    standard, it will be added to the existing alists and C header/source files.
"""



h_matrix_halfrate = [ -1,  94,  73,  -1,  -1,  -1,  -1,  -1,  55,  83,  -1,  -1,  7,  0,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 
-1,  27,  -1,  -1,  -1,  22,  79,  9,  -1,  -1,  -1,  12,  -1,  0,  0,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 
-1,  -1,  -1,  24,  22,  81,  -1,  33,  -1,  -1,  -1,  0,  -1,  -1,  0,  0,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 
61,  -1,  47,  -1,  -1,  -1,  -1,  -1,  65,  25,  -1,  -1,  -1,  -1,  -1,  0,  0,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 
-1,  -1,  39,  -1,  -1,  -1,  84,  -1,  -1,  41,  72,  -1,  -1,  -1,  -1,  -1,  0,  0,  -1,  -1,  -1,  -1,  -1,  -1, 
-1,  -1,  -1,  -1,  46,  40,  -1,  82,  -1,  -1,  -1,  79,  0,  -1,  -1,  -1,  -1,  0,  0,  -1,  -1,  -1,  -1,  -1, 
-1,  -1,  95,  53,  -1,  -1,  -1,  -1,  -1,  14,  18,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  0,  0,  -1,  -1,  -1,  -1, 
-1,  11,  73,  -1,  -1,  -1,  2,  -1,  -1,  47,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  0,  0,  -1,  -1,  -1, 
12,  -1,  -1,  -1,  83,  24,  -1,  43,  -1,  -1,  -1,  51,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  0,  0,  -1,  -1, 
-1,  -1,  -1,  -1,  -1,  94,  -1,  59,  -1,  -1,  70,  72,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  0,  0,  -1, 
-1,  -1,  7,  65,  -1,  -1,  -1,  -1,  39,  49,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  0,  0, 
43,  -1,  -1,  -1,  -1,  66,  -1,  41,  -1,  -1,  -1,  26,  7,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  0 ]

h_halfrate_x = 5
h_halfrate_d = 7

h_matrix_23A = [3,  0,  -1,  -1,  2,  0,  -1,  3,  7,  -1,  1,  1,  -1,  -1,  -1,  -1,  1,  0,  -1,  -1,  -1,  -1,  -1,  -1, 
-1,  -1,  1,  -1,  36,  -1,  -1,  34,  10,  -1,  -1,  18,  2,  -1,  3,  0,  -1,  0,  0,  -1,  -1,  -1,  -1,  -1, 
-1,  -1,  12,  2,  -1,  15,  -1,  40,  -1,  3,  -1,  15,  -1,  2,  13,  -1,  -1,  -1,  0,  0,  -1,  -1,  -1,  -1, 
-1,  -1,  19,  24,  -1,  3,  0,  -1,  6,  -1,  17,  -1,  -1,  -1,  8,  39,  -1,  -1,  -1,  0,  0,  -1,  -1,  -1, 
20,  -1,  6,  -1,  -1,  10,  29,  -1,  -1,  28,  -1,  14,  -1,  38,  -1,  -1,  0,  -1,  -1,  -1,  0,  0,  -1,  -1, 
-1,  -1,  10,  -1,  28,  20,  -1,  -1,  8,  -1,  36,  -1,  9,  -1,  21,  45,  -1,  -1,  -1,  -1,  -1,  0,  0,  -1, 
35,  25,  -1,  37,  -1,  21,  -1,  -1,  5,  -1,  -1,  0,  -1,  4,  20,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  0,  0, 
-1,  6,  6,  -1,  -1,  -1,  4,  -1,  14,  30,  -1,  3,  36,  -1,  14,  -1,  1,  -1,  -1,  -1,  -1,  -1,  -1,  0]

h_23A_x = 4
h_23A_d = 1

h_matrix_23B = [2,  -1,  19,  -1,  47,  -1,  48,  -1,  36,  -1,  82,  -1,  47,  -1,  15,  -1,  95,  0,  -1,  -1,  -1,  -1,  -1,  -1, 
-1,  69,  -1,  88,  -1,  33,  -1,  3,  -1,  16,  -1,  37,  -1,  40,  -1,  48,  -1,  0,  0,  -1,  -1,  -1,  -1,  -1, 
10,  -1,  86,  -1,  62,  -1,  28,  -1,  85,  -1,  16,  -1,  34,  -1,  73,  -1,  -1,  -1,  0,  0,  -1,  -1,  -1,  -1, 
-1,  28,  -1,  32,  -1,  81,  -1,  27,  -1,  88,  -1,  5,  -1,  56,  -1,  37,  -1,  -1,  -1,  0,  0,  -1,  -1,  -1, 
23,  -1,  29,  -1,  15,  -1,  30,  -1,  66,  -1,  24,  -1,  50,  -1,  62,  -1,  -1,  -1,  -1,  -1,  0,  0,  -1,  -1, 
-1,  30,  -1,  65,  -1,  54,  -1,  14,  -1,  0,  -1,  30,  -1,  74,  -1,  0,  -1,  -1,  -1,  -1,  -1,  0,  0,  -1, 
32,  -1,  0,  -1,  15,  -1,  56,  -1,  85,  -1,  5,  -1,  6,  -1,  52,  -1,  0,  -1,  -1,  -1,  -1,  -1,  0,  0, 
-1,  0,  -1,  47,  -1,  13,  -1,  61,  -1,  84,  -1,  55,  -1,  78,  -1,  41,  95,  -1,  -1,  -1,  -1,  -1,  -1,  0]

h_23B_x = 6
h_23B_d = 95

h_matrix_34A = [6,  38,  3,  93,  -1,  -1,  -1,  30,  70,  -1,  86,  -1,  37,  38,  4,  11,  -1,  46,  48,  0,  -1,  -1,  -1,  -1, 
62,  94,  19,  84,  -1,  92,  78,  -1,  15,  -1,  -1,  92,  -1,  45,  24,  32,  30,  -1,  -1,  0,  0,  -1,  -1,  -1, 
71,  -1,  55,  -1,  12,  66,  45,  79,  -1,  78,  -1,  -1,  10,  -1,  22,  55,  70,  82,  -1,  -1,  0,  0,  -1,  -1, 
38,  61,  -1,  66,  9,  73,  47,  64,  -1,  39,  61,  43,  -1,  -1,  -1,  -1,  95,  32,  0,  -1,  -1,  0,  0,  -1, 
-1,  -1,  -1,  -1,  32,  52,  55,  80,  95,  22,  6,  51,  24,  90,  44,  20,  -1,  -1,  -1,  -1,  -1,  -1,  0,  0, 
-1,  63,  31,  88,  20,  -1,  -1,  -1,  6,  40,  56,  16,  71,  53,  -1,  -1,  27,  26,  48,  -1,  -1,  -1,  -1,  0]

h_34A_x = 3
h_34A_d = 48

h_matrix_34B = [-1,  81,  -1,  28,  -1,  -1,  14,  25,  17,  -1,  -1,  85,  29,  52,  78,  95,  22,  92,  0,  0,  -1,  -1,  -1,  -1, 
42,  -1,  14,  68,  32,  -1,  -1,  -1,  -1,  70,  43,  11,  36,  40,  33,  57,  38,  24,  -1,  0,  0,  -1,  -1,  -1, 
-1,  -1,  20,  -1,  -1,  63,  39,  -1,  70,  67,  -1,  38,  4,  72,  47,  29,  60,  5,  80,  -1,  0,  0,  -1,  -1, 
64,  2,  -1,  -1,  63,  -1,  -1,  3,  51,  -1,  81,  15,  94,  9,  85,  36,  14,  19,  -1,  -1,  -1,  0,  0,  -1, 
-1,  53,  60,  80,  -1,  26,  75,  -1,  -1,  -1,  -1,  86,  77,  1,  3,  72,  60,  25,  -1,  -1,  -1,  -1,  0,  0, 
77,  -1,  -1,  -1,  15,  28,  -1,  35,  -1,  72,  30,  68,  85,  84,  26,  64,  11,  89,  0,  -1,  -1,  -1,  -1,  0]

h_34B_x = 2
h_34B_d = 80

# I've run across two different 5/6 code rate matrices
# This one is printed in the 2012 standard
h_matrix_56_2012 = [
1, 25, 55, -1,  47,  4,  -1,  91,  84,  8,  86,  52,  82,  33,  5,  0,  36,  20,  4,  77,  80,  0,  -1,  -1, 
-1, 6, -1, 36,  40,  47,  12,  79,  47,  -1,  41,  21,  12,  71,  14,  72,  0,  44,  49,  0,  0,  0,  0,  -1, 
51, 81, 83, 4,  67,  -1,  21,  -1,  31,  24,  91,  61,  81,  9,  86,  78,  60,  88,  67,  15,  -1,  -1,  0,  0, 
68, -1, 50, 15,  -1,  36,  13,  10,  11,  20,  53,  90,  29,  92,  57,  30,  84,  92,  11,  66,  80,  -1,  -1, 0
]

# This one is used by https://www.uni-kl.de/en/channel-codes/channel-codes-database/wimax-ldpc/
# and http://wvuscholar.wvu.edu/reports/Gerken_Tim.pdf
h_matrix_56 = [
1, 25, 55, -1,  47,  4,  -1,  91,  84,  8,  86,  52,  82,  33,  5,  0,  36,  20,  4,  77,  80,  0,  -1,  -1, 
-1, 6, -1, 36,  40,  47,  12,  79,  47,  -1,  41,  21,  12,  71,  14,  72,  0,  44,  49,  0,  0,  0,  0,  -1, 
51, 81, 83, 4,  67,  -1,  21,  -1,  31,  24,  91,  61,  81,  9,  86,  78,  60,  88,  67,  15,  -1,  -1,  0,  0, 
50, -1, 50, 15,  -1,  36,  13,  10,  11,  20,  53,  90,  29,  92,  57,  30,  84,  92,  11,  66,  80,  -1,  -1, 0
]

h_56_x = 1
h_56_d = 80


# Determine the shift size for the 1/2, 3/4 A&B, 2/3 B, and 5/6 code rates

# val - p(i, j)
# Zf - expansion factor
# Z0 - maximum size of sub-matrix for code length N=2304

def shift_size(val, Zf, Z0 = 96):
    if (val <= 0):
        return val
    else:
        return int(np.floor((val * Zf)/Z0))
    
# determine shift size for the 2/3 A code rate
def shift_size_23A(val, Zf):
    if (val <= 0):
        return val
    else:
        return val % Zf
    
# expand the base H matrix (Hbm)
# Hbm has the dimensions Nb x Mb
# the expanded matrices have the dimensions N = Zf * Nb and M = Zf * Mb

# preshifted - H already holds the shifts for Zf, so use them as they are

def expand_h_matrix(H, Zf, case_23A_rate = False, preshifted = False):
    
    item_count = 0
    row_count = 0
    

    for item in H:
        
        if item == -1:
            sub_matrix = np.zeros((Zf, Zf), dtype=np.int)
        elif item == 0:
            sub_matrix = np.identity(Zf, dtype=np.int)
        else:
            if(preshifted):
                shift = item
            elif(case_23A_rate):
                shift = shift_size_23A(item, Zf)
            else:
                shift = shift_size(item, Zf)
            
            sub_matrix = np.roll(np.identity(Zf, dtype=np.int), shift, axis=1)
        
        
        if item_count == 0:
            row = sub_matrix
        else:
            row = np.concatenate((row, sub_matrix), axis = 1)
            
        item_count += 1
        
        # The base matrix size for 802.16e is 24
        if item_count == 24:
            item_count = 0
            if row_count == 0:
                expanded_matrix = row
                row_count += 1
            else:
                expanded_matrix = np.concatenate((expanded_matrix, row), axis = 0)
    
    return expanded_matrix

# Create an Alist file out of an H matrix

def create_alist_file(matrix, filename, print_to_console = False):
    
    f = open(filename, 'w')
    
    # number of variable nodes
    N = len(matrix[0])
    # number of check nodes
    M = len(matrix)
    
    mlist = []
    row_weights = []
    for row in matrix:
        row_indices = []
        for n in range(len(row)):
            if row[n] == 1:
                row_indices.append(n+1)
        mlist.append(row_indices)  
        row_weights.append(len(row_indices))
        
    nlist = []
    column_weights = []
    for n in range(len(matrix[0])):
        column_indices = []
        for m in range(len(matrix)):
            if matrix[m][n] == 1:
                column_indices.append(m+1)
        nlist.append(column_indices)
        column_weights.append(len(column_indices))
        
    max_col_weight = np.max(column_weights)
    max_row_weight = np.max(row_weights)
    
    if(print_to_console):
        print ("N: %d " % N),
        print ("M: %d" % M)
        print ("Max Col Weight: %d" % max_col_weight)
        print ("Max Row Weight: %d" % max_row_weight)
        
        for n in column_weights:
            print ("%d " % n),
        print('\n'),
            
        for m in row_weights:
            print ("%d " % m),
        print('\n'),
        
        for n in nlist:
            print n
            
        for m in mlist:
            print m
            
    f.write("%d %d\n" %(N, M))
    f.write("%d %d\n" %(max_col_weight, max_row_weight))
        
    for n in column_weights:
            f.write("%d " % n)
    f.write('\n')
    
    for m in row_weights:
        f.write("%d " % m)
    f.write('\n')
    
    for n in nlist:
        for m in range(max_col_weight):
            if(m >= len(n)):
                f.write("%d " % 0)

            else:
                f.write("%d " % n[m])
                
        f.write('\n')
            
    for m in mlist:

        for n in range(max_row_weight):
            if(n >= len(m)):
                f.write("%d " % 0)
            else:
                f.write("%d " % m[n])      

        f.write('\n')
    80
    f.close()


# Create C header and source file for ldpc size and rate
def create_c_matrix_file(matrix, matrix_name, filename, z, header_file, X, D):
        
    f = open(filename + ".cc", 'w')
    
    # number of variable nodes
    N = len(matrix[0])
    # number of check nodes
    M = len(matrix)
    
    mlist = []
    row_weights = []
    for row in matrix:
        row_indices = []
        for n in range(len(row)):
            if row[n] == 1:
                row_indices.append(n)
        mlist.append(row_indices)  
        row_weights.append(len(row_indices))
        
    nlist = []
    column_weights = []
    for n in range(len(matrix[0])):
        column_indices = []
        for m in range(len(matrix)):
            if matrix[m][n] == 1:
                column_indices.append(m)
        nlist.append(column_indices)
        column_weights.append(len(column_indices))
        
    max_col_weight = np.max(column_weights)
    max_row_weight = np.max(row_weights)
    
    f.write("#include \"matrices.h\"\n\n\n")
    f.write("#ifdef Z_%d\n"%z)
    f.write("unsigned int %s_D = %d;\n" %(matrix_name, D))
    f.write("unsigned int %s_X = %d;\n\n" %(matrix_name, X))
    f.write("int16_t %s[%d][%d] = {\n" % (matrix_name, M, max_row_weight))
    
    for m in range(len(mlist)):
        
        f.write("    {")
        
        for n in range(max_row_weight):
            if(n >= len(mlist[m])):
                if (n == len(mlist[m])):
                    f.write("%d" % -1)
                else:
                    f.write("%d, " % -1)
            else:
                if (n == max_row_weight-1):
                    f.write("%d" % mlist[m][n])
                else:
                    f.write("%d, " % mlist[m][n])

        if m == len(mlist)-1:
            f.write("}\n")
        else:
            f.write('},\n')
    
    f.write("};\n")
    f.write("#endif")
    f.close()

    header_file.write("#ifdef Z_%d\n"%z)
    header_file.write("extern unsigned int %s_D;\n" %(matrix_name))
    header_file.write("extern unsigned int %s_X;\n\n" %(matrix_name))
    header_file.write("extern int16_t %s[%d][%d];\n" % (matrix_name, M, max_row_weight))
    header_file.write("#endif\n\n")
    
    
# Expansion factors to generate.  24 to 96 in steps of 4 are the sizes defined
# in the 802.16e standard.  192 (N = 4608) and 384 (N = 9216) are extensions
# beyond the standard.
Z_FACTORS = list(range(24, 100, 4)) + [192, 384]

# Base matrix for each rate, and whether it uses the 2/3 A shift rule
RATE_BASES = {
    "0_5":   (h_matrix_halfrate, False),
    "0_66A": (h_matrix_23A, True),
    "0_66B": (h_matrix_23B, False),
    "0_75A": (h_matrix_34A, False),
    "0_75B": (h_matrix_34B, False),
    "0_83":  (h_matrix_56, False),
}

# Shifts chosen directly for an expansion factor instead of scaled from the
# standard.  Scaling to Z = 192 or 384 multiplies every shift by 2 or 4, which
# splits the code into independent copies of the N = 2304 code.  These keep the standard base
# structure and parity shifts (so X and D follow the usual rules) and choose
# the information part shifts to avoid short cycles.
PRESHIFTED = {
    192: {
        "0_5": [
         -1, 105,  96,  -1,  -1,  -1,  -1,  -1, 151,  75,  -1,  -1,  14,   0,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
         -1, 177,  -1,  -1,  -1,  63,  48,  44,  -1,  -1,  -1,  11,  -1,   0,   0,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
         -1,  -1,  -1, 168, 188,   3,  -1,   1,  -1,  -1,  -1, 174,  -1,  -1,   0,   0,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
         95,  -1, 145,  -1,  -1,  -1,  -1,  -1,  14, 183,  -1,  -1,  -1,  -1,  -1,   0,   0,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
         -1,  -1,  97,  -1,  -1,  -1,  52,  -1,  -1,  46, 175,  -1,  -1,  -1,  -1,  -1,   0,   0,  -1,  -1,  -1,  -1,  -1,  -1,
         -1,  -1,  -1,  -1, 180,  90,  -1,  13,  -1,  -1,  -1,  84,   0,  -1,  -1,  -1,  -1,   0,   0,  -1,  -1,  -1,  -1,  -1,
         -1,  -1, 148,  98,  -1,  -1,  -1,  -1,  -1, 155, 174,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   0,   0,  -1,  -1,  -1,  -1,
         -1,  87, 104,  -1,  -1,  -1, 102,  -1,  -1,  19,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   0,   0,  -1,  -1,  -1,
         75,  -1,  -1,  -1,  19,  32,  -1, 168,  -1,  -1,  -1,  66,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   0,   0,  -1,  -1,
         -1,  -1,  -1,  -1,  -1,  77,  -1, 166,  -1,  -1, 102, 124,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   0,   0,  -1,
         -1,  -1,  30, 104,  -1,  -1,  -1,  -1, 158, 125,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   0,   0,
         23,  -1,  -1,  -1,  -1, 161,  -1, 134,  -1,  -1,  -1, 143,  14,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   0
        ],
        "0_66A": [
         77, 142,  -1,  -1,  55, 120,  -1, 191,  11,  -1,  17, 146,  -1,  -1,  -1,  -1,   1,   0,  -1,  -1,  -1,  -1,  -1,  -1,
         -1,  -1, 169,  -1,  59,  -1,  -1,  87,   4,  -1,  -1,  28,  35,  -1, 158,  28,  -1,   0,   0,  -1,  -1,  -1,  -1,  -1,
         -1,  -1, 150,  16,  -1,  20,  -1,  49,  -1, 126,  -1,  22,  -1,  92,   8,  -1,  -1,  -1,   0,   0,  -1,  -1,  -1,  -1,
         -1,  -1, 138,  30,  -1,  96,  39,  -1, 140,  -1,  56,  -1,  -1,  -1, 161,  55,  -1,  -1,  -1,   0,   0,  -1,  -1,  -1,
         63,  -1, 115,  -1,  -1, 166, 110,  -1,  -1,  39,  -1,   9,  -1, 100,  -1,  -1,   0,  -1,  -1,  -1,   0,   0,  -1,  -1,
         -1,  -1,  53,  -1,  53,  79,  -1,  -1,  35,  -1,  91,  -1,  93,  -1, 131, 146,  -1,  -1,  -1,  -1,  -1,   0,   0,  -1,
        180, 133,  -1,  67,  -1,  74,  -1,  -1,  32,  -1,  -1, 125,  -1,  29,  93,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   0,   0,
         -1,  75, 181,  -1,  -1,  -1,   8,  -1, 142, 175,  -1, 138, 188,  -1, 120,  -1,   1,  -1,  -1,  -1,  -1,  -1,  -1,   0
        ],
        "0_66B": [
         34,  -1, 191,  -1,  89,  -1, 145,  -1,  63,  -1, 109,  -1, 158,  -1, 126,  -1, 190,   0,  -1,  -1,  -1,  -1,  -1,  -1,
         -1,  34,  -1,  32,  -1,  11,  -1,  16,  -1,  85,  -1,  17,  -1, 167,  -1, 121,  -1,   0,   0,  -1,  -1,  -1,  -1,  -1,
        130,  -1, 138,  -1,  26,  -1, 180,  -1,  70,  -1,  18,  -1,  10,  -1, 118,  -1,  -1,  -1,   0,   0,  -1,  -1,  -1,  -1,
         -1,  61,  -1,  77,  -1, 182,  -1, 173,  -1, 127,  -1, 102,  -1, 110,  -1, 167,  -1,  -1,  -1,   0,   0,  -1,  -1,  -1,
        125,  -1,  59,  -1,  97,  -1, 178,  -1,  83,  -1, 152,  -1, 159,  -1, 105,  -1,  -1,  -1,  -1,  -1,   0,   0,  -1,  -1,
         -1, 149,  -1,  18,  -1,  98,  -1, 115,  -1,  37,  -1, 113,  -1,  53,  -1,  56,  -1,  -1,  -1,  -1,  -1,   0,   0,  -1,
        188,  -1, 106,  -1,  25,  -1,  68,  -1, 103,  -1, 148,  -1, 152,  -1, 161,  -1,   0,  -1,  -1,  -1,  -1,  -1,   0,   0,
         -1,   3,  -1,  96,  -1,  33,  -1, 187,  -1, 134,  -1, 137,  -1,  19,  -1,  65, 190,  -1,  -1,  -1,  -1,  -1,  -1,   0
        ],
        "0_75A": [
         75, 152,  71,   3,  -1,  -1,  -1, 132,  72,  -1,  54,  -1, 182, 152, 174, 166,  -1, 165,  96,   0,  -1,  -1,  -1,  -1,
         46, 171, 163, 109,  -1, 182, 137,  -1,  18,  -1,  -1,  90,  -1,  86, 161, 179, 190,  -1,  -1,   0,   0,  -1,  -1,  -1,
         67,  -1,  65,  -1, 141, 130, 125, 161,  -1, 140,  -1,  -1,  95,  -1,  41, 142, 139,  36,  -1,  -1,   0,   0,  -1,  -1,
         84,  29,  -1, 110, 160, 144, 176,  74,  -1,   2,   8, 131,  -1,  -1,  -1,  -1,  31, 136,   0,  -1,  -1,   0,   0,  -1,
         -1,  -1,  -1,  -1, 149, 171, 147, 114, 116, 174,  29, 178, 123,  34, 164, 119,  -1,  -1,  -1,  -1,  -1,  -1,   0,   0,
         -1,  96,  90, 147,  63,  -1,  -1,  -1, 157, 141, 176, 159, 156, 113,  -1,  -1, 113, 104,  96,  -1,  -1,  -1,  -1,   0
        ],
        "0_75B": [
         -1,   0,  -1,  39,  -1,  -1,  11, 142, 161,  -1,  -1,   6, 110, 149,  52,  19, 153, 171,   0,   0,  -1,  -1,  -1,  -1,
        108,  -1,  54,  76,  21,  -1,  -1,  -1,  -1,  72, 111,  22, 134,  82,  29,  39,  64,  87,  -1,   0,   0,  -1,  -1,  -1,
         -1,  -1,  28,  -1,  -1, 156,   3,  -1,  96,  43,  -1,  66, 135, 124,  49,  51,  26,   5, 160,  -1,   0,   0,  -1,  -1,
         94,  45,  -1,  -1,   9,  -1,  -1,  67,  33,  -1, 124,  25, 190, 167, 184,  28,  33,  40,  -1,  -1,  -1,   0,   0,  -1,
         -1, 163,  14,  30,  -1, 176, 182,  -1,  -1,  -1,  -1,  94,  21,  92, 142, 141,  28, 152,  -1,  -1,  -1,  -1,   0,   0,
         90,  -1,  -1,  -1,  40, 183,  -1, 188,  -1,  77,   4, 127,  37,  73,   6,  11, 114,  75,   0,  -1,  -1,  -1,  -1,   0
        ],
        "0_83": [
        167, 136, 181,  -1,  60, 131,  -1,   5,  60, 130, 117,  95,  33,   0, 100,  65,  78,  91, 146, 170, 160,   0,  -1,  -1,
         -1,  82,  -1,  89, 121, 125,  86, 112,  82,  -1, 138,  71,  70, 172,  79, 107,  12, 104, 107, 114,   0,   0,   0,  -1,
         45,  62, 151,  26,  22,  -1,  74,  -1, 146,  84, 140,   0,  84, 145, 138, 148, 146, 157,  46, 127,  -1,  -1,   0,   0,
         90,  -1,  99, 185,  -1, 144, 102,  44, 144, 147, 160,  54,  60,  55,  88, 139, 145,  49,  32,  67, 160,  -1,  -1,   0
        ],
    },
    384: {
        "0_5": [
         -1, 310, 311,  -1,  -1,  -1,  -1,  -1, 205, 226,  -1,  -1,  28,   0,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
         -1,  31,  -1,  -1,  -1,  61, 236, 316,  -1,  -1,  -1,  21,  -1,   0,   0,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
         -1,  -1,  -1, 381, 201, 175,  -1, 240,  -1,  -1,  -1, 237,  -1,  -1,   0,   0,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
         73,  -1, 238,  -1,  -1,  -1,  -1,  -1, 315, 317,  -1,  -1,  -1,  -1,  -1,   0,   0,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
         -1,  -1, 195,  -1,  -1,  -1, 239,  -1,  -1, 200, 336,  -1,  -1,  -1,  -1,  -1,   0,   0,  -1,  -1,  -1,  -1,  -1,  -1,
         -1,  -1,  -1,  -1,   0, 340,  -1, 241,  -1,  -1,  -1, 294,   0,  -1,  -1,  -1,  -1,   0,   0,  -1,  -1,  -1,  -1,  -1,
         -1,  -1, 293,  72,  -1,  -1,  -1,  -1,  -1, 368,  57,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   0,   0,  -1,  -1,  -1,  -1,
         -1, 321, 174,  -1,  -1,  -1, 107,  -1,  -1, 106,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   0,   0,  -1,  -1,  -1,
         50,  -1,  -1,  -1, 109,  86,  -1,  31,  -1,  -1,  -1, 358,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   0,   0,  -1,  -1,
         -1,  -1,  -1,  -1,  -1, 326,  -1, 237,  -1,  -1, 183, 125,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   0,   0,  -1,
         -1,  -1, 108, 240,  -1,  -1,  -1,  -1,  29, 279,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   0,   0,
        257,  -1,  -1,  -1,  -1,  54,  -1, 261,  -1,  -1,  -1, 239,  28,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   0
        ],
        "0_66A": [
        195, 280,  -1,  -1,  90, 145,  -1, 287, 164,  -1, 287,  72,  -1,  -1,  -1,  -1,   1,   0,  -1,  -1,  -1,  -1,  -1,  -1,
         -1,  -1, 246,  -1, 279,  -1,  -1, 310,  46,  -1,  -1,  74, 315,  -1, 244, 123,  -1,   0,   0,  -1,  -1,  -1,  -1,  -1,
         -1,  -1, 281,  80,  -1, 380,  -1, 132,  -1,  53,  -1,  33,  -1, 299, 348,  -1,  -1,  -1,   0,   0,  -1,  -1,  -1,  -1,
         -1,  -1, 267, 127,  -1, 118, 313,  -1, 231,  -1, 121,  -1,  -1,  -1, 178, 379,  -1,  -1,  -1,   0,   0,  -1,  -1,  -1,
        116,  -1,  26,  -1,  -1,  80,  37,  -1,  -1, 272,  -1, 220,  -1, 356,  -1,  -1,   0,  -1,  -1,  -1,   0,   0,  -1,  -1,
         -1,  -1, 186,  -1,  57,  58,  -1,  -1, 120,  -1, 301,  -1,  13,  -1, 282, 278,  -1,  -1,  -1,  -1,  -1,   0,   0,  -1,
        105, 230,  -1, 176,  -1, 380,  -1,  -1,  25,  -1,  -1, 337,  -1, 159, 137,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   0,   0,
         -1, 312, 354,  -1,  -1,  -1, 188,  -1, 251, 267,  -1,  27, 311,  -1, 144,  -1,   1,  -1,  -1,  -1,  -1,  -1,  -1,   0
        ],
        "0_66B": [
        294,  -1, 268,  -1, 260,  -1, 310,  -1, 301,  -1, 159,  -1, 141,  -1, 358,  -1, 380,   0,  -1,  -1,  -1,  -1,  -1,  -1,
         -1, 335,  -1, 137,  -1, 210,  -1, 128,  -1, 102,  -1, 242,  -1, 357,  -1,  28,  -1,   0,   0,  -1,  -1,  -1,  -1,  -1,
        188,  -1,  81,  -1, 270,  -1, 218,  -1,  53,  -1,  83,  -1,  78,  -1, 353,  -1,  -1,  -1,   0,   0,  -1,  -1,  -1,  -1,
         -1, 167,  -1, 190,  -1, 224,  -1, 315,  -1,  82,  -1, 259,  -1, 372,  -1, 160,  -1,  -1,  -1,   0,   0,  -1,  -1,  -1,
        157,  -1, 300,  -1, 189,  -1, 215,  -1, 185,  -1,  84,  -1, 117,  -1, 381,  -1,  -1,  -1,  -1,  -1,   0,   0,  -1,  -1,
         -1,  28,  -1,  44,  -1, 365,  -1, 297,  -1, 366,  -1,  33,  -1, 229,  -1,  84,  -1,  -1,  -1,  -1,  -1,   0,   0,  -1,
        230,  -1, 150,  -1, 374,  -1,  29,  -1, 100,  -1, 325,  -1, 113,  -1, 212,  -1,   0,  -1,  -1,  -1,  -1,  -1,   0,   0,
         -1, 273,  -1, 264,  -1,  20,  -1,  26,  -1, 356,  -1,   0,  -1, 120,  -1,  59, 380,  -1,  -1,  -1,  -1,  -1,  -1,   0
        ],
        "0_75A": [
        261, 140, 157, 223,  -1,  -1,  -1, 225,  39,  -1, 192,  -1,  95, 355, 301,  60,  -1,  43, 192,   0,  -1,  -1,  -1,  -1,
        172, 259, 101,  71,  -1, 234, 253,  -1, 377,  -1,  -1,   0,  -1, 189, 280, 165, 355,  -1,  -1,   0,   0,  -1,  -1,  -1,
        165,  -1, 374,  -1, 365, 236, 349,  10,  -1, 259,  -1,  -1, 173,  -1, 166, 270, 169, 187,  -1,  -1,   0,   0,  -1,  -1,
        275, 114,  -1, 170, 167, 311, 101, 117,  -1, 349, 326, 247,  -1,  -1,  -1,  -1, 213, 158,   0,  -1,  -1,   0,   0,  -1,
         -1,  -1,  -1,  -1,   7, 176, 380, 328, 359,  50, 243, 186, 157, 162, 260, 331,  -1,  -1,  -1,  -1,  -1,  -1,   0,   0,
         -1, 193,  34, 338, 119,  -1,  -1,  -1, 150, 367, 130,  67,  15, 276,  -1,  -1, 287, 383, 192,  -1,  -1,  -1,  -1,   0
        ],
        "0_75B": [
         -1, 279,  -1, 232,  -1,  -1, 282, 354,   2,  -1,  -1, 129,  31, 185, 253, 210,  99, 279,   0,   0,  -1,  -1,  -1,  -1,
          1,  -1, 283,  62, 176,  -1,  -1,  -1,  -1, 274,  19, 350, 263, 203, 340, 212, 215,  44,  -1,   0,   0,  -1,  -1,  -1,
         -1,  -1, 226,  -1,  -1, 252,   2,  -1, 382, 293,  -1, 104,  18, 253, 367, 160,  63, 167, 320,  -1,   0,   0,  -1,  -1,
        130, 120,  -1,  -1,  73,  -1,  -1, 164,  43,  -1, 209, 245, 296,   4,   9, 121, 194, 282,  -1,  -1,  -1,   0,   0,  -1,
         -1,  64, 106,  26,  -1,  32, 324,  -1,  -1,  -1,  -1, 293,  26, 283, 299, 116,  55, 200,  -1,  -1,  -1,  -1,   0,   0,
         54,  -1,  -1,  -1, 358, 207,  -1,  89,  -1,  59,  82,  91, 267, 188, 286, 371, 304, 329,   0,  -1,  -1,  -1,  -1,   0
        ],
        "0_83": [
        275,  79, 251,  -1, 261, 305,  -1, 298, 109, 289,  58,  63, 164, 140, 113,  25, 180, 240,  46,  26, 320,   0,  -1,  -1,
         -1,  46,  -1, 249,  74, 139,  21, 275, 381,  -1, 365, 105, 259, 105, 119,  35, 148, 195,  98, 232,   0,   0,   0,  -1,
        140, 275, 231,  13, 240,  -1, 143,  -1, 148,  46, 239,  58,  83, 360, 145,  83, 250, 135,  86, 233,  -1,  -1,   0,   0,
        115,  -1, 243, 338,  -1, 183,  37,  71, 200, 197, 106, 225,   3, 189, 220,  85,  60, 169, 374, 204, 320,  -1,  -1,   0
        ],
    },
}

def expand_rate(rate, Zf):
    if Zf in PRESHIFTED and rate in PRESHIFTED[Zf]:
        return expand_h_matrix(PRESHIFTED[Zf][rate], Zf, preshifted=True)
    H, case_23A_rate = RATE_BASES[rate]
    return expand_h_matrix(H, Zf, case_23A_rate=case_23A_rate)

# Generate all of the Alists from the WIMAX standard
# Generate C header and source files for all LDPC rates and Z factors
def main():
    
    alist_dir = "../alist/"
    # generate all of the alists
    for i in Z_FACTORS:

        halfrate_filename = alist_dir + ("wimax_%d_0_5.alist" % ((i/96.0)*2304))
        filename_23A = alist_dir + ("wimax_%d_0_66A.alist" % ((i/96.0)*2304))
        filename_23B = alist_dir + ("wimax_%d_0_66B.alist" % ((i/96.0)*2304))
        filename_34A = alist_dir + ("wimax_%d_0_75A.alist" % ((i/96.0)*2304))
        filename_34B = alist_dir + ("wimax_%d_0_75B.alist" % ((i/96.0)*2304))
        filename_56 = alist_dir + ("wimax_%d_0_83.alist" % ((i/96.0)*2304))

        create_alist_file(expand_rate("0_5", i), halfrate_filename)
        create_alist_file(expand_rate("0_66A", i), filename_23A)
        create_alist_file(expand_rate("0_66B", i), filename_23B)
        create_alist_file(expand_rate("0_75A", i), filename_34A)
        create_alist_file(expand_rate("0_75B", i), filename_34B)
        create_alist_file(expand_rate("0_83", i), filename_56)
        
        
    # generate all of the c files

    cfiles_dir = "../lib/matrices/"
    include_dir = "../include/"
    
    header_file = open(include_dir + "matrices.h", 'w')
    
    include_filename = "matrices"
    
    header_file.write("#ifndef %s_H\n" % (include_filename.upper()))
    header_file.write("#define %s_H\n" % (include_filename.upper()))
    header_file.write("\n#include <stdint.h>\n\n")   
    
    for i in Z_FACTORS:
        header_file.write("#define Z_%d\n"%i)
        
    header_file.write("\n")
    
    for i in Z_FACTORS:

        halfrate_matrixname = ("wimax_%d_0_5" % ((i/96.0)*2304))
        matrixname_23A = ("wimax_%d_0_66A" % ((i/96.0)*2304))
        matrixname_23B = ("wimax_%d_0_66B" % ((i/96.0)*2304))
        matrixname_34A = ("wimax_%d_0_75A" % ((i/96.0)*2304))
        matrixname_34B = ("wimax_%d_0_75B" % ((i/96.0)*2304))
        matrixname_56 = ("wimax_%d_0_83" % ((i/96.0)*2304))

        halfrate_filename = cfiles_dir + halfrate_matrixname
        filename_23A = cfiles_dir + matrixname_23A
        filename_23B = cfiles_dir + matrixname_23B
        filename_34A = cfiles_dir + matrixname_34A
        filename_34B = cfiles_dir + matrixname_34B
        filename_56 = cfiles_dir + matrixname_56
        
        shift_halfrate = shift_size(h_halfrate_d, i)
        shift_23A = shift_size_23A(h_23A_d, i)
        shift_23B = shift_size(h_23B_d, i)
        shift_34A = shift_size(h_34A_d, i)
        shift_34B = shift_size(h_34B_d, i)
        shift_56 = shift_size(h_56_d, i)

        create_c_matrix_file(expand_rate("0_5", i), halfrate_matrixname, halfrate_filename, i, header_file, h_halfrate_x, shift_halfrate)
        create_c_matrix_file(expand_rate("0_66A", i), matrixname_23A, filename_23A, i, header_file, h_23A_x, shift_23A)
        create_c_matrix_file(expand_rate("0_66B", i), matrixname_23B, filename_23B, i, header_file, h_23B_x, shift_23B)
        create_c_matrix_file(expand_rate("0_75A", i), matrixname_34A, filename_34A, i, header_file, h_34A_x, shift_34A)
        create_c_matrix_file(expand_rate("0_75B", i), matrixname_34B, filename_34B, i, header_file, h_34B_x, shift_34B)
        create_c_matrix_file(expand_rate("0_83", i), matrixname_56, filename_56, i,
        header_file, h_56_x, shift_56)
        
    header_file.write("#endif // %s_H\n" % (include_filename.upper()))
    header_file.close()

    
if __name__ == '__main__':
    
    print("Generating Alists for all of the LDPC rates and sizes found in the 802.16 standard")
    print("Generating C header and source files containing the check nodes for all LDPC rates and sizes from the 802.16e standard")
    main()

