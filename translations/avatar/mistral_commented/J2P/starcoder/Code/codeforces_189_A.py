
import sys

# Reading the number of elements in the array from the console
n = int ( input ( ) )

# Reading the three integers representing the array elements
a = int ( input ( ) )
b = int ( input ( ) )
c = int ( input ( ) )

# Defining an array to store the array elements
arr = [ a, b, c ]

# Defining the maximum size of the dynamic programming array
maxn = 4010

# Creating a dynamic programming array of size maxn
dp = [ 0 ] * maxn

# Initializing the dynamic programming array with minimum values
for i in range ( 0, n ) :
    dp [ i ] = - sys.maxsize

dp [ 0 ] = 0

# Filling the dynamic programming array using two nested loops
for i in range ( 0, 3 ) :
    for j in range ( arr [ i ], maxn ) :
        dp [ j ] = max ( dp [ j ], dp [ j - arr [ i ] ] + 1 )

# Printing the result, which is the maximum length ending at the nth index
print ( dp [ n ] )

# 