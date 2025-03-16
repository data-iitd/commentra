import sys
import math

# Define 'int' as 'long long' for larger integer support
int = int

# Structure to represent a range with a value
class Ban:
    def __init__(self, l, r, val):
        self.l = l
        self.r = r
        self.val = val

# Sparse table for range minimum queries
mn = [[0] * 200007 for _ in range(20)]
# Precomputed powers of 2
pw = [0] * 200007

# Function to initialize the sparse table
def init(a):
    n = len(a)
    # Fill the first row of the sparse table
    for i in range(n):
        mn[0][i] = a[i]
    # Build the sparse table for range maximum queries
    for i in range(19):
        for j in range(n - (1 << (i + 1)) + 1):
            mn[i + 1][j] = min(mn[i][j], mn[i][j + (1 << i)])
    # Precompute powers of 2 for later use
    pw[1] = 0
    for i in range(2, 200007):
        pw[i] = pw[i // 2] + 1

# Function to get the minimum value in the range [l, r]
def get(l, r):
    r += 1
    p = pw[r - l]
    return min(mn[p][l], mn[p][r - (1 << p)])

# Main function
def main():
    # Read the number of elements
    n = int(input())
    a = list(map(int, input().split()))

    # Vector to store the difference between index and value
    dl = [0] * n
    for i in range(n):
        # Check if the value exceeds its index
        if a[i] > i:
            print(-1)  # Output -1 if the condition fails
            return
        # Calculate the difference and store it
        dl[i] = i - a[i]

    # Initialize answer and vector to store ranges
    ans = 0
    bans = []
    i = 0
    while i < n:
        r = i
        # Extend the range while the next value is consecutive
        while r + 1 < n and a[r] + 1 == a[r + 1]:
            r += 1
        # Update the answer with the maximum value in the range
        ans += a[r]
        i = r  # Move to the end of the current range
        # Store the range in the bans vector
        bans.append(Ban(r - a[r], r, r - a[r]))
        i += 1

    # Initialize the sparse table with the difference vector
    init(dl)
    # Check each range for validity
    for t in bans:
        # If the minimum value in the range exceeds the stored value, output -1
        if get(t.l, t.r) > t.val:
            print(-1)
            return
    # Output the final answer
    print(ans)

# Call the main function
main()
