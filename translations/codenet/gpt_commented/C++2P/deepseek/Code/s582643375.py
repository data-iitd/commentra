# Define long long type for large integers
from math import factorial

# Define constants for modulo operations and maximum size
mod = 10**9 + 7
NMAX = 1000010

# Arrays to store factorials, inverse factorials, and modular inverses
fac = [0] * NMAX
finv = [0] * NMAX
inv = [0] * NMAX

# Function to initialize factorials and their inverses
def init():
    # Base cases for factorials and their inverses
    fac[0] = fac[1] = 1
    finv[0] = finv[1] = 1
    inv[1] = 1

    # Precompute factorials and their modular inverses
    for i in range(2, NMAX):
        fac[i] = fac[i - 1] * i % mod  # Compute factorial mod
        inv[i] = mod - inv[mod % i] * (mod // i) % mod  # Compute modular inverse using Fermat's little theorem
        finv[i] = finv[i - 1] * inv[i] % mod  # Compute inverse factorial mod

# Function to compute binomial coefficient C(n, k)
def C(n, k):
    # Return 0 if k is greater than n or if either is negative
    if n < k:
        return 0
    if n < 0 or k < 0:
        return 0

    # Calculate C(n, k) using precomputed factorials and inverses
    return fac[n] * (finv[k] * finv[n - k] % mod) % mod

# Initialize factorials and inverses
init()

# Read input values for X and Y
X, Y = map(int, input().split())

# Check if the sum of X and Y is divisible by 3
if (X + Y) % 3 != 0:
    print(0)  # If not, output 0 and exit
    exit()

# Calculate n based on the sum of X and Y
n = (X + Y) // 3 + 1

# Calculate k based on the relationship to the line y = 2x
k = 2 * (n - 1) - Y + 1  # Determine how far the point is from the topmost point

# Output the result of the binomial coefficient C(n-1, k-1)
print(C(n - 1, k - 1))
