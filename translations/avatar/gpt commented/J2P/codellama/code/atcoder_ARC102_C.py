import sys

# Define a constant for the modulus value
mod = 998244353
# Declare a 2D array to store binomial coefficients
nchoosek = [[0] * 4001 for _ in range(4001)]

# Set base cases for binomial coefficients: C(n, 0) = C(n, n) = 1
for i in range(len(nchoosek)):
    nchoosek[i][0] = nchoosek[i][i] = 1

# Compute binomial coefficients using dynamic programming
for i in range(2, len(nchoosek)):
    for j in range(1, i):
        # C(i, j) = C(i-1, j) + C(i-1, j-1)
        nchoosek[i][j] = (nchoosek[i - 1][j] + nchoosek[i - 1][j - 1]) % mod

# Create a Scanner object to read input values
sc = sys.stdin
# Read the values of k and n from input
k, n = map(int, sc.readline().split())

# Iterate through the range of 2 to 2*k
for i in range(2, 2 * k + 1):
    pairs = k - i // 2 if i > k else (i - 1) // 2
    active = k - 2 * pairs
    if i % 2 == 0:
        active -= 1

    times2 = 1
    total = 0

    # Calculate total combinations for the current number of pairs
    for j in range(0, pairs + 1):
        # Calculate the number of ways to choose j pairs
        choice = times2 * nchoosek[pairs][j] % mod
        times2 = times2 * 2 % mod

        # Skip if there are not enough active elements
        if active + j - 1 < 0:
            continue

        # Add combinations to the total based on active elements
        total += choice * nchoosek[n + active - 1][active + j - 1]

        # If i is even, add additional combinations
        if i % 2 == 0:
            total += choice * nchoosek[n + active - 2][active + j - 1]

        # Ensure total remains within modulus
        total %= mod

    # Output the total combinations for the current i
    print(total)

# 