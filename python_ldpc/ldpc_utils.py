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

h_matrix_23A = [3,  0,  -1,  -1,  2,  0,  -1,  3,  7,  -1,  1,  1,  -1,  -1,  -1,  -1,  1,  0,  -1,  -1,  -1,  -1,  -1,  -1, 
-1,  -1,  1,  -1,  36,  -1,  -1,  34,  10,  -1,  -1,  18,  2,  -1,  3,  0,  -1,  0,  0,  -1,  -1,  -1,  -1,  -1, 
-1,  -1,  12,  2,  -1,  15,  -1,  40,  -1,  3,  -1,  15,  -1,  2,  13,  -1,  -1,  -1,  0,  0,  -1,  -1,  -1,  -1, 
-1,  -1,  19,  24,  -1,  3,  0,  -1,  6,  -1,  17,  -1,  -1,  -1,  8,  39,  -1,  -1,  -1,  0,  0,  -1,  -1,  -1, 
20,  -1,  6,  -1,  -1,  10,  29,  -1,  -1,  28,  -1,  14,  -1,  38,  -1,  -1,  0,  -1,  -1,  -1,  0,  0,  -1,  -1, 
-1,  -1,  10,  -1,  28,  20,  -1,  -1,  8,  -1,  36,  -1,  9,  -1,  21,  45,  -1,  -1,  -1,  -1,  -1,  0,  0,  -1, 
35,  25,  -1,  37,  -1,  21,  -1,  -1,  5,  -1,  -1,  0,  -1,  4,  20,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  0,  0, 
-1,  6,  6,  -1,  -1,  -1,  4,  -1,  14,  30,  -1,  3,  36,  -1,  14,  -1,  1,  -1,  -1,  -1,  -1,  -1,  -1,  0]

h_matrix_23B = [2,  -1,  19,  -1,  47,  -1,  48,  -1,  36,  -1,  82,  -1,  47,  -1,  15,  -1,  95,  0,  -1,  -1,  -1,  -1,  -1,  -1, 
-1,  69,  -1,  88,  -1,  33,  -1,  3,  -1,  16,  -1,  37,  -1,  40,  -1,  48,  -1,  0,  0,  -1,  -1,  -1,  -1,  -1, 
10,  -1,  86,  -1,  62,  -1,  28,  -1,  85,  -1,  16,  -1,  34,  -1,  73,  -1,  -1,  -1,  0,  0,  -1,  -1,  -1,  -1, 
-1,  28,  -1,  32,  -1,  81,  -1,  27,  -1,  88,  -1,  5,  -1,  56,  -1,  37,  -1,  -1,  -1,  0,  0,  -1,  -1,  -1, 
23,  -1,  29,  -1,  15,  -1,  30,  -1,  66,  -1,  24,  -1,  50,  -1,  62,  -1,  -1,  -1,  -1,  -1,  0,  0,  -1,  -1, 
-1,  30,  -1,  65,  -1,  54,  -1,  14,  -1,  0,  -1,  30,  -1,  74,  -1,  0,  -1,  -1,  -1,  -1,  -1,  0,  0,  -1, 
32,  -1,  0,  -1,  15,  -1,  56,  -1,  85,  -1,  5,  -1,  6,  -1,  52,  -1,  0,  -1,  -1,  -1,  -1,  -1,  0,  0, 
-1,  0,  -1,  47,  -1,  13,  -1,  61,  -1,  84,  -1,  55,  -1,  78,  -1,  41,  95,  -1,  -1,  -1,  -1,  -1,  -1,  0]

h_matrix_34A = [6,  38,  3,  93,  -1,  -1,  -1,  30,  70,  -1,  86,  -1,  37,  38,  4,  11,  -1,  46,  48,  0,  -1,  -1,  -1,  -1, 
62,  94,  19,  84,  -1,  92,  78,  -1,  15,  -1,  -1,  92,  -1,  45,  24,  32,  30,  -1,  -1,  0,  0,  -1,  -1,  -1, 
71,  -1,  55,  -1,  12,  66,  45,  79,  -1,  78,  -1,  -1,  10,  -1,  22,  55,  70,  82,  -1,  -1,  0,  0,  -1,  -1, 
38,  61,  -1,  66,  9,  73,  47,  64,  -1,  39,  61,  43,  -1,  -1,  -1,  -1,  95,  32,  0,  -1,  -1,  0,  0,  -1, 
-1,  -1,  -1,  -1,  32,  52,  55,  80,  95,  22,  6,  51,  24,  90,  44,  20,  -1,  -1,  -1,  -1,  -1,  -1,  0,  0, 
-1,  63,  31,  88,  20,  -1,  -1,  -1,  6,  40,  56,  16,  71,  53,  -1,  -1,  27,  26,  48,  -1,  -1,  -1,  -1,  0]

h_matrix_34B = [-1,  81,  -1,  28,  -1,  -1,  14,  25,  17,  -1,  -1,  85,  29,  52,  78,  95,  22,  92,  0,  0,  -1,  -1,  -1,  -1, 
42,  -1,  14,  68,  32,  -1,  -1,  -1,  -1,  70,  43,  11,  36,  40,  33,  57,  38,  24,  -1,  0,  0,  -1,  -1,  -1, 
-1,  -1,  20,  -1,  -1,  63,  39,  -1,  70,  67,  -1,  38,  4,  72,  47,  29,  60,  5,  80,  -1,  0,  0,  -1,  -1, 
64,  2,  -1,  -1,  63,  -1,  -1,  3,  51,  -1,  81,  15,  94,  9,  85,  36,  14,  19,  -1,  -1,  -1,  0,  0,  -1, 
-1,  53,  60,  80,  -1,  26,  75,  -1,  -1,  -1,  -1,  86,  77,  1,  3,  72,  60,  25,  -1,  -1,  -1,  -1,  0,  0, 
77,  -1,  -1,  -1,  15,  28,  -1,  35,  -1,  72,  30,  68,  85,  84,  26,  64,  11,  89,  0,  -1,  -1,  -1,  -1,  0]

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

def expand_h_matrix(H, Zf, case_23A_rate = False):
    
    item_count = 0
    row_count = 0
    

    for item in H:
        
        if item == -1:
            sub_matrix = np.zeros((Zf, Zf), dtype=np.int)
        elif item == 0:
            sub_matrix = np.identity(Zf, dtype=np.int)
        else:
            if(case_23A_rate):
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
    
    f.close()


# Create C header and source file for ldpc size and rate
def create_c_matrix_file(matrix, matrix_name, filename):
        
    f = open(filename + ".cc", 'w')
    header_file = open(filename + ".h", 'w')
    
    include_filename = filename.split('/')
    include_filename = include_filename[len(include_filename)-1]
    
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
    
    f.write("#include \"%s.h\"\n\n\n" % (include_filename))
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
    
    f.write("};")
    f.close()
    
    header_file.write("#ifndef %s_H\n" % (include_filename.upper()))
    
    header_file.write("#define %s_H\n" % (include_filename.upper()))

    header_file.write("\n#include <stdint.h>\n\n\n")
    
    header_file.write("extern int16_t %s[%d][%d];\n\n\n" % (matrix_name, M, max_row_weight))
    
    header_file.write("#endif // %s_H\n" % (include_filename.upper()))
    
    header_file.close()
    
# Generate all of the Alists from the WIMAX standard
# Generate C header and source files for all LDPC rates and Z factors
def main():
    
    alist_dir = "../alist/"
    # generate all of the alists
    for i in range(24, 100, 4):

        halfrate_filename = alist_dir + ("wimax_%d_0_5.alist" % ((i/96.0)*2304))
        filename_23A = alist_dir + ("wimax_%d_0_66A.alist" % ((i/96.0)*2304))
        filename_23B = alist_dir + ("wimax_%d_0_66B.alist" % ((i/96.0)*2304))
        filename_34A = alist_dir + ("wimax_%d_0_75A.alist" % ((i/96.0)*2304))
        filename_34B = alist_dir + ("wimax_%d_0_75B.alist" % ((i/96.0)*2304))
        filename_56 = alist_dir + ("wimax_%d_0_83.alist" % ((i/96.0)*2304))

        create_alist_file(expand_h_matrix(h_matrix_halfrate, i), halfrate_filename)
        create_alist_file(expand_h_matrix(h_matrix_23A, i, case_23A_rate=True), filename_23A)
        create_alist_file(expand_h_matrix(h_matrix_23B, i), filename_23B)
        create_alist_file(expand_h_matrix(h_matrix_34A, i), filename_34A)
        create_alist_file(expand_h_matrix(h_matrix_34B, i), filename_34B)
        create_alist_file(expand_h_matrix(h_matrix_56, i), filename_56)
        
        
    # generate all of the c files

    cfiles_dir = "../lib/matrices/"
    
    for i in range(24, 100, 4):

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

        create_c_matrix_file(expand_h_matrix(h_matrix_halfrate, i), halfrate_matrixname, halfrate_filename)
        create_c_matrix_file(expand_h_matrix(h_matrix_23A, i, case_23A_rate=True), matrixname_23A, filename_23A)
        create_c_matrix_file(expand_h_matrix(h_matrix_23B, i), matrixname_23B, filename_23B)
        create_c_matrix_file(expand_h_matrix(h_matrix_34A, i), matrixname_34A, filename_34A)
        create_c_matrix_file(expand_h_matrix(h_matrix_34B, i), matrixname_34B, filename_34B)
        create_c_matrix_file(expand_h_matrix(h_matrix_56, i), matrixname_56, filename_56)

    
if __name__ == '__main__':
    
    print("Generating Alists for all of the LDPC rates and sizes found in the 802.16 standard")
    print("Generating C header and source files containing the check nodes for all LDPC rates and sizes from the 802.16e standard")
    main()

