
import sys

# Read the number of elements (n) and the threshold (k) from input
n, k = map(int, input().split())

# Initialize an array to hold the input values
bb = list(map(int, input().split()))

# Initialize an array to hold the results and a counter for the results
aa = [0] * n
m = 0

# Process the input array in reverse order
for a in range(n - 1, -1, -1):
    j = 0
    # While there are still counts left for the current index in bb
    while bb[a] > 0:
        # Check if the current index in aa is valid
        if aa[j] >= a + k:
            bb[a] -= 1  # Decrease the count for bb[a]
        j += 1  # Move to the next index in aa
    # Shift elements in aa to make space for the current index
    for j_ in range(m, j):
        aa[j_] = aa[j_ - 1]
    aa[j] = a  # Place the current index in aa

# Output the results, incrementing by 1 for 1-based indexing
print(" ".join(map(lambda x: str(x + 1), aa)))

