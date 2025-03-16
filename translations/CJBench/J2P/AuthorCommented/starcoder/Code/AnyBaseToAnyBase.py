
import sys

class Main:
    MINIMUM_BASE = 2
    MAXIMUM_BASE = 36

    def __init__(self):
        self.in_ = sys.stdin.readline
        self.out_ = sys.stdout.write
        self.err_ = sys.stderr.write

    def main(self):
        n = self.in_().strip()

        b1 = int(self.in_().strip())
        while b1 < self.MINIMUM_BASE or b1 > self.MAXIMUM_BASE:
            self.err_("Invalid base! Please enter again.\n")
            self.out_("Enter beginning base: ")
            b1 = int(self.in_().strip())

        if not self.valid_for_base(n, b1):
            self.err_("The number is invalid for this base!\n")
            return

        b2 = int(self.in_().strip())
        while b2 < self.MINIMUM_BASE or b2 > self.MAXIMUM_BASE:
            self.err_("Invalid base! Please enter again.\n")
            self.out_("Enter end base: ")
            b2 = int(self.in_().strip())

        result = self.base2base(n, b1, b2)
        self.out_("Converted number: {}\n".format(result))

    def valid_for_base(self, n, base):
        valid_digits = [
            '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
            'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
            'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
            'U', 'V', 'W', 'X', 'Y', 'Z'
        ]
        digits_for_base = valid_digits[:base]

        digits_list = set(digits_for_base)

        for c in n.upper():
            if c not in digits_list:
                return False

        return True

    def base2base(self, n, b1, b2):
        decimal_value = 0
        output = []

        for char_b1 in n.upper():
            char_b2 = (ord(char_b1) - ord('A') + 10) if ord('A') <= ord(char_b1) <= ord('Z') else ord(char_b1) - ord('0')
            decimal_value = decimal_value * b1 + char_b2

        if decimal_value == 0:
            return "0"

        while decimal_value!= 0:
            remainder = decimal_value % b2
            output.insert(0, chr(remainder + ord('0') if remainder < 10 else remainder + ord('A') - 10))
            decimal_value //= b2

        return "".join(output)

if __name__ == "__main__":
    Main().main()

