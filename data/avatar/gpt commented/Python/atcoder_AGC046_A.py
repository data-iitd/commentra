# Import the gcd function from the math module to calculate the greatest common divisor
from math import gcd

# Take an integer input from the user
x = int(input())

# Calculate and print the number of equal parts in a full circle (360 degrees) 
# that can be formed with the given angle x using the gcd
print(360 // gcd(360, x))
