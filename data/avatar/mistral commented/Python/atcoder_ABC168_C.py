# Assign values to variables a, b, h, and m using the input function and map function
a, b, h, m = map(int, input().split())

# Import the math module for mathematical functions
import math

# Calculate the angle C between hour hand and minute hand
C = abs(360 / 60 * m - 360 / 12 * h - 360 / 12 / 60 * m)
if C > 180:
    # If angle C is greater than 180 degrees, subtract it from 360 to get the correct value
    C = 360 - C

# Calculate the cosine of angle C
cosC = math.cos(math.radians(C))

# Calculate and print the length of the side of the right triangle formed by the hour and minute hands
print(math.sqrt(a ** 2 + b ** 2 - 2 * a * b * cosC))