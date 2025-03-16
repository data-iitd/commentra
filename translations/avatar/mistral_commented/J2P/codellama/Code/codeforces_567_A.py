
import math
import sys

# Asking user for the size of the array and initializing it
a = int ( input ( ) )
ar = [ ]

# Initializing variables for storing maximum and minimum differences
max = 0
min = 0

# Reading array elements from user input
for i in range ( a ) :
    ar.append ( int ( input ( ) ) )

# Finding maximum and minimum differences between consecutive elements in the array
for i in range ( len ( ar ) ) :
    # Finding maximum difference between current element and first element
    max = max ( ar [ i ] - ar [ 0 ] , ar [ len ( ar ) - 1 ] - ar [ i ] )

    # Finding minimum difference between current element and previous element
    if i == 0 :
        min = ar [ i + 1 ] - ar [ i ]
    elif i == len ( ar ) - 1 :
        min = ar [ i ] - ar [ i - 1 ]
    else :
        min = min ( ar [ i ] - ar [ i - 1 ] , ar [ i + 1 ] - ar [ i ] )

    # Printing minimum and maximum differences for each pair of consecutive elements
    print ( min , max )

# END-OF-CODE
