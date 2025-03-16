
import sys

# Define a constant for infinity
INF = 1e15

# Create a Scanner object to read input
sc = sys.stdin

# Read the input number as a string
number = sc.readline ( )

# Create an array to store the digits of the number
digits = [ ]

# Convert the number into an array of digits
for i in range ( len ( number ) ):
    digits.append ( int ( number [ -1 - i ] ) )

# Initialize the total bill to 0
bills = 0

# Loop through each digit to calculate the total bill
for i in range ( len ( digits ) ):
    # Handle the case where the digit is 10
    if digits [ i ] == 10:
        digits [ i + 1 ] += 1
        digits [ i ] = 0

    # Add the digit to the bill if it is less than 5
    if digits [ i ] < 5:
        bills += digits [ i ]

    # Handle the case where the digit is 5
    elif digits [ i ] == 5:
        if digits [ i + 1 ] >= 5:
            digits [ i + 1 ] += 1
        bills += 5

    # Handle the case where the digit is greater than 5
    else:
        digits [ i + 1 ] += 1
        bills += 10 - digits [ i ]

# Print the total bill
print ( bills )

# END-OF-CODE
