

import sys

# Read the first line of input, split by spaces, and store in an array of strings
str = input ( ).split ( " " )

# Read the next line of input as integers and store in an array
a, b = map ( int, input ( ).split ( " " ) )

# Read another string from the input
u = input ( )

# Check if the read string is equal to the first element of the array and print accordingly
print ( ( u == str [ 0 ] ) and ( a - 1 ) or a, ( b - 1 ) or b )

