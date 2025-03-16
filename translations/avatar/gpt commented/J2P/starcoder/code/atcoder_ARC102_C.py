import sys

# Define a constant for the modulus value
mod = 998244353
# Declare a 2D array to store binomial coefficients
nchoosek = [[0] * 4001 for i in range(4001)]

# Set base cases for binomial coefficients: C(n, 0) = C(n, n) = 1
for i in range(4001):
    nchoosek[i][0] = nchoosek[i][i] = 1

# Compute binomial coefficients using dynamic programming
for i in range(2, 4001):
    for j in range(1, i):
        # C(i, j) = C(i-1, j) + C(i-1, j-1)
        nchoosek[i][j] = (nchoosek[i - 1][j] + nchoosek[i - 1][j - 1]) % mod

# Read the values of k and n from input
k = int(sys.stdin.readline())
n = int(sys.stdin.readline())

# Iterate through the range of 2 to 2*k
for i in range(2, 2 * k + 1):
    pairs = 0
    # Calculate the number of pairs based on the current index i
    if i > k:
        pairs = k - i // 2 # More pairs than k
    else:
        pairs = (i - 1) // 2 # Fewer pairs than k

    # Calculate the number of active elements remaining
    active = k - 2 * pairs
    if i % 2 == 0: active -= 1 # Adjust active count for even i

    times2 = 1 # Initialize multiplier for choices
    total = 0 # Initialize total count

    # Calculate total combinations for the current number of pairs
    for j in range(pairs + 1):
        # Calculate the number of ways to choose j pairs
        choice = times2 * nchoosek[pairs][j] % mod
        times2 = times2 * 2 % mod # Update multiplier for the next iteration

        # Skip if there are not enough active elements
        if active + j - 1 < 0: continue

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