
import math
import sys

# Reading the number of elements in the arrays
n = int ( sys.stdin.readline ( ) )

# Creating an ArrayList to store the first array elements
a = [ ]

# Creating an ArrayList to store the second array elements
b = [ ]

# Initializing left and right variables to store the minimum and maximum elements respectively
left = math.inf
right = - math.inf

# Reading the elements of the arrays and updating the minimum and maximum elements
for i in range ( n ) :
    a.append ( int ( sys.stdin.readline ( ) ) )
    b.append ( int ( sys.stdin.readline ( ) ) )
    left = min ( left , a [ i ] )
    right = max ( right , b [ i ] )

# Checking if there is an element that has the same minimum and maximum value in both arrays
for i in range ( n ) :
    if left == a [ i ] and right == b [ i ] :
        # If true, printing the index of the element
        print ( i + 1 )
        break

# If no such element is found, printing -1
print ( - 1 )

