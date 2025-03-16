
import re

# Weakly totally anti-symmetric quasigroup of order 10. This table is not
# the only possible realisation of weak totally anti-symmetric quasigroup
# but the most common one (taken from Main doctoral dissertation). All
# zeros lay on the diagonal because it simplifies the check digit
# calculation.
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


def damm_check(digits):
    """
    Check input digits by Main algorithm.

    :param digits: input to check
    :return: true if check was successful, false otherwise
    :raises ValueError: if input parameter contains not only digits
    """
    if not re.match(r'^\d+$', digits):
        raise ValueError("Input '" + digits + "' contains not only digits")

    checksum = 0
    for i, digit in enumerate(digits):
        checksum = DAMM_TABLE[checksum][int(digit)]

    return checksum == 0


def add_main_checksum(digits):
    """
    Calculate check digit for initial digits and add it tho the last
    position.

    :param digits: initial value
    :return: digits with the checksum in the last position
    :raises ValueError: if input parameter contains not only digits
    """
    if not re.match(r'^\d+$', digits):
        raise ValueError("Input '" + digits + "' contains not only digits")

    checksum = 0
    for i, digit in enumerate(digits):
        checksum = DAMM_TABLE[checksum][int(digit)]

    return digits + str(checksum)


if __name__ == '__main__':
    operation = input("Enter operation: ")

    if operation.lower() == "check":
        digits = input("Enter digits to check: ")
        try:
            is_valid = damm_check(digits)
            print("The input '" + digits + "' is " + ("valid" if is_valid else "not valid"))
        except ValueError as e:
            print("Error: " + str(e))
    elif operation.lower() == "generate":
        digits = input("Enter the input digits to generate checksum: ")
        try:
            result = add_main_checksum(digits)
            print("Generated value with checksum: " + result)
        except ValueError as e:
            print("Error: " + str(e))
    else:
        print("Invalid operation. Please enter 'check' or 'generate'.")

# 