#include "matrices.h"


#ifdef Z_52
unsigned int wimax_1248_0_75A_D = 26;
unsigned int wimax_1248_0_75A_X = 3;

int16_t wimax_1248_0_75A[312][15] = {
    {3, 72, 105, 206, 380, 453, 566, 644, 696, 730, 785, 908, 962, 988, -1},
    {4, 73, 106, 207, 381, 454, 567, 645, 697, 731, 786, 909, 963, 989, -1},
    {5, 74, 107, 156, 382, 455, 568, 646, 698, 732, 787, 910, 964, 990, -1},
    {6, 75, 108, 157, 383, 456, 569, 647, 699, 733, 788, 911, 965, 991, -1},
    {7, 76, 109, 158, 384, 457, 570, 648, 700, 734, 789, 912, 966, 992, -1},
    {8, 77, 110, 159, 385, 458, 571, 649, 701, 735, 790, 913, 967, 993, -1},
    {9, 78, 111, 160, 386, 459, 520, 650, 702, 736, 791, 914, 968, 994, -1},
    {10, 79, 112, 161, 387, 460, 521, 651, 703, 737, 792, 915, 969, 995, -1},
    {11, 80, 113, 162, 388, 461, 522, 652, 704, 738, 793, 916, 970, 996, -1},
    {12, 81, 114, 163, 389, 462, 523, 653, 705, 739, 794, 917, 971, 997, -1},
    {13, 82, 115, 164, 390, 463, 524, 654, 706, 740, 795, 918, 972, 998, -1},
    {14, 83, 116, 165, 391, 464, 525, 655, 707, 741, 796, 919, 973, 999, -1},
    {15, 84, 117, 166, 392, 465, 526, 656, 708, 742, 797, 920, 974, 1000, -1},
    {16, 85, 118, 167, 393, 466, 527, 657, 709, 743, 798, 921, 975, 1001, -1},
    {17, 86, 119, 168, 394, 467, 528, 658, 710, 744, 799, 922, 976, 1002, -1},
    {18, 87, 120, 169, 395, 416, 529, 659, 711, 745, 800, 923, 977, 1003, -1},
    {19, 88, 121, 170, 396, 417, 530, 660, 712, 746, 801, 924, 978, 1004, -1},
    {20, 89, 122, 171, 397, 418, 531, 661, 713, 747, 802, 925, 979, 1005, -1},
    {21, 90, 123, 172, 398, 419, 532, 662, 714, 748, 803, 926, 980, 1006, -1},
    {22, 91, 124, 173, 399, 420, 533, 663, 715, 749, 804, 927, 981, 1007, -1},
    {23, 92, 125, 174, 400, 421, 534, 664, 716, 750, 805, 928, 982, 1008, -1},
    {24, 93, 126, 175, 401, 422, 535, 665, 717, 751, 806, 929, 983, 1009, -1},
    {25, 94, 127, 176, 402, 423, 536, 666, 718, 752, 807, 930, 984, 1010, -1},
    {26, 95, 128, 177, 403, 424, 537, 667, 719, 753, 808, 931, 985, 1011, -1},
    {27, 96, 129, 178, 404, 425, 538, 668, 720, 754, 809, 932, 986, 1012, -1},
    {28, 97, 130, 179, 405, 426, 539, 669, 721, 755, 810, 933, 987, 1013, -1},
    {29, 98, 131, 180, 406, 427, 540, 670, 722, 756, 811, 934, 936, 1014, -1},
    {30, 99, 132, 181, 407, 428, 541, 671, 723, 757, 812, 935, 937, 1015, -1},
    {31, 100, 133, 182, 408, 429, 542, 672, 724, 758, 813, 884, 938, 1016, -1},
    {32, 101, 134, 183, 409, 430, 543, 673, 725, 759, 814, 885, 939, 1017, -1},
    {33, 102, 135, 184, 410, 431, 544, 674, 726, 760, 815, 886, 940, 1018, -1},
    {34, 103, 136, 185, 411, 432, 545, 675, 727, 761, 816, 887, 941, 1019, -1},
    {35, 52, 137, 186, 412, 433, 546, 624, 676, 762, 817, 888, 942, 1020, -1},
    {36, 53, 138, 187, 413, 434, 547, 625, 677, 763, 818, 889, 943, 1021, -1},
    {37, 54, 139, 188, 414, 435, 548, 626, 678, 764, 819, 890, 944, 1022, -1},
    {38, 55, 140, 189, 415, 436, 549, 627, 679, 765, 820, 891, 945, 1023, -1},
    {39, 56, 141, 190, 364, 437, 550, 628, 680, 766, 821, 892, 946, 1024, -1},
    {40, 57, 142, 191, 365, 438, 551, 629, 681, 767, 822, 893, 947, 1025, -1},
    {41, 58, 143, 192, 366, 439, 552, 630, 682, 768, 823, 894, 948, 1026, -1},
    {42, 59, 144, 193, 367, 440, 553, 631, 683, 769, 824, 895, 949, 1027, -1},
    {43, 60, 145, 194, 368, 441, 554, 632, 684, 770, 825, 896, 950, 1028, -1},
    {44, 61, 146, 195, 369, 442, 555, 633, 685, 771, 826, 897, 951, 1029, -1},
    {45, 62, 147, 196, 370, 443, 556, 634, 686, 772, 827, 898, 952, 1030, -1},
    {46, 63, 148, 197, 371, 444, 557, 635, 687, 773, 828, 899, 953, 1031, -1},
    {47, 64, 149, 198, 372, 445, 558, 636, 688, 774, 829, 900, 954, 1032, -1},
    {48, 65, 150, 199, 373, 446, 559, 637, 689, 775, 830, 901, 955, 1033, -1},
    {49, 66, 151, 200, 374, 447, 560, 638, 690, 776, 831, 902, 956, 1034, -1},
    {50, 67, 152, 201, 375, 448, 561, 639, 691, 777, 780, 903, 957, 1035, -1},
    {51, 68, 153, 202, 376, 449, 562, 640, 692, 778, 781, 904, 958, 1036, -1},
    {0, 69, 154, 203, 377, 450, 563, 641, 693, 779, 782, 905, 959, 1037, -1},
    {1, 70, 155, 204, 378, 451, 564, 642, 694, 728, 783, 906, 960, 1038, -1},
    {2, 71, 104, 205, 379, 452, 565, 643, 695, 729, 784, 907, 961, 1039, -1},
    {33, 102, 114, 201, 309, 354, 424, 621, 700, 741, 797, 848, 988, 1040, -1},
    {34, 103, 115, 202, 310, 355, 425, 622, 701, 742, 798, 849, 989, 1041, -1},
    {35, 52, 116, 203, 311, 356, 426, 623, 702, 743, 799, 850, 990, 1042, -1},
    {36, 53, 117, 204, 260, 357, 427, 572, 703, 744, 800, 851, 991, 1043, -1},
    {37, 54, 118, 205, 261, 358, 428, 573, 704, 745, 801, 852, 992, 1044, -1},
    {38, 55, 119, 206, 262, 359, 429, 574, 705, 746, 802, 853, 993, 1045, -1},
    {39, 56, 120, 207, 263, 360, 430, 575, 706, 747, 803, 854, 994, 1046, -1},
    {40, 57, 121, 156, 264, 361, 431, 576, 707, 748, 804, 855, 995, 1047, -1},
    {41, 58, 122, 157, 265, 362, 432, 577, 708, 749, 805, 856, 996, 1048, -1},
    {42, 59, 123, 158, 266, 363, 433, 578, 709, 750, 806, 857, 997, 1049, -1},
    {43, 60, 124, 159, 267, 312, 434, 579, 710, 751, 807, 858, 998, 1050, -1},
    {44, 61, 125, 160, 268, 313, 435, 580, 711, 752, 808, 859, 999, 1051, -1},
    {45, 62, 126, 161, 269, 314, 436, 581, 712, 753, 809, 860, 1000, 1052, -1},
    {46, 63, 127, 162, 270, 315, 437, 582, 713, 754, 810, 861, 1001, 1053, -1},
    {47, 64, 128, 163, 271, 316, 438, 583, 714, 755, 811, 862, 1002, 1054, -1},
    {48, 65, 129, 164, 272, 317, 439, 584, 715, 756, 812, 863, 1003, 1055, -1},
    {49, 66, 130, 165, 273, 318, 440, 585, 716, 757, 813, 864, 1004, 1056, -1},
    {50, 67, 131, 166, 274, 319, 441, 586, 717, 758, 814, 865, 1005, 1057, -1},
    {51, 68, 132, 167, 275, 320, 442, 587, 718, 759, 815, 866, 1006, 1058, -1},
    {0, 69, 133, 168, 276, 321, 443, 588, 719, 760, 816, 867, 1007, 1059, -1},
    {1, 70, 134, 169, 277, 322, 444, 589, 720, 761, 817, 868, 1008, 1060, -1},
    {2, 71, 135, 170, 278, 323, 445, 590, 721, 762, 818, 869, 1009, 1061, -1},
    {3, 72, 136, 171, 279, 324, 446, 591, 722, 763, 819, 870, 1010, 1062, -1},
    {4, 73, 137, 172, 280, 325, 447, 592, 723, 764, 820, 871, 1011, 1063, -1},
    {5, 74, 138, 173, 281, 326, 448, 593, 724, 765, 821, 872, 1012, 1064, -1},
    {6, 75, 139, 174, 282, 327, 449, 594, 725, 766, 822, 873, 1013, 1065, -1},
    {7, 76, 140, 175, 283, 328, 450, 595, 726, 767, 823, 874, 1014, 1066, -1},
    {8, 77, 141, 176, 284, 329, 451, 596, 727, 768, 824, 875, 1015, 1067, -1},
    {9, 78, 142, 177, 285, 330, 452, 597, 676, 769, 825, 876, 1016, 1068, -1},
    {10, 79, 143, 178, 286, 331, 453, 598, 677, 770, 826, 877, 1017, 1069, -1},
    {11, 80, 144, 179, 287, 332, 454, 599, 678, 771, 827, 878, 1018, 1070, -1},
    {12, 81, 145, 180, 288, 333, 455, 600, 679, 772, 828, 879, 1019, 1071, -1},
    {13, 82, 146, 181, 289, 334, 456, 601, 680, 773, 829, 880, 1020, 1072, -1},
    {14, 83, 147, 182, 290, 335, 457, 602, 681, 774, 830, 881, 1021, 1073, -1},
    {15, 84, 148, 183, 291, 336, 458, 603, 682, 775, 831, 882, 1022, 1074, -1},
    {16, 85, 149, 184, 292, 337, 459, 604, 683, 776, 780, 883, 1023, 1075, -1},
    {17, 86, 150, 185, 293, 338, 460, 605, 684, 777, 781, 832, 1024, 1076, -1},
    {18, 87, 151, 186, 294, 339, 461, 606, 685, 778, 782, 833, 1025, 1077, -1},
    {19, 88, 152, 187, 295, 340, 462, 607, 686, 779, 783, 834, 1026, 1078, -1},
    {20, 89, 153, 188, 296, 341, 463, 608, 687, 728, 784, 835, 1027, 1079, -1},
    {21, 90, 154, 189, 297, 342, 464, 609, 688, 729, 785, 836, 1028, 1080, -1},
    {22, 91, 155, 190, 298, 343, 465, 610, 689, 730, 786, 837, 1029, 1081, -1},
    {23, 92, 104, 191, 299, 344, 466, 611, 690, 731, 787, 838, 1030, 1082, -1},
    {24, 93, 105, 192, 300, 345, 467, 612, 691, 732, 788, 839, 1031, 1083, -1},
    {25, 94, 106, 193, 301, 346, 416, 613, 692, 733, 789, 840, 1032, 1084, -1},
    {26, 95, 107, 194, 302, 347, 417, 614, 693, 734, 790, 841, 1033, 1085, -1},
    {27, 96, 108, 195, 303, 348, 418, 615, 694, 735, 791, 842, 1034, 1086, -1},
    {28, 97, 109, 196, 304, 349, 419, 616, 695, 736, 792, 843, 1035, 1087, -1},
    {29, 98, 110, 197, 305, 350, 420, 617, 696, 737, 793, 844, 1036, 1088, -1},
    {30, 99, 111, 198, 306, 351, 421, 618, 697, 738, 794, 845, 1037, 1089, -1},
    {31, 100, 112, 199, 307, 352, 422, 619, 698, 739, 795, 846, 1038, 1090, -1},
    {32, 101, 113, 200, 308, 353, 423, 620, 699, 740, 796, 847, 1039, 1091, -1},
    {38, 133, 214, 295, 336, 406, 510, 629, 739, 809, 869, 928, 1040, 1092, -1},
    {39, 134, 215, 296, 337, 407, 511, 630, 740, 810, 870, 929, 1041, 1093, -1},
    {40, 135, 216, 297, 338, 408, 512, 631, 741, 811, 871, 930, 1042, 1094, -1},
    {41, 136, 217, 298, 339, 409, 513, 632, 742, 812, 872, 931, 1043, 1095, -1},
    {42, 137, 218, 299, 340, 410, 514, 633, 743, 813, 873, 932, 1044, 1096, -1},
    {43, 138, 219, 300, 341, 411, 515, 634, 744, 814, 874, 933, 1045, 1097, -1},
    {44, 139, 220, 301, 342, 412, 516, 635, 745, 815, 875, 934, 1046, 1098, -1},
    {45, 140, 221, 302, 343, 413, 517, 636, 746, 816, 876, 935, 1047, 1099, -1},
    {46, 141, 222, 303, 344, 414, 518, 637, 747, 817, 877, 884, 1048, 1100, -1},
    {47, 142, 223, 304, 345, 415, 519, 638, 748, 818, 878, 885, 1049, 1101, -1},
    {48, 143, 224, 305, 346, 364, 468, 639, 749, 819, 879, 886, 1050, 1102, -1},
    {49, 144, 225, 306, 347, 365, 469, 640, 750, 820, 880, 887, 1051, 1103, -1},
    {50, 145, 226, 307, 348, 366, 470, 641, 751, 821, 881, 888, 1052, 1104, -1},
    {51, 146, 227, 308, 349, 367, 471, 642, 752, 822, 882, 889, 1053, 1105, -1},
    {0, 147, 228, 309, 350, 368, 472, 643, 753, 823, 883, 890, 1054, 1106, -1},
    {1, 148, 229, 310, 351, 369, 473, 644, 754, 824, 832, 891, 1055, 1107, -1},
    {2, 149, 230, 311, 352, 370, 474, 645, 755, 825, 833, 892, 1056, 1108, -1},
    {3, 150, 231, 260, 353, 371, 475, 646, 756, 826, 834, 893, 1057, 1109, -1},
    {4, 151, 232, 261, 354, 372, 476, 647, 757, 827, 835, 894, 1058, 1110, -1},
    {5, 152, 233, 262, 355, 373, 477, 648, 758, 828, 836, 895, 1059, 1111, -1},
    {6, 153, 234, 263, 356, 374, 478, 649, 759, 829, 837, 896, 1060, 1112, -1},
    {7, 154, 235, 264, 357, 375, 479, 650, 760, 830, 838, 897, 1061, 1113, -1},
    {8, 155, 236, 265, 358, 376, 480, 651, 761, 831, 839, 898, 1062, 1114, -1},
    {9, 104, 237, 266, 359, 377, 481, 652, 762, 780, 840, 899, 1063, 1115, -1},
    {10, 105, 238, 267, 360, 378, 482, 653, 763, 781, 841, 900, 1064, 1116, -1},
    {11, 106, 239, 268, 361, 379, 483, 654, 764, 782, 842, 901, 1065, 1117, -1},
    {12, 107, 240, 269, 362, 380, 484, 655, 765, 783, 843, 902, 1066, 1118, -1},
    {13, 108, 241, 270, 363, 381, 485, 656, 766, 784, 844, 903, 1067, 1119, -1},
    {14, 109, 242, 271, 312, 382, 486, 657, 767, 785, 845, 904, 1068, 1120, -1},
    {15, 110, 243, 272, 313, 383, 487, 658, 768, 786, 846, 905, 1069, 1121, -1},
    {16, 111, 244, 273, 314, 384, 488, 659, 769, 787, 847, 906, 1070, 1122, -1},
    {17, 112, 245, 274, 315, 385, 489, 660, 770, 788, 848, 907, 1071, 1123, -1},
    {18, 113, 246, 275, 316, 386, 490, 661, 771, 789, 849, 908, 1072, 1124, -1},
    {19, 114, 247, 276, 317, 387, 491, 662, 772, 790, 850, 909, 1073, 1125, -1},
    {20, 115, 248, 277, 318, 388, 492, 663, 773, 791, 851, 910, 1074, 1126, -1},
    {21, 116, 249, 278, 319, 389, 493, 664, 774, 792, 852, 911, 1075, 1127, -1},
    {22, 117, 250, 279, 320, 390, 494, 665, 775, 793, 853, 912, 1076, 1128, -1},
    {23, 118, 251, 280, 321, 391, 495, 666, 776, 794, 854, 913, 1077, 1129, -1},
    {24, 119, 252, 281, 322, 392, 496, 667, 777, 795, 855, 914, 1078, 1130, -1},
    {25, 120, 253, 282, 323, 393, 497, 668, 778, 796, 856, 915, 1079, 1131, -1},
    {26, 121, 254, 283, 324, 394, 498, 669, 779, 797, 857, 916, 1080, 1132, -1},
    {27, 122, 255, 284, 325, 395, 499, 670, 728, 798, 858, 917, 1081, 1133, -1},
    {28, 123, 256, 285, 326, 396, 500, 671, 729, 799, 859, 918, 1082, 1134, -1},
    {29, 124, 257, 286, 327, 397, 501, 672, 730, 800, 860, 919, 1083, 1135, -1},
    {30, 125, 258, 287, 328, 398, 502, 673, 731, 801, 861, 920, 1084, 1136, -1},
    {31, 126, 259, 288, 329, 399, 503, 674, 732, 802, 862, 921, 1085, 1137, -1},
    {32, 127, 208, 289, 330, 400, 504, 675, 733, 803, 863, 922, 1086, 1138, -1},
    {33, 128, 209, 290, 331, 401, 505, 624, 734, 804, 864, 923, 1087, 1139, -1},
    {34, 129, 210, 291, 332, 402, 506, 625, 735, 805, 865, 924, 1088, 1140, -1},
    {35, 130, 211, 292, 333, 403, 507, 626, 736, 806, 866, 925, 1089, 1141, -1},
    {36, 131, 212, 293, 334, 404, 508, 627, 737, 807, 867, 926, 1090, 1142, -1},
    {37, 132, 213, 294, 335, 405, 509, 628, 738, 808, 868, 927, 1091, 1143, -1},
    {20, 85, 191, 212, 299, 337, 398, 489, 553, 595, 883, 901, 936, 1092, 1144},
    {21, 86, 192, 213, 300, 338, 399, 490, 554, 596, 832, 902, 937, 1093, 1145},
    {22, 87, 193, 214, 301, 339, 400, 491, 555, 597, 833, 903, 938, 1094, 1146},
    {23, 88, 194, 215, 302, 340, 401, 492, 556, 598, 834, 904, 939, 1095, 1147},
    {24, 89, 195, 216, 303, 341, 402, 493, 557, 599, 835, 905, 940, 1096, 1148},
    {25, 90, 196, 217, 304, 342, 403, 494, 558, 600, 836, 906, 941, 1097, 1149},
    {26, 91, 197, 218, 305, 343, 404, 495, 559, 601, 837, 907, 942, 1098, 1150},
    {27, 92, 198, 219, 306, 344, 405, 496, 560, 602, 838, 908, 943, 1099, 1151},
    {28, 93, 199, 220, 307, 345, 406, 497, 561, 603, 839, 909, 944, 1100, 1152},
    {29, 94, 200, 221, 308, 346, 407, 498, 562, 604, 840, 910, 945, 1101, 1153},
    {30, 95, 201, 222, 309, 347, 408, 499, 563, 605, 841, 911, 946, 1102, 1154},
    {31, 96, 202, 223, 310, 348, 409, 500, 564, 606, 842, 912, 947, 1103, 1155},
    {32, 97, 203, 224, 311, 349, 410, 501, 565, 607, 843, 913, 948, 1104, 1156},
    {33, 98, 204, 225, 260, 350, 411, 502, 566, 608, 844, 914, 949, 1105, 1157},
    {34, 99, 205, 226, 261, 351, 412, 503, 567, 609, 845, 915, 950, 1106, 1158},
    {35, 100, 206, 227, 262, 352, 413, 504, 568, 610, 846, 916, 951, 1107, 1159},
    {36, 101, 207, 228, 263, 353, 414, 505, 569, 611, 847, 917, 952, 1108, 1160},
    {37, 102, 156, 229, 264, 354, 415, 506, 570, 612, 848, 918, 953, 1109, 1161},
    {38, 103, 157, 230, 265, 355, 364, 507, 571, 613, 849, 919, 954, 1110, 1162},
    {39, 52, 158, 231, 266, 356, 365, 508, 520, 614, 850, 920, 955, 1111, 1163},
    {40, 53, 159, 232, 267, 357, 366, 509, 521, 615, 851, 921, 956, 1112, 1164},
    {41, 54, 160, 233, 268, 358, 367, 510, 522, 616, 852, 922, 957, 1113, 1165},
    {42, 55, 161, 234, 269, 359, 368, 511, 523, 617, 853, 923, 958, 1114, 1166},
    {43, 56, 162, 235, 270, 360, 369, 512, 524, 618, 854, 924, 959, 1115, 1167},
    {44, 57, 163, 236, 271, 361, 370, 513, 525, 619, 855, 925, 960, 1116, 1168},
    {45, 58, 164, 237, 272, 362, 371, 514, 526, 620, 856, 926, 961, 1117, 1169},
    {46, 59, 165, 238, 273, 363, 372, 515, 527, 621, 857, 927, 962, 1118, 1170},
    {47, 60, 166, 239, 274, 312, 373, 516, 528, 622, 858, 928, 963, 1119, 1171},
    {48, 61, 167, 240, 275, 313, 374, 517, 529, 623, 859, 929, 964, 1120, 1172},
    {49, 62, 168, 241, 276, 314, 375, 518, 530, 572, 860, 930, 965, 1121, 1173},
    {50, 63, 169, 242, 277, 315, 376, 519, 531, 573, 861, 931, 966, 1122, 1174},
    {51, 64, 170, 243, 278, 316, 377, 468, 532, 574, 862, 932, 967, 1123, 1175},
    {0, 65, 171, 244, 279, 317, 378, 469, 533, 575, 863, 933, 968, 1124, 1176},
    {1, 66, 172, 245, 280, 318, 379, 470, 534, 576, 864, 934, 969, 1125, 1177},
    {2, 67, 173, 246, 281, 319, 380, 471, 535, 577, 865, 935, 970, 1126, 1178},
    {3, 68, 174, 247, 282, 320, 381, 472, 536, 578, 866, 884, 971, 1127, 1179},
    {4, 69, 175, 248, 283, 321, 382, 473, 537, 579, 867, 885, 972, 1128, 1180},
    {5, 70, 176, 249, 284, 322, 383, 474, 538, 580, 868, 886, 973, 1129, 1181},
    {6, 71, 177, 250, 285, 323, 384, 475, 539, 581, 869, 887, 974, 1130, 1182},
    {7, 72, 178, 251, 286, 324, 385, 476, 540, 582, 870, 888, 975, 1131, 1183},
    {8, 73, 179, 252, 287, 325, 386, 477, 541, 583, 871, 889, 976, 1132, 1184},
    {9, 74, 180, 253, 288, 326, 387, 478, 542, 584, 872, 890, 977, 1133, 1185},
    {10, 75, 181, 254, 289, 327, 388, 479, 543, 585, 873, 891, 978, 1134, 1186},
    {11, 76, 182, 255, 290, 328, 389, 480, 544, 586, 874, 892, 979, 1135, 1187},
    {12, 77, 183, 256, 291, 329, 390, 481, 545, 587, 875, 893, 980, 1136, 1188},
    {13, 78, 184, 257, 292, 330, 391, 482, 546, 588, 876, 894, 981, 1137, 1189},
    {14, 79, 185, 258, 293, 331, 392, 483, 547, 589, 877, 895, 982, 1138, 1190},
    {15, 80, 186, 259, 294, 332, 393, 484, 548, 590, 878, 896, 983, 1139, 1191},
    {16, 81, 187, 208, 295, 333, 394, 485, 549, 591, 879, 897, 984, 1140, 1192},
    {17, 82, 188, 209, 296, 334, 395, 486, 550, 592, 880, 898, 985, 1141, 1193},
    {18, 83, 189, 210, 297, 335, 396, 487, 551, 593, 881, 899, 986, 1142, 1194},
    {19, 84, 190, 211, 298, 336, 397, 488, 552, 594, 882, 900, 987, 1143, 1195},
    {225, 288, 341, 407, 467, 479, 523, 599, 637, 724, 751, 790, 1144, 1196, -1},
    {226, 289, 342, 408, 416, 480, 524, 600, 638, 725, 752, 791, 1145, 1197, -1},
    {227, 290, 343, 409, 417, 481, 525, 601, 639, 726, 753, 792, 1146, 1198, -1},
    {228, 291, 344, 410, 418, 482, 526, 602, 640, 727, 754, 793, 1147, 1199, -1},
    {229, 292, 345, 411, 419, 483, 527, 603, 641, 676, 755, 794, 1148, 1200, -1},
    {230, 293, 346, 412, 420, 484, 528, 604, 642, 677, 756, 795, 1149, 1201, -1},
    {231, 294, 347, 413, 421, 485, 529, 605, 643, 678, 757, 796, 1150, 1202, -1},
    {232, 295, 348, 414, 422, 486, 530, 606, 644, 679, 758, 797, 1151, 1203, -1},
    {233, 296, 349, 415, 423, 487, 531, 607, 645, 680, 759, 798, 1152, 1204, -1},
    {234, 297, 350, 364, 424, 488, 532, 608, 646, 681, 760, 799, 1153, 1205, -1},
    {235, 298, 351, 365, 425, 489, 533, 609, 647, 682, 761, 800, 1154, 1206, -1},
    {236, 299, 352, 366, 426, 490, 534, 610, 648, 683, 762, 801, 1155, 1207, -1},
    {237, 300, 353, 367, 427, 491, 535, 611, 649, 684, 763, 802, 1156, 1208, -1},
    {238, 301, 354, 368, 428, 492, 536, 612, 650, 685, 764, 803, 1157, 1209, -1},
    {239, 302, 355, 369, 429, 493, 537, 613, 651, 686, 765, 804, 1158, 1210, -1},
    {240, 303, 356, 370, 430, 494, 538, 614, 652, 687, 766, 805, 1159, 1211, -1},
    {241, 304, 357, 371, 431, 495, 539, 615, 653, 688, 767, 806, 1160, 1212, -1},
    {242, 305, 358, 372, 432, 496, 540, 616, 654, 689, 768, 807, 1161, 1213, -1},
    {243, 306, 359, 373, 433, 497, 541, 617, 655, 690, 769, 808, 1162, 1214, -1},
    {244, 307, 360, 374, 434, 498, 542, 618, 656, 691, 770, 809, 1163, 1215, -1},
    {245, 308, 361, 375, 435, 499, 543, 619, 657, 692, 771, 810, 1164, 1216, -1},
    {246, 309, 362, 376, 436, 500, 544, 620, 658, 693, 772, 811, 1165, 1217, -1},
    {247, 310, 363, 377, 437, 501, 545, 621, 659, 694, 773, 812, 1166, 1218, -1},
    {248, 311, 312, 378, 438, 502, 546, 622, 660, 695, 774, 813, 1167, 1219, -1},
    {249, 260, 313, 379, 439, 503, 547, 623, 661, 696, 775, 814, 1168, 1220, -1},
    {250, 261, 314, 380, 440, 504, 548, 572, 662, 697, 776, 815, 1169, 1221, -1},
    {251, 262, 315, 381, 441, 505, 549, 573, 663, 698, 777, 816, 1170, 1222, -1},
    {252, 263, 316, 382, 442, 506, 550, 574, 664, 699, 778, 817, 1171, 1223, -1},
    {253, 264, 317, 383, 443, 507, 551, 575, 665, 700, 779, 818, 1172, 1224, -1},
    {254, 265, 318, 384, 444, 508, 552, 576, 666, 701, 728, 819, 1173, 1225, -1},
    {255, 266, 319, 385, 445, 509, 553, 577, 667, 702, 729, 820, 1174, 1226, -1},
    {256, 267, 320, 386, 446, 510, 554, 578, 668, 703, 730, 821, 1175, 1227, -1},
    {257, 268, 321, 387, 447, 511, 555, 579, 669, 704, 731, 822, 1176, 1228, -1},
    {258, 269, 322, 388, 448, 512, 556, 580, 670, 705, 732, 823, 1177, 1229, -1},
    {259, 270, 323, 389, 449, 513, 557, 581, 671, 706, 733, 824, 1178, 1230, -1},
    {208, 271, 324, 390, 450, 514, 558, 582, 672, 707, 734, 825, 1179, 1231, -1},
    {209, 272, 325, 391, 451, 515, 559, 583, 673, 708, 735, 826, 1180, 1232, -1},
    {210, 273, 326, 392, 452, 516, 560, 584, 674, 709, 736, 827, 1181, 1233, -1},
    {211, 274, 327, 393, 453, 517, 561, 585, 675, 710, 737, 828, 1182, 1234, -1},
    {212, 275, 328, 394, 454, 518, 562, 586, 624, 711, 738, 829, 1183, 1235, -1},
    {213, 276, 329, 395, 455, 519, 563, 587, 625, 712, 739, 830, 1184, 1236, -1},
    {214, 277, 330, 396, 456, 468, 564, 588, 626, 713, 740, 831, 1185, 1237, -1},
    {215, 278, 331, 397, 457, 469, 565, 589, 627, 714, 741, 780, 1186, 1238, -1},
    {216, 279, 332, 398, 458, 470, 566, 590, 628, 715, 742, 781, 1187, 1239, -1},
    {217, 280, 333, 399, 459, 471, 567, 591, 629, 716, 743, 782, 1188, 1240, -1},
    {218, 281, 334, 400, 460, 472, 568, 592, 630, 717, 744, 783, 1189, 1241, -1},
    {219, 282, 335, 401, 461, 473, 569, 593, 631, 718, 745, 784, 1190, 1242, -1},
    {220, 283, 336, 402, 462, 474, 570, 594, 632, 719, 746, 785, 1191, 1243, -1},
    {221, 284, 337, 403, 463, 475, 571, 595, 633, 720, 747, 786, 1192, 1244, -1},
    {222, 285, 338, 404, 464, 476, 520, 596, 634, 721, 748, 787, 1193, 1245, -1},
    {223, 286, 339, 405, 465, 477, 521, 597, 635, 722, 749, 788, 1194, 1246, -1},
    {224, 287, 340, 406, 466, 478, 522, 598, 636, 723, 750, 789, 1195, 1247, -1},
    {86, 120, 203, 218, 419, 489, 550, 580, 662, 704, 846, 898, 962, 1196, -1},
    {87, 121, 204, 219, 420, 490, 551, 581, 663, 705, 847, 899, 963, 1197, -1},
    {88, 122, 205, 220, 421, 491, 552, 582, 664, 706, 848, 900, 964, 1198, -1},
    {89, 123, 206, 221, 422, 492, 553, 583, 665, 707, 849, 901, 965, 1199, -1},
    {90, 124, 207, 222, 423, 493, 554, 584, 666, 708, 850, 902, 966, 1200, -1},
    {91, 125, 156, 223, 424, 494, 555, 585, 667, 709, 851, 903, 967, 1201, -1},
    {92, 126, 157, 224, 425, 495, 556, 586, 668, 710, 852, 904, 968, 1202, -1},
    {93, 127, 158, 225, 426, 496, 557, 587, 669, 711, 853, 905, 969, 1203, -1},
    {94, 128, 159, 226, 427, 497, 558, 588, 670, 712, 854, 906, 970, 1204, -1},
    {95, 129, 160, 227, 428, 498, 559, 589, 671, 713, 855, 907, 971, 1205, -1},
    {96, 130, 161, 228, 429, 499, 560, 590, 672, 714, 856, 908, 972, 1206, -1},
    {97, 131, 162, 229, 430, 500, 561, 591, 673, 715, 857, 909, 973, 1207, -1},
    {98, 132, 163, 230, 431, 501, 562, 592, 674, 716, 858, 910, 974, 1208, -1},
    {99, 133, 164, 231, 432, 502, 563, 593, 675, 717, 859, 911, 975, 1209, -1},
    {100, 134, 165, 232, 433, 503, 564, 594, 624, 718, 860, 912, 976, 1210, -1},
    {101, 135, 166, 233, 434, 504, 565, 595, 625, 719, 861, 913, 977, 1211, -1},
    {102, 136, 167, 234, 435, 505, 566, 596, 626, 720, 862, 914, 978, 1212, -1},
    {103, 137, 168, 235, 436, 506, 567, 597, 627, 721, 863, 915, 979, 1213, -1},
    {52, 138, 169, 236, 437, 507, 568, 598, 628, 722, 864, 916, 980, 1214, -1},
    {53, 139, 170, 237, 438, 508, 569, 599, 629, 723, 865, 917, 981, 1215, -1},
    {54, 140, 171, 238, 439, 509, 570, 600, 630, 724, 866, 918, 982, 1216, -1},
    {55, 141, 172, 239, 440, 510, 571, 601, 631, 725, 867, 919, 983, 1217, -1},
    {56, 142, 173, 240, 441, 511, 520, 602, 632, 726, 868, 920, 984, 1218, -1},
    {57, 143, 174, 241, 442, 512, 521, 603, 633, 727, 869, 921, 985, 1219, -1},
    {58, 144, 175, 242, 443, 513, 522, 604, 634, 676, 870, 922, 986, 1220, -1},
    {59, 145, 176, 243, 444, 514, 523, 605, 635, 677, 871, 923, 987, 1221, -1},
    {60, 146, 177, 244, 445, 515, 524, 606, 636, 678, 872, 924, 936, 1222, -1},
    {61, 147, 178, 245, 446, 516, 525, 607, 637, 679, 873, 925, 937, 1223, -1},
    {62, 148, 179, 246, 447, 517, 526, 608, 638, 680, 874, 926, 938, 1224, -1},
    {63, 149, 180, 247, 448, 518, 527, 609, 639, 681, 875, 927, 939, 1225, -1},
    {64, 150, 181, 248, 449, 519, 528, 610, 640, 682, 876, 928, 940, 1226, -1},
    {65, 151, 182, 249, 450, 468, 529, 611, 641, 683, 877, 929, 941, 1227, -1},
    {66, 152, 183, 250, 451, 469, 530, 612, 642, 684, 878, 930, 942, 1228, -1},
    {67, 153, 184, 251, 452, 470, 531, 613, 643, 685, 879, 931, 943, 1229, -1},
    {68, 154, 185, 252, 453, 471, 532, 614, 644, 686, 880, 932, 944, 1230, -1},
    {69, 155, 186, 253, 454, 472, 533, 615, 645, 687, 881, 933, 945, 1231, -1},
    {70, 104, 187, 254, 455, 473, 534, 616, 646, 688, 882, 934, 946, 1232, -1},
    {71, 105, 188, 255, 456, 474, 535, 617, 647, 689, 883, 935, 947, 1233, -1},
    {72, 106, 189, 256, 457, 475, 536, 618, 648, 690, 832, 884, 948, 1234, -1},
    {73, 107, 190, 257, 458, 476, 537, 619, 649, 691, 833, 885, 949, 1235, -1},
    {74, 108, 191, 258, 459, 477, 538, 620, 650, 692, 834, 886, 950, 1236, -1},
    {75, 109, 192, 259, 460, 478, 539, 621, 651, 693, 835, 887, 951, 1237, -1},
    {76, 110, 193, 208, 461, 479, 540, 622, 652, 694, 836, 888, 952, 1238, -1},
    {77, 111, 194, 209, 462, 480, 541, 623, 653, 695, 837, 889, 953, 1239, -1},
    {78, 112, 195, 210, 463, 481, 542, 572, 654, 696, 838, 890, 954, 1240, -1},
    {79, 113, 196, 211, 464, 482, 543, 573, 655, 697, 839, 891, 955, 1241, -1},
    {80, 114, 197, 212, 465, 483, 544, 574, 656, 698, 840, 892, 956, 1242, -1},
    {81, 115, 198, 213, 466, 484, 545, 575, 657, 699, 841, 893, 957, 1243, -1},
    {82, 116, 199, 214, 467, 485, 546, 576, 658, 700, 842, 894, 958, 1244, -1},
    {83, 117, 200, 215, 416, 486, 547, 577, 659, 701, 843, 895, 959, 1245, -1},
    {84, 118, 201, 216, 417, 487, 548, 578, 660, 702, 844, 896, 960, 1246, -1},
    {85, 119, 202, 217, 418, 488, 549, 579, 661, 703, 845, 897, 961, 1247, -1}
};
#endif