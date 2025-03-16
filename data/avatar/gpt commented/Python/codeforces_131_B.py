import sys
input = sys.stdin.readline
from collections import Counter

# Read the number of elements
n = int(input())

# Read the elements and count their occurrences using Counter
w = Counter(map(int, input().split()))

# Initialize a counter for pairs that sum to zero
c = 0

# Iterate through each unique number in the counter
for i in w:
    # Check if the number is zero
    if i == 0:
        # For zero, count pairs (w[i] choose 2) since both numbers are the same
        c += w[i] * (w[i] - 1)
    else:
        # Check if the negative counterpart exists in the counter
        if -i in w:
            # Count pairs formed by the number and its negative counterpart
            c += w[i] * w[-i]

# Since each pair is counted twice, divide the total count by 2 before printing
print(c // 2)
