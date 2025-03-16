import numpy as np

# Read the size of the array
N = int(input())

# Create a numpy array from the input values
A = np.fromiter(map(int, input().split()), np.int64)

# Initialize the result variable to 0
result = 0

# Loop over each bit position from 0 to 59
for b in range(60):
    # Count the number of set bits at the current bit position
    bs = int(((A >> b) & 1).sum())
    
    # Calculate the contribution of the current bit position to the result
    result = (result + bs * (N - bs) * (1 << b)) % 1000000007

# Print the final result
print(result)
