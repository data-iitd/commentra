
from collections import deque
n = int(input())  # Read an integer n from the input
a = list(map(str, input().split()))  # Read a list of strings a from the input
b = []

# Create list b by taking every second element from a (starting from index 1) in reverse order
# and then adding every second element from a (starting from index 0) in normal order
b = a[1::2][::-1] + a[::2]

# Check if the length of a is even
if len(a) % 2 == 0:
    # Print the elements of b as a single string with spaces between the elements
    print(' '.join(b))
else:
    # Print the elements of b in reverse order as a single string with spaces between the elements
    print(' '.join(b[::-1]))

