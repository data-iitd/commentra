# Import required libraries
import sys
input = sys.stdin.readline
import numpy as np
# Define constant value
MOD = 10 ** 9 + 7

# Read input number of elements N
N = int(input())
# Define a constant value for the size of the 2D array A
M = 10 ** 6

# Initialize NumPy array A with given size and input data
A = np.array(input().split(), dtype=np.int64)

# Define a constant value for the size of the 2D array fact
Nsq = 10 ** 3

# Initialize 2D NumPy array fact with given size and initial value 1
fact = np.arange(M, dtype=np.int64).reshape(Nsq, Nsq)
fact[0, 0] = 1

# Calculate factorial for each cell in the 2D array fact using a loop
for n in range(1, Nsq):
    fact[ : , n ] *= fact[ : , n - 1 ]  # Multiply current row with previous row
    fact[ : , n ] %= MOD             # Modulo with given constant value MOD

# Transpose the 2D array fact and calculate factorial for each cell in the new rows
for n in range(1, Nsq):
    fact[n] *= fact[n - 1, -1]       # Multiply current row with last cell of previous row
    fact[n] %= MOD                  # Modulo with given constant value MOD

# Flatten the 2D array fact into a 1D NumPy array
fact = fact.ravel()

# Initialize NumPy array j with given size
j = np.arange(N)

# Calculate the inverse of each element in the array inv using a list comprehension
inv = np.array([pow(i + 1, MOD - 2, MOD) for i in range(N)])

# Calculate cumulative sum of the array inv
inv = np.cumsum(inv) % MOD

# Calculate temporary array temp using elements from j and inv
temp = inv[j] + inv[N - 1 - j] - 1

# Calculate the answer ans using given formula
ans = (A * temp % MOD).sum()

# Modulo the answer ans with given constant value MOD
ans %= MOD

# Multiply the answer ans with the last element of fact array
ans *= fact[N]

# Modulo the answer ans with given constant value MOD
ans %= MOD

# Print the answer ans
print(ans)
