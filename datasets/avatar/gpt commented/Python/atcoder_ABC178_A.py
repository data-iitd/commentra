import os
from sys import stdin, stdout

# Define a function to solve the problem for a given test case
def solve(tc):
    # Read an integer from standard input and strip any extra whitespace
    a = int(stdin.readline().strip())
    
    # Print 1 if the integer is 0, otherwise print 0
    print(1 if a == 0 else 0)

# Initialize the number of test cases
tcs = 1
# Start with the first test case
tc = 1

# Loop through each test case until the specified number of test cases is reached
while tc <= tcs:
    # Call the solve function for the current test case
    solve(tc)
    # Increment the test case counter
    tc += 1
