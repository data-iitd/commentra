# Import necessary modules
import os
from sys import stdin, stdout

# Function to solve a single test case
def solve(tc):
    # Read the next test case and store it in a variable 'a'
    a = int(stdin.readline().strip())

    # Print the solution for the current test case
    print(1 if a == 0 else 0)

# Initialize the number of test cases and the test case counter
tcs = 1
tc = 1

# Run the solution function for each test case
while tc <= tcs:
    # Solve the current test case
    solve(tc)

    # Increment the test case counter
    tc += 1
