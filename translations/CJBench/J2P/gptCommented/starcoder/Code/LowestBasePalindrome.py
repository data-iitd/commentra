import sys

# Private function to prevent instantiation
def __init__(self):
    pass

# Function to read an integer input from the user
def read_int():
    return int(raw_input())

# Function to read a list of integers input from the user
def read_list_int():
    return map(int, raw_input().split())

# Function to compute the digits of a number in a given base
def compute_digits_in_base(number, base):
    # Validate the input number and base
    if number < 0:
        raise ValueError("Number must be non-negative.")
    if base <= 1:
        raise ValueError("Base must be greater than 1.")
    
    # List to store the digits of the number in the specified base
    digits = []
    
    # Convert the number to the specified base and store the digits
    while number > 0:
        digits.append(number % base)
        number /= base
    
    # Return the list of digits
    return digits

# Function to check if a list of integers is palindromic
def is_palindromic(list):
    size = len(list)
    
    # Compare elements from the start and end of the list
    for i in range(size / 2):
        if list[i]!= list[size - 1 - i]:
            return False # Not a palindrome
    
    # If all comparisons passed, it is a palindrome
    return True

# Function to check if a number is palindromic in a given base
def is_palindromic_in_base(number, base):
    # Validate the input number and base
    if number < 0:
        raise ValueError("Number must be non-negative.")
    if base <= 1:
        raise ValueError("Base must be greater than 1.")
    
    # Numbers 0 and 1 are palindromic in any base
    if number <= 1:
        return True
    
    # If the number is divisible by the base, it cannot be a palindrome
    if number % base == 0:
        return False
    
    # Check if the digits of the number in the specified base form a palindrome
    return is_palindromic(compute_digits_in_base(number, base))

# Function to find the lowest base in which the number is a palindrome
def lowest_base_palindrome(number):
    # Validate the input number
    if number < 0:
        raise ValueError("Number must be non-negative.")
    
    # Start checking from base 2
    base = 2
    
    # Increment the base until a palindromic representation is found
    while not is_palindromic_in_base(number, base):
        base += 1
    
    # Return the lowest base found
    return base

# Main execution
if __name__ == "__main__":
    # Read an integer input from the user
    number = read_int()
    
    # Find the lowest base in which the number is a palindrome
    base = lowest_base_palindrome(number)
    
    # Output the result
    print base

# 