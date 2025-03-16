

import re

DAMM_TABLE = [
    # Main table for checksum calculation
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

def damm_check(digits):
    # Method to check if given digits form a valid Main number
    if not re.match(r'\d+$', digits):
        raise ValueError("Input contains not only digits")
    numbers = [int(i) for i in digits]
    checksum = 0
    for number in numbers:
        checksum = DAMM_TABLE[checksum][number]
    return checksum == 0

def add_main_checksum(initial_digits):
    # Method to add main checksum to given digits
    if not re.match(r'\d+$', initial_digits):
        raise ValueError("Input contains not only digits")
    numbers = [int(i) for i in initial_digits]
    checksum = 0
    for number in numbers:
        checksum = DAMM_TABLE[checksum][number]
    return initial_digits + str(checksum)

if __name__ == "__main__":
    # Main method to handle user input and call appropriate methods
    operation = input("Enter operation (check/generate): ")
    if operation.lower() == "check":
        # Check operation
        digits = input("Enter digits to check: ")
        try:
            is_valid = damm_check(digits)
            print(f"The input '{digits}' is {'valid' if is_valid else 'not valid'}")
        except ValueError as e:
            print(f"Error: {e}")
    elif operation.lower() == "generate":
        # Generate operation
        print("Enter the input digits to generate checksum:")
        digits = input()
        try:
            result = add_main_checksum(digits)
            print(f"Generated value with checksum: {result}")
        except ValueError as e:
            print(f"Error: {e}")
    else:
        # Invalid operation
        print("Invalid operation. Please enter 'check' or 'generate'.")

