
import sys
from bisect import bisect_left

# Read input from stdin and provide input() function
def input():
    return sys.stdin.readline().rstrip()

# Initialize xs with the first element of as
n = int(input())
as = [int(input()) for _ in range(n)]
xs = [as[0]]
for j in range(1, n):
    # Use bisect_left to find the position to insert the current element
    idx = bisect_left(xs, as[j])
    if idx == len(xs):
        # If the element is larger than all elements in xs, append it
        xs.append(as[j])
    else:
        # Otherwise, replace the existing element at the found position
        xs[idx] = as[j]

# Print the length of the longest increasing subsequence found
print(len(xs))

