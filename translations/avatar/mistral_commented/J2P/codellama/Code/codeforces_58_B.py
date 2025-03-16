
import sys

# Reading the first number from the user input
n = int ( sys.stdin.readline ( ) )

# Printing the first number to the standard output stream
print ( n )

# Initializing an integer variable 'm' with the value of 'n'
m = n

# Finding the factors of the number 'n' using a for loop
for i in range ( n - 1 , 0 , -1 ) :
    if ( m % i == 0 ) :  # Checking if 'i' is a factor of 'm'
        # Printing the factor to the standard output stream
        print ( i )
        # Updating the value of 'm' with the current factor
        m = i

# 