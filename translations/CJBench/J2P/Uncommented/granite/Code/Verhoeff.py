

import sys
MULTIPLICATION_TABLE = [
    [0, 1, 2, 3, 4, 5, 6, 7, 8, 9],
    [1, 2, 3, 4, 0, 6, 7, 8, 9, 5],
    [2, 3, 4, 0, 1, 7, 8, 9, 5, 6],
    [3, 4, 0, 1, 2, 8, 9, 5, 6, 7],
    [4, 0, 1, 2, 3, 9, 5, 6, 7, 8],
    [5, 9, 8, 7, 6, 0, 4, 3, 2, 1],
    [6, 5, 9, 8, 7, 1, 0, 4, 3, 2],
    [7, 6, 5, 9, 8, 2, 1, 0, 4, 3],
    [8, 7, 6, 5, 9, 3, 2, 1, 0, 4],
    [9, 8, 7, 6, 5, 4, 3, 2, 1, 0]
]
MULTIPLICATIVE_INVERSE = [
    0, 4, 3, 2, 1, 5, 6, 7, 8, 9
]
PERMUTATION_TABLE = [
    [0, 1, 2, 3, 4, 5, 6, 7, 8, 9],
    [1, 5, 7, 6, 2, 8, 3, 0, 9, 4],
    [5, 8, 0, 3, 7, 9, 6, 1, 4, 2],
    [8, 9, 1, 6, 0, 4, 3, 5, 2, 7],
    [9, 4, 5, 3, 1, 2, 6, 8, 7, 0],
    [4, 2, 8, 6, 5, 7, 3, 9, 0, 1],
    [2, 7, 9, 3, 8, 0, 6, 4, 1, 5],
    [7, 0, 4, 6, 9, 1, 3, 2, 5, 8]
]
def verhoeff_check(digits):
    if not digits.isdigit():
        raise ValueError("Input contains invalid characters: " + digits)
    numbers = [int(digit) for digit in digits]
    checksum = 0
    for i in range(len(numbers)):
        index = len(numbers) - i - 1
        b = PERMUTATION_TABLE[i % 8][numbers[index]]
        checksum = MULTIPLICATION_TABLE[checksum][b]
    return checksum == 0
def add_main_checksum(initial_digits):
    if not initial_digits.isdigit():
        raise ValueError("Input contains invalid characters: " + initial_digits)
    modified_digits = initial_digits + "0"
    numbers = [int(digit) for digit in modified_digits]
    checksum = 0
    for i in range(len(numbers)):
        index = len(numbers) - i - 1
        b = PERMUTATION_TABLE[i % 8][numbers[index]]
        checksum = MULTIPLICATION_TABLE[checksum][b]
    checksum = MULTIPLICATIVE_INVERSE[checksum]
    return initial_digits + str(checksum)
if __name__ == "__main__":
    input_to_validate = input("Enter a number to validate: ")
    print("Input is " + ("valid" if verhoeff_check(input_to_validate) else "not valid"))
    input_to_generate_checksum = input("Enter a number to generate a checksum: ")
    print("Number with checksum: " + add_main_checksum(input_to_generate_checksum))
