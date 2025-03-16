import sys
input = sys.stdin.readline
import numpy as np

# Define the modulo constant
MOD = 10 ** 9 + 7

# Read the integer input N
N = int(input())

# Define a constant for the maximum size
M = 10 ** 6

# Read the array A from input and convert it to a numpy array of int64 type
A = np.array(input().split(), dtype=np.int64)

# Define the size for factorial calculations
Nsq = 10 ** 3

# Initialize a 2D array to store factorial values
fact = np.arange(M, dtype=np.int64).reshape(Nsq, Nsq)

# Set the first factorial value
fact[0, 0] = 1

# Compute factorial values for columns
for n in range(1, Nsq):
    fact[:, n] *= fact[:, n - 1]  # Multiply current column by the previous column
    fact[:, n] %= MOD  # Take modulo

# Compute factorial values for rows
for n in range(1, Nsq):
    fact[n] *= fact[n - 1, -1]  # Multiply current row by the last element of the previous row
    fact[n] %= MOD  # Take modulo

# Flatten the factorial array to 1D
fact = fact.ravel()

# Create an array of indices from 0 to N-1
j = np.arange(N)

# Calculate modular inverses of numbers from 1 to N
inv = np.array([pow(i + 1, MOD - 2, MOD) for i in range(N)])

# Compute cumulative sum of inverses and take modulo
inv = np.cumsum(inv) % MOD

# Calculate temporary values based on the cumulative inverses
temp = inv[j] + inv[N - 1 - j] - 1

# Compute the final answer by multiplying A with temp and summing the result
ans = (A * temp % MOD).sum()
ans %= MOD  # Take modulo

# Multiply the answer by the factorial of N and take modulo
ans *= fact[N]
ans %= MOD  # Take modulo

# Print the final answer
print(ans)
