
import sys

def check_base(base):
    if base <= 1:
        raise ValueError("Base must be greater than 1.")

def check_number(number):
    if number < 0:
        raise ValueError("Number must be non-negative.")

def compute_digits_in_base(number, base):
    # Validate the input number and base
    check_number(number)
    check_base(base)

    # List to store the digits of the number in the specified base
    digits = []

    # Convert the number to the specified base and store the digits
    while number > 0:
        digits.append(number % base)
        number //= base

    # Return the list of digits
    return digits

def is_palindromic(list):
    size = len(list)

    # Compare elements from the start and end of the list
    for i in range(size // 2):
        if list[i]!= list[size - 1 - i]:
            return False # Not a palindrome

    # If all comparisons passed, it is a palindrome
    return True

def is_palindromic_in_base(number, base):
    # Validate the input number and base
    check_number(number)
    check_base(base)

    # Numbers 0 and 1 are palindromic in any base
    if number <= 1:
        return True

    # If the number is divisible by the base, it cannot be a palindrome
    if number % base == 0:
        return False

    # Check if the digits of the number in the specified base form a palindrome
    return is_palindromic(compute_digits_in_base(number, base))

def lowest_base_palindrome(number):
    # Validate the input number
    check_number(number)

    # Start checking from base 2
    base = 2

    # Increment the base until a palindromic representation is found
    while not is_palindromic_in_base(number, base):
        base += 1

    # Return the lowest base found
    return base

if __name__ == "__main__":
    # Read an integer input from the user
    number = int(input())

    # Find the lowest base in which the number is a palindrome
    base = lowest_base_palindrome(number)

    # Output the result
    print(base)

