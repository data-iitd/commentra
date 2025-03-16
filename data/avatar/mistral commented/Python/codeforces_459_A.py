# Import the math module for calculating the square root
import math

# Get user input and convert it to a list of integers
given = input("")
l1 = given.split()
l1 = [int(x) for x in l1]

# Assign the first two elements of the list to x1, y1 and the last two elements to x2, y2
x1, y1 = l1[0], l1[1]
x2, y2 = l1[2], l1[3]

# Calculate the denominator and numerator of the slope
denominator = x2 - x1
numerator = y2 - y1

# Check if the denominator is zero
if denominator == 0:
    # Calculate the distance between the two points and print the result
    d = int(math.sqrt((x2 - x1) ** 2 + (y2 - y1) ** 2))
    x4, x3, y3, y4 = x1, x2, y2 + d, y1 + d
    print(f"{x3} {y3} {x4} {y4}")

# If the denominator is not zero, calculate the quotient
elif denominator != 0:
    quotient = numerator / denominator

# Check if the quotient is equal to 1 or -1
if quotient == 1 or quotient == -1:
    # Swap the x and y coordinates of the two points and print the result
    if quotient == 1:
        x4, x3, y3, y4 = x2, x1, y1, y2
    else:
        x4, x3, y3, y4 = x1, x2, y2, y1
    print(f"{x3} {y3} {x4} {y4}")

# If the quotient is not 1 or -1, print -1
else:
    print("-1")
