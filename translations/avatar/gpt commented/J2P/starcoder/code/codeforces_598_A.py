import sys

# Reading the number of test cases
q = int(sys.stdin.readline())

# Looping through each test case
while q > 0:
    # Reading the integer n for the current test case
    n = int(sys.stdin.readline())
    
    # Initializing a variable to store the result
    s = 0
    
    # Calculating the highest power of 2 less than or equal to n
    x = int(math.log(n, 2))
    x += 1
    
    # Calculating the final result using the derived formula
    s = -1 * (2 ** x) + 2 + ((n * (n + 1)) / 2) - (2 ** x)
    
    # Printing the result for the current test case
    print(s)
    
    # Decrementing the number of test cases
    q -= 1

# 