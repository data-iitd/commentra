
import os , sys , io , math
from tokenize import Triple
from math import *

# Define functions to read input efficiently
I = lambda : [ * map ( int , sys.stdin.readline ( ).split ( ) ) ]
IS = lambda : input ( )
IN = lambda : int ( input ( ) )
IF = lambda : float ( input ( ) )

# Read the number of elements
n = IN ( )

# Initialize variables to track the best candidate interval
id = 0
l , r = map ( int , input ( ).split ( ) )

# Process each interval
for i in range ( 1 , n ) :
    li , ri = map ( int , input ( ).split ( ) )
    # Check if the current interval completely covers the best candidate interval
    if li <= l and r <= ri : id = i
    # Check if the current interval overlaps with the best candidate interval
    elif li < l or r < ri : id = n
    # Update the boundaries of the best candidate interval
    l = min ( l , li )
    r = max ( r , ri )

# Output the result
print ( - 1 if id == n else id + 1 )

