
import sys

# Read a line of input and split it into a list of integers
ns = list(map(int, sys.stdin.readline().split()))

# Sort the list of integers in ascending order
ns.sort()

# Check if the sorted list of integers matches the specific sequence [1, 4, 7, 9]
if ns == [1, 4, 7, 9]:
    # If they match, print "YES"
    print("YES")
else:
    # If they do not match, print "NO"
    print("NO")

