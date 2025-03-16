
import math

# Read input values for N and M
N, M = map(int, input().split())

# Calculate the number of valid positions based on the dimensions
ans = 0
if N == 1 and M == 1:
    # If both dimensions are 1, there's only one position
    ans += 1
elif 1 < N and 1 < M:
    # If both dimensions are greater than 1, calculate the inner positions
    ans += (N - 2) * (M - 2)
else:
    # If one dimension is 1, count the edge positions
    ans += (N * M) - 2

# Output the calculated answer
print(ans)

# 