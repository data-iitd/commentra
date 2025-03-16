import sys

# Reading the input
N, L, R, QL, QR = map(int, sys.stdin.readline().split())
W = list(map(int, sys.stdin.readline().split()))

# Initializing the minimum cost to a very large value
min = 1000000000000000000

# Iterating over possible positions for the rightmost item
for firstR in range(N + 1):
    lCount = firstR
    rCount = N - lCount

    # Calculating the cost for the current position of the rightmost item
    cand = sum(W[:lCount]) * L + sum(W[lCount:]) * R

    # Calculating the additional costs for unbalanced counts
    llCount = max(0, lCount - rCount - 1)
    rrCount = max(0, rCount - lCount - 1)
    cand += llCount * QL
    cand += rrCount * QR

    # Updating the minimum cost found so far
    min = min(cand, min)

# Printing the minimum cost
print(min)

