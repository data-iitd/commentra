
import os
from sys import stdin , stdout

# Define the solve function that takes a test case number as an argument
def solve ( tc ) :
    # Read an integer input from standard input
    a = int ( stdin.readline ( ).strip ( ) )
    # Print 1 if the input is 0, otherwise print 0
    print ( 1 if a == 0 else 0 )

# Set the number of test cases to 1 and initialize the current test case number
tcs = 1
tc = 1

# Enter a while loop that continues as long as the current test case number is less than or equal to the total number of test cases
while tc <= tcs :
    # Call the solve function with the current test case number and increment the current test case number
    solve ( tc )
    tc += 1

