import sys

# Read input values of n and m from standard input
n, m = map(int, sys.stdin.readline().split())

# Initialize answer variable ans to 0
ans = 0

# Calculate the sum of numbers from 1 to n-1 and add it to the answer
ans += n * (n - 1) // 2

# Calculate the sum of numbers from 1 to m-1 and add it to the answer
ans += m * (m - 1) // 2

# Print the answer to the standard output
print(ans)
