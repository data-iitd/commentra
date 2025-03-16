
# A utility class to convert an octal (base-8) number into its binary (base-2) representation.
#
# This class provides methods to:
# - Convert an octal number to its binary equivalent
# - Convert individual octal digits to binary
#
# @author <NAME>

class Main:

    @staticmethod
    def convert_main(octal_number):
        binary_number = 0
        digit_position = 1

        while octal_number!= 0:
            octal_digit = octal_number % 10
            binary_digit = Main.convert_octal_digit_to_binary(octal_digit)

            binary_number += binary_digit * digit_position

            octal_number //= 10
            digit_position *= 1000

        return binary_number

    @staticmethod
    def convert_octal_digit_to_binary(octal_digit):
        binary_digit = 0
        binary_multiplier = 1

        while octal_digit!= 0:
            octal_digit_remainder = octal_digit % 2
            binary_digit += octal_digit_remainder * binary_multiplier

            octal_digit //= 2
            binary_multiplier *= 10

        return binary_digit

    @staticmethod
    def main():
        octal_number = int(input())

        binary_number = Main.convert_main(octal_number)

        print("Binary equivalent: " + str(binary_number))


