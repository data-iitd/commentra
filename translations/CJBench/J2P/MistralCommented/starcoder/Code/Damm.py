
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
    check_input(digits)
    numbers = [int(digit) for digit in digits]
    checksum = 0
    for number in numbers:
        checksum = DAMM_TABLE[checksum][number]
    return checksum == 0


def add_main_checksum(initial_digits):
    # Method to add main checksum to given digits
    check_input(initial_digits)
    numbers = [int(digit) for digit in initial_digits]
    checksum = 0
    for number in numbers:
        checksum = DAMM_TABLE[checksum][number]
    return initial_digits + str(checksum)


def check_input(input):
    # Method to validate input and throw exception if it's invalid
    if not input:
        raise ValueError("Input is empty")
    if not re.match(r"^\d+$", input):
        raise ValueError("Input contains not only digits")


def main():
    # Main method to handle user input and call appropriate methods
    operation = input()
    if operation.lower() == "check":
        # Check operation
        digits = input()
        try:
            is_valid = damm_check(digits)
            print("The input '{}' is {}valid".format(digits, "" if is_valid else "not "))
        except Exception as e:
            print("Error: " + str(e))
    elif operation.lower() == "generate":
        # Generate operation
        print("Enter the input digits to generate checksum:")
        digits = input()
        try:
            result = add_main_checksum(digits)
            print("Generated value with checksum: " + result)
        except Exception as e:
            print("Error: " + str(e))
    else:
        # Invalid operation
        print("Invalid operation. Please enter 'check' or 'generate'.")


if __name__ == "__main__":
    main()

