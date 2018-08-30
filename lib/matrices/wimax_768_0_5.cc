#include "matrices.h"


#ifdef Z_32
unsigned int wimax_768_0_5_D = 2;
unsigned int wimax_768_0_5_X = 5;

int16_t wimax_768_0_5[384][7] = {
    {63, 88, 274, 315, 386, 416, -1},
    {32, 89, 275, 316, 387, 417, -1},
    {33, 90, 276, 317, 388, 418, -1},
    {34, 91, 277, 318, 389, 419, -1},
    {35, 92, 278, 319, 390, 420, -1},
    {36, 93, 279, 288, 391, 421, -1},
    {37, 94, 280, 289, 392, 422, -1},
    {38, 95, 281, 290, 393, 423, -1},
    {39, 64, 282, 291, 394, 424, -1},
    {40, 65, 283, 292, 395, 425, -1},
    {41, 66, 284, 293, 396, 426, -1},
    {42, 67, 285, 294, 397, 427, -1},
    {43, 68, 286, 295, 398, 428, -1},
    {44, 69, 287, 296, 399, 429, -1},
    {45, 70, 256, 297, 400, 430, -1},
    {46, 71, 257, 298, 401, 431, -1},
    {47, 72, 258, 299, 402, 432, -1},
    {48, 73, 259, 300, 403, 433, -1},
    {49, 74, 260, 301, 404, 434, -1},
    {50, 75, 261, 302, 405, 435, -1},
    {51, 76, 262, 303, 406, 436, -1},
    {52, 77, 263, 304, 407, 437, -1},
    {53, 78, 264, 305, 408, 438, -1},
    {54, 79, 265, 306, 409, 439, -1},
    {55, 80, 266, 307, 410, 440, -1},
    {56, 81, 267, 308, 411, 441, -1},
    {57, 82, 268, 309, 412, 442, -1},
    {58, 83, 269, 310, 413, 443, -1},
    {59, 84, 270, 311, 414, 444, -1},
    {60, 85, 271, 312, 415, 445, -1},
    {61, 86, 272, 313, 384, 446, -1},
    {62, 87, 273, 314, 385, 447, -1},
    {41, 167, 218, 227, 356, 416, 448},
    {42, 168, 219, 228, 357, 417, 449},
    {43, 169, 220, 229, 358, 418, 450},
    {44, 170, 221, 230, 359, 419, 451},
    {45, 171, 222, 231, 360, 420, 452},
    {46, 172, 223, 232, 361, 421, 453},
    {47, 173, 192, 233, 362, 422, 454},
    {48, 174, 193, 234, 363, 423, 455},
    {49, 175, 194, 235, 364, 424, 456},
    {50, 176, 195, 236, 365, 425, 457},
    {51, 177, 196, 237, 366, 426, 458},
    {52, 178, 197, 238, 367, 427, 459},
    {53, 179, 198, 239, 368, 428, 460},
    {54, 180, 199, 240, 369, 429, 461},
    {55, 181, 200, 241, 370, 430, 462},
    {56, 182, 201, 242, 371, 431, 463},
    {57, 183, 202, 243, 372, 432, 464},
    {58, 184, 203, 244, 373, 433, 465},
    {59, 185, 204, 245, 374, 434, 466},
    {60, 186, 205, 246, 375, 435, 467},
    {61, 187, 206, 247, 376, 436, 468},
    {62, 188, 207, 248, 377, 437, 469},
    {63, 189, 208, 249, 378, 438, 470},
    {32, 190, 209, 250, 379, 439, 471},
    {33, 191, 210, 251, 380, 440, 472},
    {34, 160, 211, 252, 381, 441, 473},
    {35, 161, 212, 253, 382, 442, 474},
    {36, 162, 213, 254, 383, 443, 475},
    {37, 163, 214, 255, 352, 444, 476},
    {38, 164, 215, 224, 353, 445, 477},
    {39, 165, 216, 225, 354, 446, 478},
    {40, 166, 217, 226, 355, 447, 479},
    {104, 135, 187, 235, 352, 448, 480},
    {105, 136, 188, 236, 353, 449, 481},
    {106, 137, 189, 237, 354, 450, 482},
    {107, 138, 190, 238, 355, 451, 483},
    {108, 139, 191, 239, 356, 452, 484},
    {109, 140, 160, 240, 357, 453, 485},
    {110, 141, 161, 241, 358, 454, 486},
    {111, 142, 162, 242, 359, 455, 487},
    {112, 143, 163, 243, 360, 456, 488},
    {113, 144, 164, 244, 361, 457, 489},
    {114, 145, 165, 245, 362, 458, 490},
    {115, 146, 166, 246, 363, 459, 491},
    {116, 147, 167, 247, 364, 460, 492},
    {117, 148, 168, 248, 365, 461, 493},
    {118, 149, 169, 249, 366, 462, 494},
    {119, 150, 170, 250, 367, 463, 495},
    {120, 151, 171, 251, 368, 464, 496},
    {121, 152, 172, 252, 369, 465, 497},
    {122, 153, 173, 253, 370, 466, 498},
    {123, 154, 174, 254, 371, 467, 499},
    {124, 155, 175, 255, 372, 468, 500},
    {125, 156, 176, 224, 373, 469, 501},
    {126, 157, 177, 225, 374, 470, 502},
    {127, 158, 178, 226, 375, 471, 503},
    {96, 159, 179, 227, 376, 472, 504},
    {97, 128, 180, 228, 377, 473, 505},
    {98, 129, 181, 229, 378, 474, 506},
    {99, 130, 182, 230, 379, 475, 507},
    {100, 131, 183, 231, 380, 476, 508},
    {101, 132, 184, 232, 381, 477, 509},
    {102, 133, 185, 233, 382, 478, 510},
    {103, 134, 186, 234, 383, 479, 511},
    {20, 79, 277, 296, 480, 512, -1},
    {21, 80, 278, 297, 481, 513, -1},
    {22, 81, 279, 298, 482, 514, -1},
    {23, 82, 280, 299, 483, 515, -1},
    {24, 83, 281, 300, 484, 516, -1},
    {25, 84, 282, 301, 485, 517, -1},
    {26, 85, 283, 302, 486, 518, -1},
    {27, 86, 284, 303, 487, 519, -1},
    {28, 87, 285, 304, 488, 520, -1},
    {29, 88, 286, 305, 489, 521, -1},
    {30, 89, 287, 306, 490, 522, -1},
    {31, 90, 256, 307, 491, 523, -1},
    {0, 91, 257, 308, 492, 524, -1},
    {1, 92, 258, 309, 493, 525, -1},
    {2, 93, 259, 310, 494, 526, -1},
    {3, 94, 260, 311, 495, 527, -1},
    {4, 95, 261, 312, 496, 528, -1},
    {5, 64, 262, 313, 497, 529, -1},
    {6, 65, 263, 314, 498, 530, -1},
    {7, 66, 264, 315, 499, 531, -1},
    {8, 67, 265, 316, 500, 532, -1},
    {9, 68, 266, 317, 501, 533, -1},
    {10, 69, 267, 318, 502, 534, -1},
    {11, 70, 268, 319, 503, 535, -1},
    {12, 71, 269, 288, 504, 536, -1},
    {13, 72, 270, 289, 505, 537, -1},
    {14, 73, 271, 290, 506, 538, -1},
    {15, 74, 272, 291, 507, 539, -1},
    {16, 75, 273, 292, 508, 540, -1},
    {17, 76, 274, 293, 509, 541, -1},
    {18, 77, 275, 294, 510, 542, -1},
    {19, 78, 276, 295, 511, 543, -1},
    {77, 220, 301, 344, 512, 544, -1},
    {78, 221, 302, 345, 513, 545, -1},
    {79, 222, 303, 346, 514, 546, -1},
    {80, 223, 304, 347, 515, 547, -1},
    {81, 192, 305, 348, 516, 548, -1},
    {82, 193, 306, 349, 517, 549, -1},
    {83, 194, 307, 350, 518, 550, -1},
    {84, 195, 308, 351, 519, 551, -1},
    {85, 196, 309, 320, 520, 552, -1},
    {86, 197, 310, 321, 521, 553, -1},
    {87, 198, 311, 322, 522, 554, -1},
    {88, 199, 312, 323, 523, 555, -1},
    {89, 200, 313, 324, 524, 556, -1},
    {90, 201, 314, 325, 525, 557, -1},
    {91, 202, 315, 326, 526, 558, -1},
    {92, 203, 316, 327, 527, 559, -1},
    {93, 204, 317, 328, 528, 560, -1},
    {94, 205, 318, 329, 529, 561, -1},
    {95, 206, 319, 330, 530, 562, -1},
    {64, 207, 288, 331, 531, 563, -1},
    {65, 208, 289, 332, 532, 564, -1},
    {66, 209, 290, 333, 533, 565, -1},
    {67, 210, 291, 334, 534, 566, -1},
    {68, 211, 292, 335, 535, 567, -1},
    {69, 212, 293, 336, 536, 568, -1},
    {70, 213, 294, 337, 537, 569, -1},
    {71, 214, 295, 338, 538, 570, -1},
    {72, 215, 296, 339, 539, 571, -1},
    {73, 216, 297, 340, 540, 572, -1},
    {74, 217, 298, 341, 541, 573, -1},
    {75, 218, 299, 342, 542, 574, -1},
    {76, 219, 300, 343, 543, 575, -1},
    {143, 173, 251, 378, 384, 544, 576},
    {144, 174, 252, 379, 385, 545, 577},
    {145, 175, 253, 380, 386, 546, 578},
    {146, 176, 254, 381, 387, 547, 579},
    {147, 177, 255, 382, 388, 548, 580},
    {148, 178, 224, 383, 389, 549, 581},
    {149, 179, 225, 352, 390, 550, 582},
    {150, 180, 226, 353, 391, 551, 583},
    {151, 181, 227, 354, 392, 552, 584},
    {152, 182, 228, 355, 393, 553, 585},
    {153, 183, 229, 356, 394, 554, 586},
    {154, 184, 230, 357, 395, 555, 587},
    {155, 185, 231, 358, 396, 556, 588},
    {156, 186, 232, 359, 397, 557, 589},
    {157, 187, 233, 360, 398, 558, 590},
    {158, 188, 234, 361, 399, 559, 591},
    {159, 189, 235, 362, 400, 560, 592},
    {128, 190, 236, 363, 401, 561, 593},
    {129, 191, 237, 364, 402, 562, 594},
    {130, 160, 238, 365, 403, 563, 595},
    {131, 161, 239, 366, 404, 564, 596},
    {132, 162, 240, 367, 405, 565, 597},
    {133, 163, 241, 368, 406, 566, 598},
    {134, 164, 242, 369, 407, 567, 599},
    {135, 165, 243, 370, 408, 568, 600},
    {136, 166, 244, 371, 409, 569, 601},
    {137, 167, 245, 372, 410, 570, 602},
    {138, 168, 246, 373, 411, 571, 603},
    {139, 169, 247, 374, 412, 572, 604},
    {140, 170, 248, 375, 413, 573, 605},
    {141, 171, 249, 376, 414, 574, 606},
    {142, 172, 250, 377, 415, 575, 607},
    {95, 113, 292, 326, 576, 608, -1},
    {64, 114, 293, 327, 577, 609, -1},
    {65, 115, 294, 328, 578, 610, -1},
    {66, 116, 295, 329, 579, 611, -1},
    {67, 117, 296, 330, 580, 612, -1},
    {68, 118, 297, 331, 581, 613, -1},
    {69, 119, 298, 332, 582, 614, -1},
    {70, 120, 299, 333, 583, 615, -1},
    {71, 121, 300, 334, 584, 616, -1},
    {72, 122, 301, 335, 585, 617, -1},
    {73, 123, 302, 336, 586, 618, -1},
    {74, 124, 303, 337, 587, 619, -1},
    {75, 125, 304, 338, 588, 620, -1},
    {76, 126, 305, 339, 589, 621, -1},
    {77, 127, 306, 340, 590, 622, -1},
    {78, 96, 307, 341, 591, 623, -1},
    {79, 97, 308, 342, 592, 624, -1},
    {80, 98, 309, 343, 593, 625, -1},
    {81, 99, 310, 344, 594, 626, -1},
    {82, 100, 311, 345, 595, 627, -1},
    {83, 101, 312, 346, 596, 628, -1},
    {84, 102, 313, 347, 597, 629, -1},
    {85, 103, 314, 348, 598, 630, -1},
    {86, 104, 315, 349, 599, 631, -1},
    {87, 105, 316, 350, 600, 632, -1},
    {88, 106, 317, 351, 601, 633, -1},
    {89, 107, 318, 320, 602, 634, -1},
    {90, 108, 319, 321, 603, 635, -1},
    {91, 109, 288, 322, 604, 636, -1},
    {92, 110, 289, 323, 605, 637, -1},
    {93, 111, 290, 324, 606, 638, -1},
    {94, 112, 291, 325, 607, 639, -1},
    {35, 88, 192, 303, 608, 640, -1},
    {36, 89, 193, 304, 609, 641, -1},
    {37, 90, 194, 305, 610, 642, -1},
    {38, 91, 195, 306, 611, 643, -1},
    {39, 92, 196, 307, 612, 644, -1},
    {40, 93, 197, 308, 613, 645, -1},
    {41, 94, 198, 309, 614, 646, -1},
    {42, 95, 199, 310, 615, 647, -1},
    {43, 64, 200, 311, 616, 648, -1},
    {44, 65, 201, 312, 617, 649, -1},
    {45, 66, 202, 313, 618, 650, -1},
    {46, 67, 203, 314, 619, 651, -1},
    {47, 68, 204, 315, 620, 652, -1},
    {48, 69, 205, 316, 621, 653, -1},
    {49, 70, 206, 317, 622, 654, -1},
    {50, 71, 207, 318, 623, 655, -1},
    {51, 72, 208, 319, 624, 656, -1},
    {52, 73, 209, 288, 625, 657, -1},
    {53, 74, 210, 289, 626, 658, -1},
    {54, 75, 211, 290, 627, 659, -1},
    {55, 76, 212, 291, 628, 660, -1},
    {56, 77, 213, 292, 629, 661, -1},
    {57, 78, 214, 293, 630, 662, -1},
    {58, 79, 215, 294, 631, 663, -1},
    {59, 80, 216, 295, 632, 664, -1},
    {60, 81, 217, 296, 633, 665, -1},
    {61, 82, 218, 297, 634, 666, -1},
    {62, 83, 219, 298, 635, 667, -1},
    {63, 84, 220, 299, 636, 668, -1},
    {32, 85, 221, 300, 637, 669, -1},
    {33, 86, 222, 301, 638, 670, -1},
    {34, 87, 223, 302, 639, 671, -1},
    {4, 155, 168, 238, 369, 640, 672},
    {5, 156, 169, 239, 370, 641, 673},
    {6, 157, 170, 240, 371, 642, 674},
    {7, 158, 171, 241, 372, 643, 675},
    {8, 159, 172, 242, 373, 644, 676},
    {9, 128, 173, 243, 374, 645, 677},
    {10, 129, 174, 244, 375, 646, 678},
    {11, 130, 175, 245, 376, 647, 679},
    {12, 131, 176, 246, 377, 648, 680},
    {13, 132, 177, 247, 378, 649, 681},
    {14, 133, 178, 248, 379, 650, 682},
    {15, 134, 179, 249, 380, 651, 683},
    {16, 135, 180, 250, 381, 652, 684},
    {17, 136, 181, 251, 382, 653, 685},
    {18, 137, 182, 252, 383, 654, 686},
    {19, 138, 183, 253, 352, 655, 687},
    {20, 139, 184, 254, 353, 656, 688},
    {21, 140, 185, 255, 354, 657, 689},
    {22, 141, 186, 224, 355, 658, 690},
    {23, 142, 187, 225, 356, 659, 691},
    {24, 143, 188, 226, 357, 660, 692},
    {25, 144, 189, 227, 358, 661, 693},
    {26, 145, 190, 228, 359, 662, 694},
    {27, 146, 191, 229, 360, 663, 695},
    {28, 147, 160, 230, 361, 664, 696},
    {29, 148, 161, 231, 362, 665, 697},
    {30, 149, 162, 232, 363, 666, 698},
    {31, 150, 163, 233, 364, 667, 699},
    {0, 151, 164, 234, 365, 668, 700},
    {1, 152, 165, 235, 366, 669, 701},
    {2, 153, 166, 236, 367, 670, 702},
    {3, 154, 167, 237, 368, 671, 703},
    {191, 243, 343, 376, 672, 704, -1},
    {160, 244, 344, 377, 673, 705, -1},
    {161, 245, 345, 378, 674, 706, -1},
    {162, 246, 346, 379, 675, 707, -1},
    {163, 247, 347, 380, 676, 708, -1},
    {164, 248, 348, 381, 677, 709, -1},
    {165, 249, 349, 382, 678, 710, -1},
    {166, 250, 350, 383, 679, 711, -1},
    {167, 251, 351, 352, 680, 712, -1},
    {168, 252, 320, 353, 681, 713, -1},
    {169, 253, 321, 354, 682, 714, -1},
    {170, 254, 322, 355, 683, 715, -1},
    {171, 255, 323, 356, 684, 716, -1},
    {172, 224, 324, 357, 685, 717, -1},
    {173, 225, 325, 358, 686, 718, -1},
    {174, 226, 326, 359, 687, 719, -1},
    {175, 227, 327, 360, 688, 720, -1},
    {176, 228, 328, 361, 689, 721, -1},
    {177, 229, 329, 362, 690, 722, -1},
    {178, 230, 330, 363, 691, 723, -1},
    {179, 231, 331, 364, 692, 724, -1},
    {180, 232, 332, 365, 693, 725, -1},
    {181, 233, 333, 366, 694, 726, -1},
    {182, 234, 334, 367, 695, 727, -1},
    {183, 235, 335, 368, 696, 728, -1},
    {184, 236, 336, 369, 697, 729, -1},
    {185, 237, 337, 370, 698, 730, -1},
    {186, 238, 338, 371, 699, 731, -1},
    {187, 239, 339, 372, 700, 732, -1},
    {188, 240, 340, 373, 701, 733, -1},
    {189, 241, 341, 374, 702, 734, -1},
    {190, 242, 342, 375, 703, 735, -1},
    {66, 117, 269, 304, 704, 736, -1},
    {67, 118, 270, 305, 705, 737, -1},
    {68, 119, 271, 306, 706, 738, -1},
    {69, 120, 272, 307, 707, 739, -1},
    {70, 121, 273, 308, 708, 740, -1},
    {71, 122, 274, 309, 709, 741, -1},
    {72, 123, 275, 310, 710, 742, -1},
    {73, 124, 276, 311, 711, 743, -1},
    {74, 125, 277, 312, 712, 744, -1},
    {75, 126, 278, 313, 713, 745, -1},
    {76, 127, 279, 314, 714, 746, -1},
    {77, 96, 280, 315, 715, 747, -1},
    {78, 97, 281, 316, 716, 748, -1},
    {79, 98, 282, 317, 717, 749, -1},
    {80, 99, 283, 318, 718, 750, -1},
    {81, 100, 284, 319, 719, 751, -1},
    {82, 101, 285, 288, 720, 752, -1},
    {83, 102, 286, 289, 721, 753, -1},
    {84, 103, 287, 290, 722, 754, -1},
    {85, 104, 256, 291, 723, 755, -1},
    {86, 105, 257, 292, 724, 756, -1},
    {87, 106, 258, 293, 725, 757, -1},
    {88, 107, 259, 294, 726, 758, -1},
    {89, 108, 260, 295, 727, 759, -1},
    {90, 109, 261, 296, 728, 760, -1},
    {91, 110, 262, 297, 729, 761, -1},
    {92, 111, 263, 298, 730, 762, -1},
    {93, 112, 264, 299, 731, 763, -1},
    {94, 113, 265, 300, 732, 764, -1},
    {95, 114, 266, 301, 733, 765, -1},
    {64, 115, 267, 302, 734, 766, -1},
    {65, 116, 268, 303, 735, 767, -1},
    {14, 182, 237, 360, 386, 736, -1},
    {15, 183, 238, 361, 387, 737, -1},
    {16, 184, 239, 362, 388, 738, -1},
    {17, 185, 240, 363, 389, 739, -1},
    {18, 186, 241, 364, 390, 740, -1},
    {19, 187, 242, 365, 391, 741, -1},
    {20, 188, 243, 366, 392, 742, -1},
    {21, 189, 244, 367, 393, 743, -1},
    {22, 190, 245, 368, 394, 744, -1},
    {23, 191, 246, 369, 395, 745, -1},
    {24, 160, 247, 370, 396, 746, -1},
    {25, 161, 248, 371, 397, 747, -1},
    {26, 162, 249, 372, 398, 748, -1},
    {27, 163, 250, 373, 399, 749, -1},
    {28, 164, 251, 374, 400, 750, -1},
    {29, 165, 252, 375, 401, 751, -1},
    {30, 166, 253, 376, 402, 752, -1},
    {31, 167, 254, 377, 403, 753, -1},
    {0, 168, 255, 378, 404, 754, -1},
    {1, 169, 224, 379, 405, 755, -1},
    {2, 170, 225, 380, 406, 756, -1},
    {3, 171, 226, 381, 407, 757, -1},
    {4, 172, 227, 382, 408, 758, -1},
    {5, 173, 228, 383, 409, 759, -1},
    {6, 174, 229, 352, 410, 760, -1},
    {7, 175, 230, 353, 411, 761, -1},
    {8, 176, 231, 354, 412, 762, -1},
    {9, 177, 232, 355, 413, 763, -1},
    {10, 178, 233, 356, 414, 764, -1},
    {11, 179, 234, 357, 415, 765, -1},
    {12, 180, 235, 358, 384, 766, -1},
    {13, 181, 236, 359, 385, 767, -1}
};
#endif