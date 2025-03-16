
import sys

# Initialize input reader with a buffer size of 1,000,000 bytes
input = sys.stdin.buffer.read

# Read the number of elements and the array of integers from input
n = int(input())
s = list(map(int, input().split()))

# Create a boolean slice to track used indices
u = [False] * n

# Initialize variables to store the maximum sum and a temporary sum
m = 0
f = 0

# Iterate through possible values of c from 1 to n-2
for c in range(1, n-1):
  f = 0 # Reset the temporary sum for each c
  
  # Iterate to find pairs of indices based on the current value of c
  for k in range(0, n-1-c):
    u[k*c] = True # Mark the current index as used
    
    # Break if the corresponding index is already used
    if u[n-1-k*c]: break
    
    # Calculate the sum of the elements at the current indices
    f += s[n-1-k*c] + s[k*c]
    
    # Update the maximum sum if the current sum is greater
    if m < f: m = f
    
    # Reset the used indices for the next iteration of c
    for k in range(0, n-1-c): u[k*c] = False

# Print the maximum sum found
print(m)

