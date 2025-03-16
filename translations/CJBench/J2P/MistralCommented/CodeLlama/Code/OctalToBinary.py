
import math

def convert_main(octal_number):
    binary_number = 0
    digit_position = 1

    # Convert octal number to binary number
    while octal_number != 0:
        octal_digit = octal_number % 10
        binary_digit = convert_octal_digit_to_binary(octal_digit)
        binary_number += binary_digit * digit_position
        octal_number //= 10
        digit_position *= 1000

    return binary_number

def convert_octal_digit_to_binary(octal_digit):
    binary_digit = 0
    binary_multiplier = 1

    # Convert an octal digit to its binary equivalent
    while octal_digit != 0:
        octal_digit_remainder = octal_digit % 2
        binary_digit += octal_digit_remainder * binary_multiplier
        octal_digit //= 2
        binary_multiplier *= 10

    return binary_digit

def main():
    # Read an octal number from the console and convert it to binary number
    octal_number = int(input("Enter an octal number: "))
    binary_number = convert_main(octal_number)

    # Print the binary number to the console
    print("Binary equivalent:", binary_number)

if __name__ == "__main__":
    main()

