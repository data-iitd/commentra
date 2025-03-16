# Include necessary libraries
import sys

# Read input values
n, k = map(int, sys.stdin.readline().split())

# Initialize the count variable
cnt = 0

# Use a while loop to read each height
while n > 0:
	h = int(sys.stdin.readline()) # Read each height
	if h >= k: # Check if the height is suitable
		cnt += 1 # Increment the count if the height is greater than or equal to k
	n -= 1 # Decrement the number of heights

# Print the final count
print(cnt)

# 