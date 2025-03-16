import numpy as np

# Read the number of elements in the array
N = int(input())

# Read the input values and create a NumPy array of integers
A = np.fromiter(map(int, input().split()), np.int64)

# Initialize the result variable to store the final answer
result = 0

# Iterate over each bit position from 0 to 59 (assuming 60 bits for integers)
for b in range(60):
    # Count how many numbers have the b-th bit set (1)
    bs = int(((A >> b) & 1).sum())
    
    # Calculate the contribution of the b-th bit to the result
    # bs * (N - bs) gives the number of pairs with different b-th bits
    # (1 << b) gives the value of the b-th bit
    result = (result + bs * (N - bs) * (1 << b)) % 1000000007

# Print the final result
print(result)
