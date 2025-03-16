
#!/usr/bin/env python3

import sys

# scanner wraps bufio.Scanner to provide convenient methods for reading input.
class scanner:
    def __init__(self, r):
        self.s = bufio.Scanner(r)
        self.s.split(bufio.ScanWords) # Set the scanner to split input by words.
        self.s.buffer(None, 100000000) # Set a large buffer size for the scanner.

    # Int reads the next integer from the input.
    def Int(self):
        self.s.scan() # Scan the next token.
        return int(self.s.text()) # Convert the scanned text to an integer.

    # IntSlice reads a slice of integers from the input with the specified length.
    def IntSlice(self, l):
        if l == 0:
            return [] # Return an empty slice if length is zero.
        sl = [0] * l # Create a slice of the specified length.
        for i in range(l):
            sl[i] = self.Int() # Fill the slice with integers from input.
        return sl

# iabs returns the absolute value of an integer.
def iabs(x):
    if x < 0:
        return -x # Return the negation if x is negative.
    return x # Return x if it is non-negative.

# solve computes the minimum cost to reach the last height using dynamic programming.
def solve(n, heights):
    t = [0] * (n+1) # Create a slice to store minimum costs.
    for i in range(n+1):
        t[i] = 10**9 # Initialize all costs to a large value.

    t[0] = 0 # The cost to reach the first height is zero.
    for i in range(1, n):
        # Calculate the cost to reach the current height from the previous height.
        if v := t[i-1] + iabs(heights[i]-heights[i-1]); v < t[i]:
            t[i] = v # Update the cost if it's lower.
        # Calculate the cost to reach the current height from two heights back.
        if 1 < i:
            if v := t[i-2] + iabs(heights[i]-heights[i-2]); v < t[i]:
                t[i] = v # Update the cost if it's lower.

    return t[n-1] # Return the minimum cost to reach the last height.

# main function to execute the program.
def main():
    sc = scanner(sys.stdin) # Initialize the scanner for standard input.
    n = sc.Int() # Read the number of heights.
    heights = sc.IntSlice(n) # Read the heights into a slice.
    ans = solve(n, heights) # Solve for the minimum cost.
    print(ans) # Print the result.

