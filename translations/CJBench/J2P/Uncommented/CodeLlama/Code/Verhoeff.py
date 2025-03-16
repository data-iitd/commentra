
import re

def verhoeff_check(digits):
    if not re.match(r'^\d+$', digits):
        raise ValueError('Input contains invalid characters: ' + digits)
    numbers = [int(digit) for digit in digits]
    checksum = 0
    for i in range(len(numbers)):
        index = len(numbers) - i - 1
        b = PERMUTATION_TABLE[i % 8][numbers[index]]
        checksum = MULTIPLICATION_TABLE[checksum][b]
    return checksum == 0

def add_main_checksum(initial_digits):
    if not re.match(r'^\d+$', initial_digits):
        raise ValueError('Input contains invalid characters: ' + initial_digits)
    modified_digits = initial_digits + '0'
    numbers = [int(digit) for digit in modified_digits]
    checksum = 0
    for i in range(len(numbers)):
        index = len(numbers) - i - 1
        b = PERMUTATION_TABLE[i % 8][numbers[index]]
        checksum = MULTIPLICATION_TABLE[checksum][b]
    checksum = MULTIPLICATIVE_INVERSE[checksum]
    return initial_digits + str(checksum)

# 