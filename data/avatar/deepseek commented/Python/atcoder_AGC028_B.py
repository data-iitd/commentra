
import sys
input = sys.stdin.readline
import numpy as np

MOD = 10 ** 9 + 7  # Define the modulo constant
N = int(input())  # Read the size of the array
M = 10 ** 6  # Define a constant for the factorial table size
A = np.array(input().split(), dtype=np.int64)  # Read the array elements and convert to numpy array

Nsq = 10 ** 3  # Define a constant for the size of the factorial table

# Initialize the factorial table
fact = np.arange(M, dtype=np.int64).reshape(Nsq, Nsq)
fact[0, 0] = 1

# Compute the factorial table
for n in range(1, Nsq):
    fact[:, n] *= fact[:, n - 1]  # Multiply current column with the previous column
    fact[:, n] %= MOD  # Take modulo MOD

# Compute the factorial table row-wise
for n in range(1, Nsq):
    fact[n] *= fact[n - 1, -1]  # Multiply current row with the last element of the previous row
    fact[n] %= MOD  # Take modulo MOD

# Flatten the factorial table for efficient storage
fact = fact.ravel()

# Compute the inverse factorial values
j = np.arange(N)
inv = np.array([pow(i + 1, MOD - 2, MOD) for i in range(N)])
inv = np.cumsum(inv) % MOD

# Compute the temporary value
temp = inv[j] + inv[N - 1 - j] - 1

# Compute the final answer
ans = (A * temp % MOD).sum()
ans %= MOD

# Multiply the final answer with the factorial of N
ans *= fact[N]
ans %= MOD

# Print the final answer
print(ans)

