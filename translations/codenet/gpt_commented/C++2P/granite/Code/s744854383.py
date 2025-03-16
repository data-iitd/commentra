
# Read the number of elements
N = int(input())

# Initialize a list to store the elements
a = list(map(int, input().split()))

# Initialize index and answer counter
idx = 1
ans = 0

# Iterate through the list to count mismatches
for i in range(N):
    # If the current element matches the expected index
    if a[i] == idx:
        # Move to the next expected index
        idx += 1
    else:
        # Count the mismatch
        ans += 1

# If no elements matched the expected index
if idx == 1:
    print(-1)  # Output -1 to indicate no matches
else:
    # Output the count of mismatches
    print(ans)

