import sys

# Constants for minimum and maximum base values
MINIMUM_BASE = 2
MAXIMUM_BASE = 36

def valid_for_base(n, base):
    # Define valid digits for bases up to 36
    valid_digits = '0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    
    # Create a set of valid digits for the specified base
    digits_for_base = set(valid_digits[:base])
    
    # Check if each character in the number is valid for the base
    for c in n.upper():
        if c not in digits_for_base:
            return False  # Return false if an invalid character is found
    return True  # Return true if all characters are valid

def base_to_base(n, b1, b2):
    decimal_value = 0  # Variable to hold the decimal value
    output = []  # List to build the output

    # Convert the number from base b1 to decimal
    for char_b1 in n.upper():
        # Convert character to its integer value based on the base
        char_b2 = 10 + (ord(char_b1) - ord('A')) if 'A' <= char_b1 <= 'Z' else int(char_b1)
        decimal_value = decimal_value * b1 + char_b2  # Update decimal value

    # Handle the case where the number is zero
    if decimal_value == 0:
        return "0"  # Return "0" if the decimal value is zero

    # Convert the decimal value to the target base b2
    while decimal_value != 0:
        remainder = decimal_value % b2  # Get the remainder
        # Convert remainder to the appropriate character and insert at the beginning
        output.insert(0, chr(remainder + ord('0')) if remainder < 10 else chr(remainder - 10 + ord('A')))
        decimal_value //= b2  # Update decimal value for the next iteration

    return ''.join(output)  # Return the final converted number

def main():
    # Read the number to be converted
    n = input()
    
    # Read the source base and validate it
    b1 = int(input())
    while b1 < MINIMUM_BASE or b1 > MAXIMUM_BASE:
        print("Invalid base! Please enter again.")
        b1 = int(input())

    # Validate the number for the specified source base
    if not valid_for_base(n, b1):
        print("The number is invalid for this base!")
        return  # Exit if the number is invalid

    # Read the target base and validate it
    b2 = int(input())
    while b2 < MINIMUM_BASE or b2 > MAXIMUM_BASE:
        print("Invalid base! Please enter again.")
        b2 = int(input())

    # Convert the number from base b1 to base b2
    result = base_to_base(n, b1, b2)
    
    # Output the converted number
    print("Converted number:", result)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
