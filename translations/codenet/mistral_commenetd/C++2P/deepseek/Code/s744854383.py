import sys

# Read the number of elements from the standard input
N = int(input().strip())

# Read the elements of the array
a = list(map(int, input().strip().split()))

# Initialize variables
idx = 1
ans = 0

# Process the array
for i in range(N):
    # Check if the current element matches the index
    if a[i] == idx:
        # Increment the index
        idx += 1
    else:
        # Increment the answer
        ans += 1

# Output the result
if idx == 1:
    print(-1)  # Output -1 if all elements are the same
else:
    print(ans)  # Output the answer otherwise
