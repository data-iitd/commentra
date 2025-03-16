class Main:
    @staticmethod
    def convert_main(octal_number):
        binary_number = 0  # Initialize binary_number to 0
        digit_position = 1  # Initialize digit_position to 1

        # Convert octal number to binary number
        while octal_number != 0:
            octal_digit = octal_number % 10  # Get the last digit of the octal number
            binary_digit = Main.convert_octal_digit_to_binary(octal_digit)  # Convert the octal digit to binary digit
            binary_number += binary_digit * digit_position  # Add the binary digit to the binary number with its weight
            octal_number //= 10  # Remove the last digit from the octal number
            digit_position *= 1000  # Multiply the weight of the next digit by 1000

        return binary_number  # Return the binary number

    @staticmethod
    def convert_octal_digit_to_binary(octal_digit):
        binary_digit = 0  # Initialize binary_digit to 0
        binary_multiplier = 1  # Initialize binary_multiplier to 1

        # Convert an octal digit to its binary equivalent
        while octal_digit != 0:
            octal_digit_remainder = octal_digit % 2  # Get the last bit of the octal digit
            binary_digit += octal_digit_remainder * binary_multiplier  # Add the bit to the binary digit with its weight
            octal_digit //= 2  # Remove the last bit from the octal digit
            binary_multiplier *= 10  # Multiply the weight of the next bit by 10

        return binary_digit  # Return the binary digit

if __name__ == "__main__":
    octal_number = int(input("Enter an octal number: "))  # Read an octal number from the console
    binary_number = Main.convert_main(octal_number)  # Convert octal number to binary number

    # Print the binary number to the console
    print("Binary equivalent:", binary_number)

# <END-OF-CODE>
