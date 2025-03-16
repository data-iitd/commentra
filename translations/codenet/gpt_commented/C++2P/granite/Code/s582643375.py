
# Python code to calculate the number of lattice points on the line y = 2x that are below the line y = x + 1 and lie on or above the x-axis

# Define constants for modulo operations and maximum size
mod = 10**9 + 7
NMAX = 10**6 + 10

# Arrays to store factorials, inverse factorials, and modular inverses
fac = [1] * NMAX
finv = [1] * NMAX
inv = [0] * NMAX
inv[1] = 1

# Function to initialize factorials and their inverses
def init():
    global fac, finv, inv
    for i in range(2, NMAX):
        fac[i] = fac[i - 1] * i % mod
        inv[i] = mod - inv[mod % i] * (mod // i) % mod
        finv[i] = finv[i - 1] * inv[i] % mod

# Function to compute binomial coefficient C(n, k)
def C(n, k):
    if n < k: return 0
    if n < 0 or k < 0: return 0
    return fac[n] * (finv[k] * finv[n - k] % mod) % mod

# Read input values for X and Y
X, Y = map(int, input().split())

# Check if the sum of X and Y is divisible by 3
if (X + Y) % 3!= 0:
    print(0) # If not, output 0 and exit
    exit()

# Calculate n based on the sum of X and Y
n = (X + Y) // 3 + 1

# Calculate k based on the relationship to the line y = 2x
k = 2 * (n - 1) - Y + 1

# Output the result of the binomial coefficient C(n-1, k-1)
print(C(n - 1, k - 1))

