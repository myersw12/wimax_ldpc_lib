#include "wimax_768_0_66A.h"


int16_t wimax_768_0_66A[256][10] = {
    {3, 32, 130, 160, 227, 263, 321, 353, 513, 544},
    {4, 33, 131, 161, 228, 264, 322, 354, 514, 545},
    {5, 34, 132, 162, 229, 265, 323, 355, 515, 546},
    {6, 35, 133, 163, 230, 266, 324, 356, 516, 547},
    {7, 36, 134, 164, 231, 267, 325, 357, 517, 548},
    {8, 37, 135, 165, 232, 268, 326, 358, 518, 549},
    {9, 38, 136, 166, 233, 269, 327, 359, 519, 550},
    {10, 39, 137, 167, 234, 270, 328, 360, 520, 551},
    {11, 40, 138, 168, 235, 271, 329, 361, 521, 552},
    {12, 41, 139, 169, 236, 272, 330, 362, 522, 553},
    {13, 42, 140, 170, 237, 273, 331, 363, 523, 554},
    {14, 43, 141, 171, 238, 274, 332, 364, 524, 555},
    {15, 44, 142, 172, 239, 275, 333, 365, 525, 556},
    {16, 45, 143, 173, 240, 276, 334, 366, 526, 557},
    {17, 46, 144, 174, 241, 277, 335, 367, 527, 558},
    {18, 47, 145, 175, 242, 278, 336, 368, 528, 559},
    {19, 48, 146, 176, 243, 279, 337, 369, 529, 560},
    {20, 49, 147, 177, 244, 280, 338, 370, 530, 561},
    {21, 50, 148, 178, 245, 281, 339, 371, 531, 562},
    {22, 51, 149, 179, 246, 282, 340, 372, 532, 563},
    {23, 52, 150, 180, 247, 283, 341, 373, 533, 564},
    {24, 53, 151, 181, 248, 284, 342, 374, 534, 565},
    {25, 54, 152, 182, 249, 285, 343, 375, 535, 566},
    {26, 55, 153, 183, 250, 286, 344, 376, 536, 567},
    {27, 56, 154, 184, 251, 287, 345, 377, 537, 568},
    {28, 57, 155, 185, 252, 256, 346, 378, 538, 569},
    {29, 58, 156, 186, 253, 257, 347, 379, 539, 570},
    {30, 59, 157, 187, 254, 258, 348, 380, 540, 571},
    {31, 60, 158, 188, 255, 259, 349, 381, 541, 572},
    {0, 61, 159, 189, 224, 260, 350, 382, 542, 573},
    {1, 62, 128, 190, 225, 261, 351, 383, 543, 574},
    {2, 63, 129, 191, 226, 262, 320, 352, 512, 575},
    {65, 132, 226, 266, 370, 386, 451, 480, 544, 576},
    {66, 133, 227, 267, 371, 387, 452, 481, 545, 577},
    {67, 134, 228, 268, 372, 388, 453, 482, 546, 578},
    {68, 135, 229, 269, 373, 389, 454, 483, 547, 579},
    {69, 136, 230, 270, 374, 390, 455, 484, 548, 580},
    {70, 137, 231, 271, 375, 391, 456, 485, 549, 581},
    {71, 138, 232, 272, 376, 392, 457, 486, 550, 582},
    {72, 139, 233, 273, 377, 393, 458, 487, 551, 583},
    {73, 140, 234, 274, 378, 394, 459, 488, 552, 584},
    {74, 141, 235, 275, 379, 395, 460, 489, 553, 585},
    {75, 142, 236, 276, 380, 396, 461, 490, 554, 586},
    {76, 143, 237, 277, 381, 397, 462, 491, 555, 587},
    {77, 144, 238, 278, 382, 398, 463, 492, 556, 588},
    {78, 145, 239, 279, 383, 399, 464, 493, 557, 589},
    {79, 146, 240, 280, 352, 400, 465, 494, 558, 590},
    {80, 147, 241, 281, 353, 401, 466, 495, 559, 591},
    {81, 148, 242, 282, 354, 402, 467, 496, 560, 592},
    {82, 149, 243, 283, 355, 403, 468, 497, 561, 593},
    {83, 150, 244, 284, 356, 404, 469, 498, 562, 594},
    {84, 151, 245, 285, 357, 405, 470, 499, 563, 595},
    {85, 152, 246, 286, 358, 406, 471, 500, 564, 596},
    {86, 153, 247, 287, 359, 407, 472, 501, 565, 597},
    {87, 154, 248, 256, 360, 408, 473, 502, 566, 598},
    {88, 155, 249, 257, 361, 409, 474, 503, 567, 599},
    {89, 156, 250, 258, 362, 410, 475, 504, 568, 600},
    {90, 157, 251, 259, 363, 411, 476, 505, 569, 601},
    {91, 158, 252, 260, 364, 412, 477, 506, 570, 602},
    {92, 159, 253, 261, 365, 413, 478, 507, 571, 603},
    {93, 128, 254, 262, 366, 414, 479, 508, 572, 604},
    {94, 129, 255, 263, 367, 415, 448, 509, 573, 605},
    {95, 130, 224, 264, 368, 384, 449, 510, 574, 606},
    {64, 131, 225, 265, 369, 385, 450, 511, 575, 607},
    {76, 98, 175, 232, 291, 367, 418, 461, 576, 608},
    {77, 99, 176, 233, 292, 368, 419, 462, 577, 609},
    {78, 100, 177, 234, 293, 369, 420, 463, 578, 610},
    {79, 101, 178, 235, 294, 370, 421, 464, 579, 611},
    {80, 102, 179, 236, 295, 371, 422, 465, 580, 612},
    {81, 103, 180, 237, 296, 372, 423, 466, 581, 613},
    {82, 104, 181, 238, 297, 373, 424, 467, 582, 614},
    {83, 105, 182, 239, 298, 374, 425, 468, 583, 615},
    {84, 106, 183, 240, 299, 375, 426, 469, 584, 616},
    {85, 107, 184, 241, 300, 376, 427, 470, 585, 617},
    {86, 108, 185, 242, 301, 377, 428, 471, 586, 618},
    {87, 109, 186, 243, 302, 378, 429, 472, 587, 619},
    {88, 110, 187, 244, 303, 379, 430, 473, 588, 620},
    {89, 111, 188, 245, 304, 380, 431, 474, 589, 621},
    {90, 112, 189, 246, 305, 381, 432, 475, 590, 622},
    {91, 113, 190, 247, 306, 382, 433, 476, 591, 623},
    {92, 114, 191, 248, 307, 383, 434, 477, 592, 624},
    {93, 115, 160, 249, 308, 352, 435, 478, 593, 625},
    {94, 116, 161, 250, 309, 353, 436, 479, 594, 626},
    {95, 117, 162, 251, 310, 354, 437, 448, 595, 627},
    {64, 118, 163, 252, 311, 355, 438, 449, 596, 628},
    {65, 119, 164, 253, 312, 356, 439, 450, 597, 629},
    {66, 120, 165, 254, 313, 357, 440, 451, 598, 630},
    {67, 121, 166, 255, 314, 358, 441, 452, 599, 631},
    {68, 122, 167, 224, 315, 359, 442, 453, 600, 632},
    {69, 123, 168, 225, 316, 360, 443, 454, 601, 633},
    {70, 124, 169, 226, 317, 361, 444, 455, 602, 634},
    {71, 125, 170, 227, 318, 362, 445, 456, 603, 635},
    {72, 126, 171, 228, 319, 363, 446, 457, 604, 636},
    {73, 127, 172, 229, 288, 364, 447, 458, 605, 637},
    {74, 96, 173, 230, 289, 365, 416, 459, 606, 638},
    {75, 97, 174, 231, 290, 366, 417, 460, 607, 639},
    {83, 120, 163, 192, 262, 337, 456, 487, 608, 640},
    {84, 121, 164, 193, 263, 338, 457, 488, 609, 641},
    {85, 122, 165, 194, 264, 339, 458, 489, 610, 642},
    {86, 123, 166, 195, 265, 340, 459, 490, 611, 643},
    {87, 124, 167, 196, 266, 341, 460, 491, 612, 644},
    {88, 125, 168, 197, 267, 342, 461, 492, 613, 645},
    {89, 126, 169, 198, 268, 343, 462, 493, 614, 646},
    {90, 127, 170, 199, 269, 344, 463, 494, 615, 647},
    {91, 96, 171, 200, 270, 345, 464, 495, 616, 648},
    {92, 97, 172, 201, 271, 346, 465, 496, 617, 649},
    {93, 98, 173, 202, 272, 347, 466, 497, 618, 650},
    {94, 99, 174, 203, 273, 348, 467, 498, 619, 651},
    {95, 100, 175, 204, 274, 349, 468, 499, 620, 652},
    {64, 101, 176, 205, 275, 350, 469, 500, 621, 653},
    {65, 102, 177, 206, 276, 351, 470, 501, 622, 654},
    {66, 103, 178, 207, 277, 320, 471, 502, 623, 655},
    {67, 104, 179, 208, 278, 321, 472, 503, 624, 656},
    {68, 105, 180, 209, 279, 322, 473, 504, 625, 657},
    {69, 106, 181, 210, 280, 323, 474, 505, 626, 658},
    {70, 107, 182, 211, 281, 324, 475, 506, 627, 659},
    {71, 108, 183, 212, 282, 325, 476, 507, 628, 660},
    {72, 109, 184, 213, 283, 326, 477, 508, 629, 661},
    {73, 110, 185, 214, 284, 327, 478, 509, 630, 662},
    {74, 111, 186, 215, 285, 328, 479, 510, 631, 663},
    {75, 112, 187, 216, 286, 329, 448, 511, 632, 664},
    {76, 113, 188, 217, 287, 330, 449, 480, 633, 665},
    {77, 114, 189, 218, 256, 331, 450, 481, 634, 666},
    {78, 115, 190, 219, 257, 332, 451, 482, 635, 667},
    {79, 116, 191, 220, 258, 333, 452, 483, 636, 668},
    {80, 117, 160, 221, 259, 334, 453, 484, 637, 669},
    {81, 118, 161, 222, 260, 335, 454, 485, 638, 670},
    {82, 119, 162, 223, 261, 336, 455, 486, 639, 671},
    {20, 70, 170, 221, 316, 366, 422, 512, 640, 672},
    {21, 71, 171, 222, 317, 367, 423, 513, 641, 673},
    {22, 72, 172, 223, 318, 368, 424, 514, 642, 674},
    {23, 73, 173, 192, 319, 369, 425, 515, 643, 675},
    {24, 74, 174, 193, 288, 370, 426, 516, 644, 676},
    {25, 75, 175, 194, 289, 371, 427, 517, 645, 677},
    {26, 76, 176, 195, 290, 372, 428, 518, 646, 678},
    {27, 77, 177, 196, 291, 373, 429, 519, 647, 679},
    {28, 78, 178, 197, 292, 374, 430, 520, 648, 680},
    {29, 79, 179, 198, 293, 375, 431, 521, 649, 681},
    {30, 80, 180, 199, 294, 376, 432, 522, 650, 682},
    {31, 81, 181, 200, 295, 377, 433, 523, 651, 683},
    {0, 82, 182, 201, 296, 378, 434, 524, 652, 684},
    {1, 83, 183, 202, 297, 379, 435, 525, 653, 685},
    {2, 84, 184, 203, 298, 380, 436, 526, 654, 686},
    {3, 85, 185, 204, 299, 381, 437, 527, 655, 687},
    {4, 86, 186, 205, 300, 382, 438, 528, 656, 688},
    {5, 87, 187, 206, 301, 383, 439, 529, 657, 689},
    {6, 88, 188, 207, 302, 352, 440, 530, 658, 690},
    {7, 89, 189, 208, 303, 353, 441, 531, 659, 691},
    {8, 90, 190, 209, 304, 354, 442, 532, 660, 692},
    {9, 91, 191, 210, 305, 355, 443, 533, 661, 693},
    {10, 92, 160, 211, 306, 356, 444, 534, 662, 694},
    {11, 93, 161, 212, 307, 357, 445, 535, 663, 695},
    {12, 94, 162, 213, 308, 358, 446, 536, 664, 696},
    {13, 95, 163, 214, 309, 359, 447, 537, 665, 697},
    {14, 64, 164, 215, 310, 360, 416, 538, 666, 698},
    {15, 65, 165, 216, 311, 361, 417, 539, 667, 699},
    {16, 66, 166, 217, 312, 362, 418, 540, 668, 700},
    {17, 67, 167, 218, 313, 363, 419, 541, 669, 701},
    {18, 68, 168, 219, 314, 364, 420, 542, 670, 702},
    {19, 69, 169, 220, 315, 365, 421, 543, 671, 703},
    {74, 156, 180, 264, 324, 393, 469, 493, 672, 704},
    {75, 157, 181, 265, 325, 394, 470, 494, 673, 705},
    {76, 158, 182, 266, 326, 395, 471, 495, 674, 706},
    {77, 159, 183, 267, 327, 396, 472, 496, 675, 707},
    {78, 128, 184, 268, 328, 397, 473, 497, 676, 708},
    {79, 129, 185, 269, 329, 398, 474, 498, 677, 709},
    {80, 130, 186, 270, 330, 399, 475, 499, 678, 710},
    {81, 131, 187, 271, 331, 400, 476, 500, 679, 711},
    {82, 132, 188, 272, 332, 401, 477, 501, 680, 712},
    {83, 133, 189, 273, 333, 402, 478, 502, 681, 713},
    {84, 134, 190, 274, 334, 403, 479, 503, 682, 714},
    {85, 135, 191, 275, 335, 404, 448, 504, 683, 715},
    {86, 136, 160, 276, 336, 405, 449, 505, 684, 716},
    {87, 137, 161, 277, 337, 406, 450, 506, 685, 717},
    {88, 138, 162, 278, 338, 407, 451, 507, 686, 718},
    {89, 139, 163, 279, 339, 408, 452, 508, 687, 719},
    {90, 140, 164, 280, 340, 409, 453, 509, 688, 720},
    {91, 141, 165, 281, 341, 410, 454, 510, 689, 721},
    {92, 142, 166, 282, 342, 411, 455, 511, 690, 722},
    {93, 143, 167, 283, 343, 412, 456, 480, 691, 723},
    {94, 144, 168, 284, 344, 413, 457, 481, 692, 724},
    {95, 145, 169, 285, 345, 414, 458, 482, 693, 725},
    {64, 146, 170, 286, 346, 415, 459, 483, 694, 726},
    {65, 147, 171, 287, 347, 384, 460, 484, 695, 727},
    {66, 148, 172, 256, 348, 385, 461, 485, 696, 728},
    {67, 149, 173, 257, 349, 386, 462, 486, 697, 729},
    {68, 150, 174, 258, 350, 387, 463, 487, 698, 730},
    {69, 151, 175, 259, 351, 388, 464, 488, 699, 731},
    {70, 152, 176, 260, 320, 389, 465, 489, 700, 732},
    {71, 153, 177, 261, 321, 390, 466, 490, 701, 733},
    {72, 154, 178, 262, 322, 391, 467, 491, 702, 734},
    {73, 155, 179, 263, 323, 392, 468, 492, 703, 735},
    {3, 57, 101, 181, 261, 352, 420, 468, 704, 736},
    {4, 58, 102, 182, 262, 353, 421, 469, 705, 737},
    {5, 59, 103, 183, 263, 354, 422, 470, 706, 738},
    {6, 60, 104, 184, 264, 355, 423, 471, 707, 739},
    {7, 61, 105, 185, 265, 356, 424, 472, 708, 740},
    {8, 62, 106, 186, 266, 357, 425, 473, 709, 741},
    {9, 63, 107, 187, 267, 358, 426, 474, 710, 742},
    {10, 32, 108, 188, 268, 359, 427, 475, 711, 743},
    {11, 33, 109, 189, 269, 360, 428, 476, 712, 744},
    {12, 34, 110, 190, 270, 361, 429, 477, 713, 745},
    {13, 35, 111, 191, 271, 362, 430, 478, 714, 746},
    {14, 36, 112, 160, 272, 363, 431, 479, 715, 747},
    {15, 37, 113, 161, 273, 364, 432, 448, 716, 748},
    {16, 38, 114, 162, 274, 365, 433, 449, 717, 749},
    {17, 39, 115, 163, 275, 366, 434, 450, 718, 750},
    {18, 40, 116, 164, 276, 367, 435, 451, 719, 751},
    {19, 41, 117, 165, 277, 368, 436, 452, 720, 752},
    {20, 42, 118, 166, 278, 369, 437, 453, 721, 753},
    {21, 43, 119, 167, 279, 370, 438, 454, 722, 754},
    {22, 44, 120, 168, 280, 371, 439, 455, 723, 755},
    {23, 45, 121, 169, 281, 372, 440, 456, 724, 756},
    {24, 46, 122, 170, 282, 373, 441, 457, 725, 757},
    {25, 47, 123, 171, 283, 374, 442, 458, 726, 758},
    {26, 48, 124, 172, 284, 375, 443, 459, 727, 759},
    {27, 49, 125, 173, 285, 376, 444, 460, 728, 760},
    {28, 50, 126, 174, 286, 377, 445, 461, 729, 761},
    {29, 51, 127, 175, 287, 378, 446, 462, 730, 762},
    {30, 52, 96, 176, 256, 379, 447, 463, 731, 763},
    {31, 53, 97, 177, 257, 380, 416, 464, 732, 764},
    {0, 54, 98, 178, 258, 381, 417, 465, 733, 765},
    {1, 55, 99, 179, 259, 382, 418, 466, 734, 766},
    {2, 56, 100, 180, 260, 383, 419, 467, 735, 767},
    {38, 70, 196, 270, 318, 355, 388, 462, 513, 736},
    {39, 71, 197, 271, 319, 356, 389, 463, 514, 737},
    {40, 72, 198, 272, 288, 357, 390, 464, 515, 738},
    {41, 73, 199, 273, 289, 358, 391, 465, 516, 739},
    {42, 74, 200, 274, 290, 359, 392, 466, 517, 740},
    {43, 75, 201, 275, 291, 360, 393, 467, 518, 741},
    {44, 76, 202, 276, 292, 361, 394, 468, 519, 742},
    {45, 77, 203, 277, 293, 362, 395, 469, 520, 743},
    {46, 78, 204, 278, 294, 363, 396, 470, 521, 744},
    {47, 79, 205, 279, 295, 364, 397, 471, 522, 745},
    {48, 80, 206, 280, 296, 365, 398, 472, 523, 746},
    {49, 81, 207, 281, 297, 366, 399, 473, 524, 747},
    {50, 82, 208, 282, 298, 367, 400, 474, 525, 748},
    {51, 83, 209, 283, 299, 368, 401, 475, 526, 749},
    {52, 84, 210, 284, 300, 369, 402, 476, 527, 750},
    {53, 85, 211, 285, 301, 370, 403, 477, 528, 751},
    {54, 86, 212, 286, 302, 371, 404, 478, 529, 752},
    {55, 87, 213, 287, 303, 372, 405, 479, 530, 753},
    {56, 88, 214, 256, 304, 373, 406, 448, 531, 754},
    {57, 89, 215, 257, 305, 374, 407, 449, 532, 755},
    {58, 90, 216, 258, 306, 375, 408, 450, 533, 756},
    {59, 91, 217, 259, 307, 376, 409, 451, 534, 757},
    {60, 92, 218, 260, 308, 377, 410, 452, 535, 758},
    {61, 93, 219, 261, 309, 378, 411, 453, 536, 759},
    {62, 94, 220, 262, 310, 379, 412, 454, 537, 760},
    {63, 95, 221, 263, 311, 380, 413, 455, 538, 761},
    {32, 64, 222, 264, 312, 381, 414, 456, 539, 762},
    {33, 65, 223, 265, 313, 382, 415, 457, 540, 763},
    {34, 66, 192, 266, 314, 383, 384, 458, 541, 764},
    {35, 67, 193, 267, 315, 352, 385, 459, 542, 765},
    {36, 68, 194, 268, 316, 353, 386, 460, 543, 766},
    {37, 69, 195, 269, 317, 354, 387, 461, 512, 767}
};