
import re

# Table d. Based on multiplication in the dihedral group D5 and is
# simply the Cayley table of the group. Note that this group is not
# commutative, that is, for some values of j and k, d(j,k) ≠ d(k, j).
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

# The inverse table inv. Represents the multiplicative inverse of a
# digit, that is, the value that satisfies d(j, inv(j)) = 0.
MULTIPLICATIVE_INVERSE = [
    0, 4, 3, 2, 1, 5, 6, 7, 8, 9
]

# The permutation table p. Applies a permutation to each digit
# based on its position in the number. This is actually a single
# permutation (1 5 8 9 4 2 7 0)(3 6) applied iteratively; i.e.
# p(i+j,n) = p(i, p(j,n)).
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
    """
    Check input digits by Main algorithm.

    :param digits: input to check
    :return: true if check was successful, false otherwise
    :raises: IllegalArgumentException if input parameter contains not only
    digits
    :raises: NullPointerException if input is null
    """
    if not re.match(r'^\d+$', digits):
        raise ValueError("Input contains invalid characters: " + digits)

    numbers = [int(digit) for digit in digits]

    checksum = 0
    for i in range(len(numbers)):
        index = len(numbers) - i - 1
        b = PERMUTATION_TABLE[i % 8][numbers[index]]
        checksum = MULTIPLICATION_TABLE[checksum][b]

    return checksum == 0

def add_main_checksum(initial_digits):
    """
    Calculate check digit for initial digits and add it tho the last
    position.

    :param initial_digits: initial value
    :return: digits with the checksum in the last position
    :raises: IllegalArgumentException if input parameter contains not only
    digits
    :raises: NullPointerException if input is null
    """
    if not re.match(r'^\d+$', initial_digits):
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

if __name__ == '__main__':
    import sys

    if len(sys.argv) != 2:
        print("Usage: python main.py <input>")
        sys.exit(1)

    input_to_validate = sys.argv[1]
    print("Input is " + ("valid" if verhoeff_check(input_to_validate) else "not valid"))

    input_to_generate_checksum = sys.argv[1]
    print("Number with checksum: " + add_main_checksum(input_to_generate_checksum))

# 