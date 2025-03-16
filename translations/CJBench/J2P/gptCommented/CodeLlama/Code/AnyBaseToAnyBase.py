
# Import the necessary libraries
import sys

# Define the valid digits for bases up to 36
validDigits = [
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
    'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
    'U', 'V', 'W', 'X', 'Y', 'Z'
]

# Define the minimum and maximum base values
MINIMUM_BASE = 2
MAXIMUM_BASE = 36

# Define the main function
def main():
    # Read the number to be converted
    n = input()
    
    # Read the source base and validate it
    b1 = int(input())
    while b1 < MINIMUM_BASE or b1 > MAXIMUM_BASE:
        print("Invalid base! Please enter again.")
        b1 = int(input())

    # Validate the number for the specified source base
    if not validForBase(n, b1):
        print("The number is invalid for this base!")
        return # Exit if the number is invalid

    # Read the target base and validate it
    b2 = int(input())
    while b2 < MINIMUM_BASE or b2 > MAXIMUM_BASE:
        print("Invalid base! Please enter again.")
        b2 = int(input())

    # Convert the number from base b1 to base b2
    result = base2base(n, b1, b2)
    
    # Output the converted number
    print("Converted number: " + result)

# Method to validate if the number is valid for the given base
def validForBase(n, base):
    # Create an array of valid digits for the specified base
    digitsForBase = validDigits[:base]
    
    # Use a set for quick lookup of valid digits
    digitsList = set(digitsForBase)

    # Check if each character in the number is valid for the base
    for charB1 in n.upper():
        if charB1 not in digitsList:
            return False # Return false if an invalid character is found
    return True # Return true if all characters are valid

# Method to convert a number from base b1 to base b2
def base2base(n, b1, b2):
    decimalValue = 0 # Variable to hold the decimal value
    output = "" # String to build the output

    # Convert the number from base b1 to decimal
    for charB1 in n.upper():
        # Convert character to its integer value based on the base
        charB2 = ord(charB1) - ord('0') if charB1 >= '0' and charB1 <= '9' else ord(charB1) - ord('A') + 10
        decimalValue = decimalValue * b1 + charB2 # Update decimal value

    # Handle the case where the number is zero
    if decimalValue == 0:
        return "0" # Return "0" if the decimal value is zero

    # Convert the decimal value to the target base b2
    while decimalValue != 0:
        remainder = decimalValue % b2 # Get the remainder
        # Convert remainder to the appropriate character and insert at the beginning
        output = chr(ord('0') + remainder if remainder < 10 else ord('A') + remainder - 10) + output
        decimalValue //= b2 # Update decimal value for the next iteration
    return output # Return the final converted number

# Call the main function
main()

# END-OF-CODE
