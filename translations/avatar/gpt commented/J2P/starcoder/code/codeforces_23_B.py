import sys; # Import the sys module for reading input from the console

# Read the number of test cases
t = int(sys.stdin.readline())

# Loop through each test case
for i in range(t):
    # Read the integer n for the current test case
    n = int(sys.stdin.readline())
    
    # Call the maxLeft function and print the result
    print(maxLeft(n))

# 