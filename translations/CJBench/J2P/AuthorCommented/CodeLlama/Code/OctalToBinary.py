
# A utility class to convert an octal (base-8) number into its binary (base-2) representation.
#
# This class provides methods to:
#   - Convert an octal number to its binary equivalent
#   - Convert individual octal digits to binary
#
# @author Bama Charan Chhandogi

class Main:

    # Converts an octal number to its binary representation.
    #
    # @param octalNumber the octal number to convert (non-negative integer)
    # @return the binary equivalent as a long
    @staticmethod
    def convert_main(octal_number):
        binary_number = 0
        digit_position = 1

        while octal_number != 0:
            octal_digit = octal_number % 10
            binary_digit = Main.convert_octal_digit_to_binary(octal_digit)

            binary_number += binary_digit * digit_position

            octal_number //= 10
            digit_position *= 1000

        return binary_number

    # Converts a single octal digit (0-7) to its binary equivalent.
    #
    # @param octalDigit a single octal digit (0-7)
    # @return the binary equivalent as a long
    @staticmethod
    def convert_octal_digit_to_binary(octal_digit):
        binary_digit = 0
        binary_multiplier = 1

        while octal_digit != 0:
            octal_digit_remainder = octal_digit % 2
            binary_digit += octal_digit_remainder * binary_multiplier

            octal_digit //= 2
            binary_multiplier *= 10

        return binary_digit

    # Main method to take user input and perform octal-to-binary conversion.
    @staticmethod
    def main():
        octal_number = int(input("Enter an octal number: "))

        binary_number = Main.convert_main(octal_number)

        print("Binary equivalent:", binary_number)


if __name__ == "__main__":
    Main.main()

