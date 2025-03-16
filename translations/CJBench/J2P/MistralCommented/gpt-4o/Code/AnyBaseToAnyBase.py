class BaseConverter:
    MINIMUM_BASE = 2  # Minimum base allowed for conversion
    MAXIMUM_BASE = 36  # Maximum base allowed for conversion

    @staticmethod
    def valid_for_base(n, base):
        valid_digits = '0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ'  # Define valid digits for all bases
        digits_for_base = valid_digits[:base]  # Extract valid digits for the given base

        for c in n.upper():  # Iterate through each character in the number (ignoring case)
            if c not in digits_for_base:  # Check if the character is a valid digit for the given base
                return False  # If not, return false
        return True  # If all characters are valid digits, return true

    @staticmethod
    def base_to_base(n, b1, b2):
        decimal_value = 0  # Initialize decimal_value to 0
        output = []  # Initialize an empty list to store the result

        for char_b1 in n.upper():  # Iterate through each character in the number (ignoring case)
            if 'A' <= char_b1 <= 'Z':  # If the character is a letter, convert it to its decimal value
                char_b2 = 10 + (ord(char_b1) - ord('A'))
            else:  # If the character is a digit
                char_b2 = ord(char_b1) - ord('0')

            decimal_value = decimal_value * b1 + char_b2  # Update decimal_value

        if decimal_value == 0:  # If the decimal_value is 0, the result is '0'
            return "0"

        while decimal_value != 0:  # While the decimal_value is not 0
            remainder = decimal_value % b2  # Calculate the remainder
            if remainder < 10:
                output.append(chr(ord('0') + remainder))  # Add corresponding digit in the new base (b2)
            else:
                output.append(chr(ord('A') + (remainder - 10)))  # Add corresponding letter in the new base (b2)
            decimal_value //= b2  # Update decimal_value

        output.reverse()  # Reverse the output list to get the correct order
        return ''.join(output)  # Return the converted number as a string

def main():
    n = input()  # Read the first line (number to be converted) from the console
    b1 = int(input())  # Read the first base from the console

    # Check if the first base is within the allowed range
    while b1 < BaseConverter.MINIMUM_BASE or b1 > BaseConverter.MAXIMUM_BASE:
        print("Invalid base! Please enter again.")  # Print error message and ask for a valid base
        b1 = int(input())  # Read the base again

    if not BaseConverter.valid_for_base(n, b1):  # Check if the number is valid for the given base
        print("The number is invalid for this base!")  # Print error message and exit the program
        return

    b2 = int(input())  # Read the second base from the console

    # Check if the second base is within the allowed range
    while b2 < BaseConverter.MINIMUM_BASE or b2 > BaseConverter.MAXIMUM_BASE:
        print("Invalid base! Please enter again.")  # Print error message and ask for a valid base
        b2 = int(input())  # Read the base again

    result = BaseConverter.base_to_base(n, b1, b2)  # Convert the number from base b1 to base b2
    print("Converted number:", result)  # Print the converted number

if __name__ == "__main__":
    main()  # Run the main function

# <END-OF-CODE>
