# Import necessary Python packages
import math
import sys

# Initialize the scanner for reading input
scan = sys.stdin.readline

# Read the length of the array from the user input
len = int ( scan ( ) . strip ( ) )

# Allocate memory for the array of integers
a = [ ]

# Read each integer from the user input and store it in the array
for i in range ( len ) :
    a.append ( int ( scan ( ) . strip ( ) ) )

# Initialize variables for left and right indices and a flag
l = 0
r = 0
flag = False

# Start the loop to search for two non-consecutive numbers
for i in range ( len ) :

    # Check if the current number is not in its correct position
    if a [ i ] != i + 1 and not flag :
        # Update the left index
        l = i + 1
        # Set the flag to true to indicate that we have found the first non-consecutive number
        flag = True
        # Continue to the next iteration of the loop
        continue

    # Check if the current number is also not in its correct position and the flag is set
    if a [ i ] != i + 1 and flag :
        # Update the right index
        r = i + 1

        # Check if the difference between the previous number and the current number is greater than 1
        if a [ r - 1 ] - a [ r - 2 ] > 0 :
            # Set the isTrue flag to true if the condition is satisfied
            isTrue = True
            # Break out of the loop if the flag is set to true
            break

# Print the result based on the value of the isTrue flag
print ( ( not isTrue ) * l + " " + r )


