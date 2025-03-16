
import sys

# Read input numbers N and K
N, K = map(int, sys.stdin.readline().split())

# Calculate the base-10 representation of N up to digit count K
s = str(N)
while len(s) < K:
    s = str(int(s) % K) + s
    if int(s) < K:
        break
    s = str(int(s) // K)

# Print the length of the calculated string
print(len(s))

# 