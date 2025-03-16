# Read the number of elements N
N = int(input())

# Read the elements and store their positions in the array mem
mem = [0] * (N + 1)
for i in range(1, N + 1):
    P = int(input())
    mem[P] = i

# Initialize variables to keep track of the longest increasing subsequence
maxcnt = 1
cnt = 1

# Iterate through the array to find the longest increasing subsequence
for i in range(1, N):
    # Check if the current position is less than the next position
    if mem[i] < mem[i + 1]:
        # Increment the count of the increasing subsequence
        cnt += 1
    else:
        # Update the maximum count if the current count is greater
        maxcnt = max(maxcnt, cnt)
        # Reset the count for the next subsequence
        cnt = 1
    # Update the maximum count if the end of the array is reached
    if i == N - 1:
        maxcnt = max(maxcnt, cnt)

# Output the result, which is the number of elements to remove
# to make the sequence strictly decreasing
print(N - maxcnt)
