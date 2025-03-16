
# Converts an octal number to a binary number.
def convert_main(octal_number):
    binary_number = 0
    digit_position = 1
    while octal_number!= 0:
        octal_digit = octal_number % 10
        binary_digit = convert_octal_digit_to_binary(octal_digit)
        binary_number += binary_digit * digit_position
        octal_number //= 10
        digit_position *= 1000
    return binary_number


# Converts a single octal digit to a binary digit.
def convert_octal_digit_to_binary(octal_digit):
    binary_digit = 0
    binary_multiplier = 1
    while octal_digit!= 0:
        octal_digit_remainder = octal_digit % 2
        binary_digit += octal_digit_remainder * binary_multiplier
        octal_digit //= 2
        binary_multiplier *= 10
    return binary_digit


# Entry point of the program.
def main():
    octal_number = int(input())
    binary_number = convert_main(octal_number)
    print("Binary equivalent: " + str(binary_number))


if __name__ == "__main__":
    main()

