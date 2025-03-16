
import numpy as np

# Take the number of elements as input
N = int(input())

# Take a space-separated string of integers as input and convert them to a list of integers
n = [int(x) for x in input().split()]

# Convert the list to a NumPy array
n = np.array(n)

# Initialize a counter to 1 and a position index to 0
a = 1
pos = 0

# Loop through the array from the second element to the last
for i in range(1, N):
    # Check if the current minimum element is greater than the current element
    if n[pos] > n[i]:
        # Increment the counter and update the position index
        a += 1
        pos = i

# Print the final count of elements that are greater than the current minimum
print(a)


