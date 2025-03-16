# Read the number of elements
N = int(input())

# Create an array to store the positions of elements
mem = [0] * (N + 1)

# Populate the'mem' array with the positions of each element
for i in range(1, N + 1):
    P = int(input()) # Read the element
    mem[P] = i # Store the position of the element in'mem'

# Initialize counters for the longest increasing subsequence
maxcnt = 1 # Maximum count of increasing sequence found
cnt = 1 # Current count of increasing sequence

# Iterate through the'mem' array to find the longest increasing subsequence
for i in range(1, N):
    # Check if the current position is less than the next position
    if mem[i] < mem[i + 1]:
        cnt += 1 # Increment the current count if increasing
    else:
        # Update the maximum count if the current count is greater
        maxcnt = max(maxcnt, cnt)
        cnt = 1 # Reset current count
    # Check at the last element to update max count
    if i == N - 1:
        maxcnt = max(maxcnt, cnt)

# Output the minimum number of elements to remove to get the longest increasing subsequence
print(N - maxcnt)

# 