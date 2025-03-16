
import math
import sys

# Read the value of N
N = int ( sys.stdin.readline ( ) )

# Initialize min to 0 and find the minimum of the first five inputs
min = 0
for i in range ( 5 ) : 
    if i == 0 : 
        min = int ( sys.stdin.readline ( ) )
    else : 
        min = min ( min , int ( sys.stdin.readline ( ) ) )

# Calculate the result and print it
print ( math.ceil ( N / min ) + 4 )

# 