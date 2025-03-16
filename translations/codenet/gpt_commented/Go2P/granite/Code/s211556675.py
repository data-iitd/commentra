
import sys

# I/O
# Scanner class to facilitate reading input from standard input
class Scanner:
    def __init__(self):
        self.sc = iter(sys.stdin.read().split())

    def nextStr(self):
        return next(self.sc)

    def nextInt(self):
        return int(next(self.sc))

    def nextFloat(self):
        return float(next(self.sc))

    def nextRuneSlice(self):
        return list(next(self.sc))

    def nextIntSlice(self, n):
        return [self.nextInt() for _ in range(n)]

    def nextFloatSlice(self, n):
        return [self.nextFloat() for _ in range(n)]

# Arithmetic functions

# max returns the maximum value from a list of integers
def max(*nums):
    m = nums[0] # Initialize max with the first element
    for i in nums:
        if m < i:
            m = i # Update max if a larger value is found
    return m

# min returns the minimum value from a list of integers
def min(*nums):
    m = nums[0] # Initialize min with the first element
    for i in nums:
        if m > i:
            m = i # Update min if a smaller value is found
    return m

# abs returns the absolute value of an integer
def abs(x):
    if x > 0:
        return x # Return x if positive
    return -x # Return -x if negative

# pow computes x raised to the power of y
def pow(x, y):
    res = 1 # Initialize result
    for _ in range(y):
        res *= x # Multiply res by x, y times
    return res

# Main function
def main():
    sc = Scanner() # Create a new scanner for input
    wtr = sys.stdout # Create a writer for output

    # Read four integers from input
    A, B, C, K = sc.nextInt(), sc.nextInt(), sc.nextInt(), sc.nextInt()

    # Determine the maximum value among A, B, and C
    ma = max(A, B, C)
    rest = 0 # Initialize the rest variable to hold the sum of the other two values

    # Calculate the sum of the two smaller values
    if ma == A:
        rest += B + C
    elif ma == B:
        rest += A + C
    else:
        rest += A + B

    # Double the maximum value K times
    for _ in range(K):
        ma *= 2

    # Output the final result: doubled max value plus the sum of the other two
    print(ma + rest)

if __name__ == "__main__":
    main()

