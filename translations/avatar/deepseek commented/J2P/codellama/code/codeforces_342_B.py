
import sys

# Read the input and split it into an array of strings
input = sys.stdin.readline ( ).split ( " " )

# Parse the required integers from the input
m = int ( input [ 1 ] )
s = int ( input [ 2 ] )
f = int ( input [ 3 ] )

# Initialize the maximum time and a dictionary to store the intervals
maxT = - 1
map = { }

# Read the intervals from the input and store them in the dictionary
while m > 0:
    mth = sys.stdin.readline ( ).split ( " " )
    k = int ( mth [ 0 ] )
    map [ k ] = [ int ( mth [ 1 ] ), int ( mth [ 2 ] ) ]
    maxT = max ( maxT, k )
    m -= 1

# Initialize a string to build the sequence of actions
actions = ""

# Determine the direction of movement and initialize the current position
M = "R" if s < f else "L"
d = 1 if s < f else - 1
cur = s

# Variables to store the current interval's start and end
a = - 1
b = - 1

# Build the sequence of actions based on the intervals and the current position
for t in range ( 1, maxT + 1 ):
    if t in map:
        a = map [ t ][ 0 ]
        b = map [ t ][ 1 ]
    if t in map and ( ( cur >= a and cur <= b ) or ( cur + d >= a and cur + d <= b ) ):
        actions += "X"
    else:
        actions += M
        cur += d
    if cur == f:
        break

# Continue moving in the determined direction until reaching the final position
while cur != f:
    actions += M
    cur += d

# Print the sequence of actions
print ( actions )

