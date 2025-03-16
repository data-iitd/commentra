
import sys

# Initializes the scanner and reads an integer from the standard input
scanner = sys.stdin
number = int(scanner.readline())
scanner.close()

# Checks if the input number is valid
if number < 0:
    raise ValueError("Number must be non-negative.")

# Computes the lowest base palindrome for the given number
base = 2
while not is_palindromic_in_base(number, base):
    base += 1

# Prints the result to the standard output
print(base)

# Checks if a list of integers is a palindrome
def is_palindromic(list):
    size = len(list)

    # Checks if the list has an odd length, which means it cannot be a palindrome
    if size % 2!= 0:
        return False

    # Compares the first and last elements of the list and moves towards the middle
    for i in range(size // 2):
        if list[i]!= list[size - 1 - i]:
            return False

    # Returns true if the list is a palindrome
    return True

# Checks if a number is a palindrome in a given base
def is_palindromic_in_base(number, base):
    # Returns true if the number is less than or equal to 1, as these numbers are palindromes in any base
    if number <= 1:
        return True

    # Checks if the number is a multiple of the base, which means it cannot be a palindrome in this base
    if number % base == 0:
        return False

    # Computes the digits of the number in the given base and checks if the list is a palindrome
    digits = compute_digits_in_base(number, base)
    return is_palindromic(digits)

# Computes the digits of a number in a given base and returns them as a list
def compute_digits_in_base(number, base):
    # Initializes an empty list to store the digits
    digits = []

    # Computes the digits of the number in the given base and adds them to the list
    while number > 0:
        digits.append(number % base)
        number //= base

    # Returns the list of digits
    return digits

# 