
import re

def damm_check(digits):
    if not re.match(r'^\d+$', digits):
        raise ValueError('Input contains not only digits')
    numbers = [int(digit) for digit in digits]
    checksum = 0
    for number in numbers:
        checksum = DAMM_TABLE[checksum][number]
    return checksum == 0

def add_main_checksum(initial_digits):
    if not re.match(r'^\d+$', initial_digits):
        raise ValueError('Input contains not only digits')
    numbers = [int(digit) for digit in initial_digits]
    checksum = 0
    for number in numbers:
        checksum = DAMM_TABLE[checksum][number]
    return initial_digits + str(checksum)

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

if __name__ == '__main__':
    operation = input('Enter operation (check/generate): ').strip().lower()
    if operation == 'check':
        digits = input('Enter digits: ').strip()
        try:
            is_valid = damm_check(digits)
            print('The input \'{}\' is {}valid'.format(digits, '' if is_valid else 'not '))
        except ValueError as e:
            print('Error: {}'.format(e))
    elif operation == 'generate':
        initial_digits = input('Enter initial digits: ').strip()
        try:
            result = add_main_checksum(initial_digits)
            print('Generated value with checksum: {}'.format(result))
        except ValueError as e:
            print('Error: {}'.format(e))
    else:
        print('Invalid operation. Please enter \'check\' or \'generate\'.')

