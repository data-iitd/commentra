
import sys

# DAMM_TABLE is used for the Main algorithm to validate and generate checksums.
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

# dammCheck method validates the input digits using the Main algorithm.
def dammCheck(digits):
    if not digits.isdigit():
        raise ValueError("Input '" + digits + "' contains not only digits")
    numbers = [int(i) for i in digits]
    checksum = 0
    for number in numbers:
        checksum = DAMM_TABLE[checksum][number]
    return checksum == 0

# addMainChecksum method adds a checksum to the input digits using the Main algorithm.
def addMainChecksum(initialDigits):
    if not initialDigits.isdigit():
        raise ValueError("Input '" + initialDigits + "' contains not only digits")
    numbers = [int(i) for i in initialDigits]
    checksum = 0
    for number in numbers:
        checksum = DAMM_TABLE[checksum][number]
    return initialDigits + str(checksum)

# main method is the entry point of the program.
def main():
    operation = input("Enter operation (check/generate): ")
    if operation.lower() == "check":
        digits = input("Enter digits to check: ")
        try:
            isValid = dammCheck(digits)
            print("The input '" + digits + "' is " + ("valid" if isValid else "not valid"))
        except Exception as e:
            print("Error: " + str(e))
    elif operation.lower() == "generate":
        digits = input("Enter digits to generate checksum: ")
        try:
            result = addMainChecksum(digits)
            print("Generated value with checksum: " + result)
        except Exception as e:
            print("Error: " + str(e))
    else:
        print("Invalid operation. Please enter 'check' or 'generate'.")

if __name__ == "__main__":
    main()

