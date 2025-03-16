# Import the NumPy library for efficient array operations
import numpy as np

# Read the number of elements 'N' from the user
N = int(input())

# Read 'N' integers from the user and store them in a NumPy array 'A'
A = np.fromiter(map(int, input().split()), np.int64)

# Initialize the result variable to zero
result = 0

# Iterate through each bit position 'b' from 0 to 59
for b in range(60):
    
    # Calculate the sum of bits in position 'b' in all numbers of 'A'
    bs = int((A >> b).sum())
    
    # Calculate the contribution of this bit position 'b' to the result
    contribution = bs * (N - bs) * (1 << b)
    
    # Add this contribution to the result
    result = (result + contribution) % 1000000007

# Print the final result
print(result)
