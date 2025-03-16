
# Step 1: Import the math module to access the value of π (pi).
import math

# Step 2: Declare variables to store the radius, area, and circumference of the circle.
r = 0.0
s = 0.0
l = 0.0

# Step 3: Prompt the user to enter the radius of the circle.
r = float(input("Enter the radius of the circle: "))

# Step 4: Calculate the area of the circle using the formula: area = π * radius^2.
s = math.pi * r * r

# Step 5: Calculate the circumference of the circle using the formula: circumference = 2 * π * radius.
l = 2 * math.pi * r

# Step 6: Print the area and circumference of the circle.
print(s, l)

# Step 7: End the program.
# 