
from math import *
def next_int ( ) :
    return int ( input ( ) )
def next_ints ( ) :
    return list ( map ( int , input ( ).split ( ) ) )

# Read the value of n from input
n = next_int ( )

# Initialize a counter to keep track of odd numbers
t = 0

# Loop through each number from 0 to n-1
for i in range ( n ) :
    # Check if the current index plus one is odd
    if i + 1 & 1 :
        # Increment the counter if the condition is true
        t += 1

# Calculate the ratio of odd numbers to the total numbers and print it
print ( t / n )

