# Import the math module and specifically the prod function
from math import prod

# Read the input from the standard input
a = input()

# Check if the string contains any '1' character
if a.count("1") == 0:
    # If it doesn't, print 0 and exit the program
    print(0)
    exit()

# If the string contains at least one '1' character, we proceed to calculate the product of the number of zeros in each segment between consecutive '1' characters
product_of_zeros = prod([int(i.count("0") + 1) for i in a.strip("0 ").split("1")])

# Finally, print the result
print(product_of_zeros)
