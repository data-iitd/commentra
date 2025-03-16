
import re

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

def check_input(input):
    if not re.match(r'^\d+$', input):
        raise ValueError('Input contains not only digits')

def to_int_array(string):
    return [int(i) for i in string]

def damm_check(digits):
    check_input(digits)
    numbers = to_int_array(digits)
    checksum = 0
    for number in numbers:
        checksum = DAMM_TABLE[checksum][number]
    return checksum == 0

def add_main_checksum(initial_digits):
    check_input(initial_digits)
    numbers = to_int_array(initial_digits)
    checksum = 0
    for number in numbers:
        checksum = DAMM_TABLE[checksum][number]
    return initial_digits + str(checksum)

def main():
    operation = input()
    if operation.lower() == 'check':
        digits = input()
        try:
            is_valid = damm_check(digits)
            print('The input \'{}\' is {}'.format(digits, 'valid' if is_valid else 'not valid'))
        except Exception as e:
            print('Error: {}'.format(e))
    elif operation.lower() == 'generate':
        print('Enter the input digits to generate checksum:')
        digits = input()
        try:
            result = add_main_checksum(digits)
            print('Generated value with checksum: {}'.format(result))
        except Exception as e:
            print('Error: {}'.format(e))
    else:
        print('Invalid operation. Please enter \'check\' or \'generate\'.')

if __name__ == '__main__':
    main()

