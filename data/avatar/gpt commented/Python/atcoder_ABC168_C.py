# Read input values for hours (h), minutes (m), and lengths (a, b)
a, b, h, m = map(int, input().split())

# Import the math module for mathematical functions
import math

# Calculate the angle C between the hour and minute hands of the clock
# The formula calculates the absolute difference in degrees
C = abs(360 / 60 * m - 360 / 12 * h - 360 / 12 / 60 * m)

# If the angle is greater than 180 degrees, find the smaller angle
if C > 180:
    C = 360 - C

# Calculate the cosine of angle C in radians
cosC = math.cos(math.radians(C))

# Use the Law of Cosines to calculate the length of the third side of the triangle
# formed by the lengths a, b, and the angle C
print(math.sqrt(a ** 2 + b ** 2 - 2 * a * b * cosC))
