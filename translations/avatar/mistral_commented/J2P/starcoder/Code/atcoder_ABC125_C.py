import sys

# Initialize the array A and read its elements from the standard input
A = [ ]
N = int ( sys.stdin.readline ( ) )
for i in range ( N ) :
    A.append ( int ( sys.stdin.readline ( ) ) )

# Initialize arrays M, L, and R
M = [ ]
L = [ ]
R = [ ]

# Initialize the first elements of L and R arrays
L.append ( A [ 0 ] )
R.append ( A [ N - 1 ] )

# Calculate the gcd of consecutive pairs of elements in the array A,
# starting from the second element, and store the results in the L array
for i in range ( 1, N ) :
    L.append ( gcd ( L [ i - 1 ], A [ i ] ) )

# Calculate the gcd of consecutive pairs of elements in the array A,
# starting from the last element, and store the results in the R array
for i in range ( N - 2, -1, -1 ) :
    R.append ( gcd ( R [ i + 1 ], A [ i ] ) )

# Find the maximum value among the gcd of consecutive pairs of elements
# in the subarrays [0, i] and [i+1, N-1] for all i from 0 to N-2
answer = max ( L [ N - 2 ], R [ 1 ] )
for i in range ( 1, N - 1 ) :
    answer = max ( answer, gcd ( L [ i - 1 ], R [ i + 1 ] ) )

# Print the result
print ( answer )

# 