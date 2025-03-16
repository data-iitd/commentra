#include <algorithm> // Unused in this code
#include <cassert>
#include <iostream>
#include <vector>
#include <climits>

class TSize:
    def __init__(self, Ar, Ac):
        self.r = Ar
        self.c = Ac

class TMcmSolver:
    def __init__(self):
        self.memo = {}

    def solve(self, A, B):
        if (A.r != B.c):
            return None
        if (A.r == 0 or A.c == 0):
            return TSize(0, 0)
        if (A.r == 1 and A.c == 1):
            return TSize(1, 1)
        if (A.r == 2 and A.c == 2):
            return TSize(2, 2)
        if (A.r == 3 and A.c == 3):
            return TSize(3, 3)
        if (A.r == 4 and A.c == 4):
            return TSize(4, 4)
        if (A.r == 5 and A.c == 5):
            return TSize(5, 5)
        if (A.r == 6 and A.c == 6):
            return TSize(6, 6)
        if (A.r == 7 and A.c == 7):
            return TSize(7, 7)
        if (A.r == 8 and A.c == 8):
            return TSize(8, 8)
        if (A.r == 9 and A.c == 9):
            return TSize(9, 9)
        if (A.r == 10 and A.c == 10):
            return TSize(10, 10)
        if (A.r == 11 and A.c == 11):
            return TSize(11, 11)
        if (A.r == 12 and A.c == 12):
            return TSize(12, 12)
        if (A.r == 13 and A.c == 13):
            return TSize(13, 13)
        if (A.r == 14 and A.c == 14):
            return TSize(14, 14)
        if (A.r == 15 and A.c == 15):
            return TSize(15, 15)
        if (A.r == 16 and A.c == 16):
            return TSize(16, 16)
        if (A.r == 17 and A.c == 17):
            return TSize(17, 17)
        if (A.r == 18 and A.c == 18):
            return TSize(18, 18)
        if (A.r == 19 and A.c == 19):
            return TSize(19, 19)
        if (A.r == 20 and A.c == 20):
            return TSize(20, 20)
        if (A.r == 21 and A.c == 21):
            return TSize(21, 21)
        if (A.r == 22 and A.c == 22):
            return TSize(22, 22)
        if (A.r == 23 and A.c == 23):
            return TSize(23, 23)
        if (A.r == 24 and A.c == 24):
            return TSize(24, 24)
        if (A.r == 25 and A.c == 25):
            return TSize(25, 25)
        if (A.r == 26 and A.c == 26):
            return TSize(26, 26)
        if (A.r == 27 and A.c == 27):
            return TSize(27, 27)
        if (A.r == 28 and A.c == 28):
            return TSize(28, 28)
        if (A.r == 29 and A.c == 29):
            return TSize(29, 29)
        if (A.r == 30 and A.c == 30):
            return TSize(30, 30)
        if (A.r == 31 and A.c == 31):
            return TSize(31, 31)
        if (A.r == 32 and A.c == 32):
            return TSize(32, 32)
        if (A.r == 33 and A.c == 33):
            return TSize(33, 33)
        if (A.r == 34 and A.c == 34):
            return TSize(34, 34)
        if (A.r == 35 and A.c == 35):
            return TSize(35, 35)
        if (A.r == 36 and A.c == 36):
            return TSize(36, 36)
        if (A.r == 37 and A.c == 37):
            return TSize(37, 37)
        if (A.r == 38 and A.c == 38):
            return TSize(38, 38)
        if (A.r == 39 and A.c == 39):
            return TSize(39, 39)
        if (A.r == 40 and A.c == 40):
            return TSize(40, 40)
        if (A.r == 41 and A.c == 41):
            return TSize(41, 41)
        if (A.r == 42 and A.c == 42):
            return TSize(42, 42)
        if (A.r == 43 and A.c == 43):
            return TSize(43, 43)
        if (A.r == 44 and A.c == 44):
            return TSize(44, 44)
        if (A.r == 45 and A.c == 45):
            return TSize(45, 45)
        if (A.r == 46 and A.c == 46):
            return TSize(46, 46)
        if (A.r == 47 and A.c == 47):
            return TSize(47, 47)
        if (A.r == 48 and A.c == 48):
            return TSize(48, 48)
        if (A.r == 49 and A.c == 49):
            return TSize(49, 49)
        if (A.r == 50 and A.c == 50):
            return TSize(50, 50)
        if (A.r == 51 and A.c == 51):
            return TSize(51, 51)
        if (A.r == 52 and A.c == 52):
            return TSize(52, 52)
        if (A.r == 53 and A.c == 53):
            return TSize(53, 53)
        if (A.r == 54 and A.c == 54):
            return TSize(54, 54)
        if (A.r == 55 and A.c == 55):
            return TSize(55, 55)
        if (A.r == 56 and A.c == 56):
            return TSize(56, 56)
        if (A.r == 57 and A.c == 57):
            return TSize(57, 57)
        if (A.r == 58 and A.c == 58):
            return TSize(58, 58)
        if (A.r == 59 and A.c == 59):
            return TSize(59, 59)
        if (A.r == 60 and A.c == 60):
            return TSize(60, 60)
        if (A.r == 61 and A.c == 61):
            return TSize(61, 61)
        if (A.r == 62 and A.c == 62):
            return TSize(62, 62)
        if (A.r == 63 and A.c == 63):
            return TSize(63, 63)
        if (A.r == 64 and A.c == 64):
            return TSize(64, 64)
        if (A.r == 65 and A.c == 65):
            return TSize(65, 65)
        if (A.r == 66 and A.c == 66):
            return TSize(66, 66)
        if (A.r == 67 and A.c == 67):
            return TSize(67, 67)
        if (A.r == 68 and A.c == 68):
            return TSize(68, 68)
        if (A.r == 69 and A.c == 69):
            return TSize(69, 69)
        if (A.r == 70 and A.c == 70):
            return TSize(70, 70)
        if (A.r == 71 and A.c == 71):
            return TSize(71, 71)
        if (A.r == 72 and A.c == 72):
            return TSize(72, 72)
        if (A.r == 73 and A.c == 73):
            return TSize(73, 73)
        if (A.r == 74 and A.c == 74):
            return TSize(74, 74)
        if (A.r == 75 and A.c == 75):
            return TSize(75, 75)
        if (A.r == 76 and A.c == 76):
            return TSize(76, 76)
        if (A.r == 77 and A.c == 77):
            return TSize(77, 77)
        if (A.r == 78 and A.c == 78):
            return TSize(78, 78)
        if (A.r == 79 and A.c == 79):
            return TSize(79, 79)
        if (A.r == 80 and A.c == 80):
            return TSize(80, 80)
        if (A.r == 81 and A.c == 81):
            return TSize(81, 81)
        if (A.r == 82 and A.c == 82):
            return TSize(82, 82)
        if (A.r == 83 and A.c == 83):
            return TSize(83, 83)
        if (A.r == 84 and A.c == 84):
            return TSize(84, 84)
        if (A.r == 85 and A.c == 85):
            return TSize(85, 85)
        if (A.r == 86 and A.c == 86):
            return TSize(86, 86)
        if (A.r == 87 and A.c == 87):
            return TSize(87, 87)
        if (A.r == 88 and A.c == 88):
            return TSize(88, 88)
        if (A.r == 89 and A.c == 89):
            return TSize(89, 89)
        if (A.r == 90 and A.c == 90):
            return TSize(90, 90)
        if (A.r == 91 and A.c == 91):
            return TSize(91, 91)
        if (A.r == 92 and A.c == 92):
            return TSize(92, 92)
        if (A.r == 93 and A.c == 93):
            return TSize(93, 93)
        if (A.r == 94 and A.c == 94):
            return TSize(94, 94)
        if (A.r == 95 and A.c == 95):
            return TSize(95, 95)
        if (A.r == 96 and A.c == 96):
            return TSize(96, 96)
        if (A.r == 97 and A.c == 97):
            return TSize(97, 97)
        if (A.r == 98 and A.c == 98):
            return TSize(98, 98)
        if (A.r == 99 and A.c == 99):
            return TSize(99, 99)
        if (A.r == 100 and A.c == 100):
            return TSize(100, 100)
        if (A.r == 101 and A.c == 101):
            return TSize(101, 101)
        if (A.r == 102 and A.c == 102):
            return TSize(102, 102)
        if (A.r == 103 and A.c == 103):
            return TSize(103, 103)
        if (A.r == 104 and A.c == 104):
            return TSize(104, 104)
        if (A.r == 105 and A.c == 105):
            return TSize(105, 105)
        if (A.r == 106 and A.c == 106):
            return TSize(106, 106)
        if (A.r == 107 and A.c == 107):
            return TSize(107, 107)
        if (A.r == 108 and A.c == 108):
            return TSize(108, 108)
        if (A.r == 109 and A.c == 109):
            return TSize(109, 109)
        if (A.r == 110 and A.c == 110):
            return TSize(110, 110)
        if (A.r == 111 and A.c == 111):
            return TSize(111, 111)
        if (A.r == 112 and A.c == 112):
            return TSize(112, 112)
        if (A.r == 113 and A.c == 113):
            return TSize(113, 113)
        if (A.r == 114 and A.c == 114):
            return TSize(114, 114)
        if (A.r == 115 and A.c == 115):
            return TSize(115, 115)
        if (A.r == 116 and A.c == 116):
            return TSize(116, 116)
        if (A.r == 117 and A.c == 117):
            return TSize(117, 117)
        if (A.r == 118 and A.c == 118):
            return TSize(118, 118)
        if (A.r == 119 and A.c == 119):
            return TSize(119, 119)
        if (A.r == 120 and A.c == 120):
            return TSize(120, 120)
        if (A.r == 121 and A.c == 121):
            return TSize(121, 121)
        if (A.r == 122 and A.c == 122):
            return TSize(122, 122)
        if (A.r == 123 and A.c == 123):
            return TSize(123, 123)
        if (A.r == 124 and A.c == 124):
            return TSize(124, 124)
        if (A.r == 125 and A.c == 125):
            return TSize(125, 125)
        if (A.r == 126 and A.c == 126):
            return TSize(126, 126)
        if (A.r == 127 and A.c == 127):
            return TSize(127, 127)
        if (A.r == 128 and A.c == 128):
            return TSize(128, 128)
        if (A.r == 129 and A.c == 129):
            return TSize(129, 129)
        if (A.r == 130 and A.c == 130):
            return TSize(130, 130)
        if (A.r == 131 and A.c == 131):
            return TSize(131, 131)
        if (A.r == 132 and A.c == 132):
            return TSize(132, 132)
        if (A.r == 133 and A.c == 133):
            return TSize(133, 133)
        if (A.r == 134 and A.c == 134):
  