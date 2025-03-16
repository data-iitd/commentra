
import re

# Main algorithm checksum lookup table
DAMM_TABLE = [
    [0, 3, 1, 7, 5, 9, 8, 6, 4, 2],
    [7, 0, 9, 2, 1, 5, 4, 8, 6, 3],
    [4, 2, 0, 6, 8, 7, 1, 3, 5, 9],
    [1, 7, 5, 0, 9, 8, 3, 4, 2, 6],
    [6, 1, 2, 3, 0, 4, 5, 9, 7, 8],
    [3, 6, 7, 4, 2, 0, 9, 5, 8, 1],
    [5, 8, 6, 9, 7, 2, 0, 1, 3, 4],
    [8, 9, 4, 5, 3, 6, 2, 0, 1, 7],
    [9, 4, 3, 8, 6, 1, 7, 2, 0, 5],
    [2, 5, 8, 1, 4, 3, 6, 7, 9, 0],
]

# Method to check if the input digits are valid according to the Main algorithm
def damm_check(digits):
    # Validate input format
    if not re.match(r"^\d+$", digits):
        raise ValueError("Input '" + digits + "' contains not only digits")
    # Convert input string to an integer array
    numbers = [int(digit) for digit in digits]
    checksum = 0

    # Calculate checksum using the Main table
    for number in numbers:
        checksum = DAMM_TABLE[checksum][number]
    # Return true if checksum is 0 (valid), false otherwise
    return checksum == 0

# Method to generate a checksum for the given initial digits
def add_main_checksum(initial_digits):
    # Validate input format
    if not re.match(r"^\d+$", initial_digits):
        raise ValueError("Input '" + initial_digits + "' contains not only digits")
    # Convert input string to an integer array
    numbers = [int(digit) for digit in initial_digits]
    checksum = 0

    # Calculate checksum using the Main table
    for number in numbers:
        checksum = DAMM_TABLE[checksum][number]
    # Return the original digits concatenated with the checksum
    return initial_digits + str(checksum)

# Main method to handle user input and execute operations
def main():
    # Read the operation type (check or generate)
    operation = input("Enter the operation type (check or generate): ")

    # Check operation: Validate input digits
    if operation.lower() == "check":
        # Read the digits to check
        digits = input("Enter the digits to check: ")
        try:
            # Validate the digits
            is_valid = damm_check(digits)
            # Output the result of the validation
            print("The input '" + digits + "' is " + ("valid" if is_valid else "not valid"))
        except ValueError as e:
            # Handle any exceptions that occur during validation
            print("Error: " + str(e))
    # Generate operation: Create a checksum for the input digits
    elif operation.lower() == "generate":
        # Read the digits to generate checksum
        digits = input("Enter the input digits to generate checksum: ")
        try:
            # Generate the checksum
            result = add_main_checksum(digits)
            # Output the result with the checksum
            print("Generated value with checksum: " + result)
        except ValueError as e:
            # Handle any exceptions that occur during checksum generation
            print("Error: " + str(e))
    else:
        # Handle invalid operation input
        print("Invalid operation. Please enter 'check' or 'generate'.")

if __name__ == "__main__":
    main()

