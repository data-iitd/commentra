# Read input values K and N from user
K, N = list(map(int, input().split()))

# Define a debug print function (currently does nothing)
dprint = lambda *x: x

# Function to compute combinations modulo 'mod'
def cmb(n, r, mod):
    # Return 0 if r is out of bounds
    if (r < 0 or r > n):
        return 0
    # Use symmetry property of combinations
    r = min(r, n - r)
    # Calculate combination using precomputed factorials and inverses
    return g1[n] * g2[r] * g2[n - r] % mod

# Set modulo value and maximum value for precomputation
mod = 998244353
__N = 8000

# Precompute factorials and inverse factorials
g1 = [1, 1]  # g1 will hold factorials
g2 = [1, 1]  # g2 will hold inverse factorials
inverse = [0, 1]  # inverse will hold modular inverses

# Fill g1, g2, and inverse arrays
for i in range(2, __N + 1):
    g1.append((g1[-1] * i) % mod)  # Compute factorial
    inverse.append((-inverse[mod % i] * (mod // i)) % mod)  # Compute modular inverse using Fermat's Little Theorem
    g2.append((g2[-1] * inverse[-1]) % mod)  # Compute inverse factorial

# Function to compute kumiawase (combinations with repetition)
def kumiawase(p, q):
    return cmb(p + q - 1, q - 1, mod)

# Function to solve the main problem for a given n
def solve(n):
    assert n <= K + 1  # Ensure n is within valid range
    ans = 0  # Initialize answer
    kumi = (n - 1) // 2  # Calculate half of n-1

    # Iterate over possible values of p
    for p in range(kumi + 1):
        if p > N:  # Break if p exceeds N
            break
        # Update answer with contributions from current p
        ans += 2 ** p * cmb(kumi, p, mod) * kumiawase(N - p, p + (K - kumi * 2 - int(n % 2 == 0)))
        
        # If n is even, consider the case where p is used one less
        if n % 2 == 0 and N - p - 1 >= 0:
            ans += 2 ** p * cmb(kumi, p, mod) * kumiawase(N - p - 1, p + (K - kumi * 2 - int(n % 2 == 0)))

    return ans  # Return the computed answer

# List to store answers for each i
ans = []

# Iterate over the range to compute results for each i
for i in range(2, 2 * K + 1):
    if i <= K + 1:
        # Solve for i and store the result
        tmp = solve(i) % 998244353
        ans.append(tmp)  # Append result to answers list
        print(tmp)  # Print the result
    else:
        # For i greater than K+1, use previously computed results
        print(ans[-i + K])  # Print the corresponding result from the answers list
