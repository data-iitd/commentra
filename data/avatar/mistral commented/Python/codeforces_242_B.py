# Import necessary Python libraries
import os, sys, io, math

# Define lambda functions for reading input
I = lambda : [ * map ( int , sys.stdin.readline ( ).split ( ) ) ]
IS = lambda : input ( )
IN = lambda : int ( input ( ) )
IF = lambda : float ( input ( ) )

# Read the number of test cases
n = IN ( )

# Initialize id variable to 0
id = 0

# Read left and right boundary values for the first test case
l, r = map ( int , input ( ).split ( ) )

# Iterate through the remaining test cases
for i in range ( 1 , n ) :
    # Read left and right boundary values for the current test case
    li, ri = map ( int , input ( ).split ( ) )

    # Check if the current test case overlaps with the previously defined boundary values
    if li <= l and r <= ri :
        # Update id variable to the index of the current test case
        id = i

    # If the current test case does not overlap, keep id as n
    elif li < l or r < ri :
        id = n

    # Update boundary values based on the current test case
    l = min ( l , li )
    r = max ( r , ri )

# Print the index of the test case that satisfies the condition, or -1 if no such test case exists
print ( -1 if id == n else id + 1 )
