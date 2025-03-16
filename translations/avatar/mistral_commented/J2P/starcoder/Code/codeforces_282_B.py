/

import sys

# Reading the number of test cases from the standard input stream
n = int ( sys.stdin.readline ( ) )

# Allocating an array of size 'n' to store characters
ch = [ ]
s1 = 0
s2 = 0

# Reading input for each test case
for i in range ( n ) :
    x = int ( sys.stdin.readline ( ) ) # Reading the value of 'x' for the current test case
    y = int ( sys.stdin.readline ( ) ) # Reading the value of 'y' for the current test case

    temp1 = s1 + x # Calculating the sum of's1' and 'x'
    temp2 = s2 + y # Calculating the sum of's2' and 'y'

    # Checking if the difference between the sums is within the limit of 500
    if ( abs ( temp1 - temp2 ) <= 500 ) :
        s1 += x # Updating the value of's1'
        ch.append ( 'A' ) # Adding 'A' to the character array 'ch'
        continue # Skipping the rest of the loop and moving to the next iteration

    # Checking if the difference between the absolute values of the sums is within the limit of 500
    if ( abs ( temp1 - s2 ) <= 500 ) :
        s2 += y # Updating the value of's2'
        ch.append ( 'G' ) # Adding 'G' to the character array 'ch'
        continue # Skipping the rest of the loop and moving to the next iteration

    print ( - 1 ) # Printing -1 if the difference is greater than 500
    break # Exiting the loop if the difference is greater than 500

# Printing the string 'ans' as the answer for the current test case
print ( ''.join ( ch ) )

