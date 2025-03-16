import math

# Read input values for N and K
N, K = (int(x) for x in input().split())

# Calculate the value of R as the difference between N and K
R = N - K

# Define the modulus value for the output
mod = 10**9 + 7

# Function to calculate the number of combinations (n choose r)
def fact(n, r):
    return math.factorial(n) // (math.factorial(n - r) * math.factorial(r))

# Loop through each value from 1 to K (inclusive)
for i in range(1, K + 1):
    # Check if the current index i exceeds the available combinations
    if N - K + 1 < i:
        ans = 0  # If so, set answer to 0
    else:
        # Calculate the answer using the fact function for combinations
        ans = fact(R + 1, i) * fact(K - 1, i - 1)
    
    # Print the result modulo the defined modulus
    print(int(ans) % mod)
