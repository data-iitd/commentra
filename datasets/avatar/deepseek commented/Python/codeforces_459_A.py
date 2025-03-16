
import math

# Step 1: Take input from the user and split it into a list of integers
given = input("")
l1 = given.split()
l1 = [int(x) for x in l1]

# Step 2: Assign the values to variables x1, y1, x2, and y2
x1 = l1[0]
y1 = l1[1]
x2 = l1[2]
y2 = l1[3]

# Step 3: Check if the denominator is not zero to calculate the quotient
denominator = x2 - x1
numerator = y2 - y1
if denominator != 0:
    quotient = numerator / denominator

# Step 4: If the numerator is zero, calculate the distance and print the coordinates of two points
if numerator == 0:
    d = int(math.sqrt((x2 - x1) ** 2 + (y2 - y1) ** 2))
    x4 = x1
    x3 = x2
    y3 = y2 + d
    y4 = y1 + d
    print(f"{x3} {y3} {x4} {y4}")

# Step 5: If the denominator is zero, print the coordinates of two points based on the distance calculated
elif denominator == 0:
    y4 = y2
    y3 = y1
    d = int(math.sqrt((x2 - x1) ** 2 + (y2 - y1) ** 2))
    x4 = x1 + d
    x3 = x2 + d
    print(f"{x3} {y3} {x4} {y4}")

# Step 6: If the quotient is 1 or -1, swap the coordinates and print them
elif quotient == 1:
    x4 = x2
    x3 = x1
    y4 = y1
    y3 = y2
    print(f"{x3} {y3} {x4} {y4}")
elif quotient == -1:
    x4 = x1
    x3 = x2
    y4 = y2
    y3 = y1
    print(f"{x3} {y3} {x4} {y4}")

# Step 7: If none of the above conditions are met, print -1
else:
    print('-1')