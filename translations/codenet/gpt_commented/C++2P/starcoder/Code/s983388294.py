
# Read the number of elements
n = int(input())

# Initialize a vector to store the input elements
a = []

# Read n integers into the vector
for i in range(n):
    a.append(int(input()))

# Initialize a counter for the current expected number
curr = 0

# Iterate through the vector to find the longest prefix of consecutive integers starting from 1
for i in range(n):
    if a[i] == curr+1:
        curr += 1 # Increment curr if the current element matches the expected value

# Check if any consecutive integers were found
if curr > 0:
    # Print the number of elements not in the consecutive sequence
    print(n-curr)
else:
    # If no consecutive integers were found, print -1
    print(-1)

# 