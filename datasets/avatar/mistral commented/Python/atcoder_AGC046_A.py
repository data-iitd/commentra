
# Import the math module and specifically the gcd function
from math import gcd

# Ask the user for an integer input and assign it to the variable x
x = int( input() )

# Calculate the greatest common divisor (gcd) of 360 and the user input x
gcd_value = gcd( 360 , x )

# Print the result of the division of 360 by the gcd
print( 360 // gcd_value )