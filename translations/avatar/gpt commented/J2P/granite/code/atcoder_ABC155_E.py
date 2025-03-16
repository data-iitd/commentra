
import sys

# Define a constant for a large number (infinity) for potential use in calculations
INF = 10 ** 15

# Read the input number from the command line arguments
number = int(sys.argv[1])

# Initialize a variable to count the total number of bills
bills = 0

# Process each digit to calculate the total number of bills needed
while number > 0:
    # Handle carry over for digits equal to 10
    if number % 10 == 10:
        number //= 10
        number += 1
    # If the digit is less than 5, add it directly to the bills
    if number % 10 < 5:
        bills += number % 10
        number //= 10
    # If the digit is exactly 5, check the next digit for rounding
    elif number % 10 == 5:
        if number // 10 >= 5:
            number //= 10
            number += 1
        bills += 5
    # If the digit is greater than 5, round up to the next ten
    else:
        number //= 10
        number += 1
        bills += 10 - (number % 10)

# Output the total number of bills calculated
print(bills)

