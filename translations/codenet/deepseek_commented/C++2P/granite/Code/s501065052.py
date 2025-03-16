
# Read the number of elements N
N = int(input())

# Allocate an array mem to store the positions of elements
# The size of the array is N + 1 to accommodate 1-based indexing
mem = [0] * (N + 1)

# Read the elements and store their positions in the array mem
# The position is stored at the index corresponding to the element value
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

# Uncommented part of the code
# cnt = 1
# for i in range(N, 1, -1):
#     if mem[i] > mem[i - 1]:
#         cnt += 1

# Output the result, which is the number of elements to remove
# to make the sequence strictly decreasing
print(N - maxcnt)

