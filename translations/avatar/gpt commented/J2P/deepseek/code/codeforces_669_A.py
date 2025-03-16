import sys

def solve(n):
    # Calculating and printing the result based on the input integer n
    # The formula calculates (n // 3) * 2 and adds 1 if n is not divisible by 3
    print((n // 3) * 2 + (0 if n % 3 == 0 else 1))

# Reading an integer input from the user
n = int(sys.stdin.readline().strip())

# Calling the solve method with the input integer
solve(n)
