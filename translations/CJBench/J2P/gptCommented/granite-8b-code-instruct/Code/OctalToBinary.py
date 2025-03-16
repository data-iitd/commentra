
import sys

def convert_main(octal_number):
    binary_number = 0 # Variable to hold the resulting binary number
    digit_position = 1 # Variable to track the position of the binary digit

    # Loop until all digits of the octal number are processed
    while octal_number!= 0:
        # Extract the last digit of the octal number
        octal_digit = octal_number % 10
        # Convert the octal digit to its binary equivalent
        binary_digit = convert_octal_digit_to_binary(octal_digit)
        # Add the binary digit to the final binary number at the correct position
        binary_number += binary_digit * digit_position
        # Remove the last digit from the octal number
        octal_number //= 10
        # Update the position for the next binary digit (each octal digit corresponds to 3 binary digits)
        digit_position *= 1000

    return binary_number # Return the final binary number

def convert_octal_digit_to_binary(octal_digit):
    binary_digit = 0 # Variable to hold the resulting binary digit
    binary_multiplier = 1 # Variable to track the position of the binary digit

    # Loop until all bits of the octal digit are processed
    while octal_digit!= 0:
        # Get the remainder when dividing by 2 (to get the binary digit)
        octal_digit_remainder = octal_digit % 2
        # Add the binary digit to the result at the correct position
        binary_digit += octal_digit_remainder * binary_multiplier
        # Remove the last bit from the octal digit
        octal_digit //= 2
        # Update the position for the next binary digit
        binary_multiplier *= 10

    return binary_digit # Return the binary equivalent of the octal digit

# Main method to execute the program
if __name__ == "__main__":
    octal_number = int(input("Enter an octal number: ")) # Read the octal number from user input
    binary_number = convert_main(octal_number) # Convert the octal number to binary
    # Print the binary equivalent
    print("Binary equivalent:", binary_number)

