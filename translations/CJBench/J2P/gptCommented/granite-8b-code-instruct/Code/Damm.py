
import sys

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
    if not digits.isdigit():
        raise ValueError("Input '" + digits + "' contains not only digits")
    numbers = [int(i) for i in digits]
    checksum = 0
    for number in numbers:
        checksum = DAMM_TABLE[checksum][number]
    return checksum == 0

# Method to generate a checksum for the given initial digits
def add_main_checksum(initial_digits):
    if not initial_digits.isdigit():
        raise ValueError("Input '" + initial_digits + "' contains not only digits")
    numbers = [int(i) for i in initial_digits]
    checksum = 0
    for number in numbers:
        checksum = DAMM_TABLE[checksum][number]
    return initial_digits + str(checksum)

# Main method to handle user input and execute operations
def main():
    operation = input("Enter operation type (check or generate): ")
    if operation.lower() == "check":
        digits = input("Enter the digits to check: ")
        try:
            is_valid = damm_check(digits)
            print("The input '" + digits + "' is " + ("valid" if is_valid else "not valid"))
        except Exception as e:
            print("Error: " + str(e))
    elif operation.lower() == "generate":
        digits = input("Enter the input digits to generate checksum: ")
        try:
            result = add_main_checksum(digits)
            print("Generated value with checksum: " + result)
        except Exception as e:
            print("Error: " + str(e))
    else:
        print("Invalid operation. Please enter 'check' or 'generate'.")

if __name__ == "__main__":
    main()

