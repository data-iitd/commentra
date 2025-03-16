
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;

class Main:
    MINIMUM_BASE = 2
    MAXIMUM_BASE = 36

    def __init__(self):
        pass

    def main(self):
        in = Scanner(System.in)
        n = in.next()
        b1 = in.nextInt()

        while b1 < self.MINIMUM_BASE or b1 > self.MAXIMUM_BASE:
            print("Invalid base! Please enter again.")
            b1 = in.nextInt()

        if not self.validForBase(n, b1):
            print("The number is invalid for this base!")
            return

        b2 = in.nextInt()

        while b2 < self.MINIMUM_BASE or b2 > self.MAXIMUM_BASE:
            print("Invalid base! Please enter again.")
            b2 = in.nextInt()

        result = self.base2base(n, b1, b2)
        print("Converted number: " + result)
        in.close()

    def validForBase(self, n, base):
        validDigits = [
            '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
            'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
            'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
            'U', 'V', 'W', 'X', 'Y', 'Z'
        ]
        digitsForBase = validDigits[0:base]
        digitsList = HashSet()

        for c in digitsForBase:
            digitsList.add(c)

        for c in n.upper():
            if not digitsList.contains(c):
                return False

        return True

    def base2base(self, n, b1, b2):
        decimalValue = 0
        output = StringBuilder()

        for charB1 in n.upper():
            charB2 = 0

            if charB1 >= 'A' and charB1 <= 'Z':
                charB2 = 10 + (charB1 - 'A')
            else:
                charB2 = charB1 - '0'

            decimalValue = decimalValue * b1 + charB2

        if decimalValue == 0:
            return "0"

        while decimalValue!= 0:
            remainder = decimalValue % b2
            output.insert(0, chr(remainder < 10 and ord('0') + remainder or ord('A') + (remainder - 10)))
            decimalValue /= b2

        return output.toString()

# 