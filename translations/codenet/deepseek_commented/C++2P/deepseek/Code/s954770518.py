# Include header for input/output operations
import sys

# Read input numbers into the list
s = []
for i in range(10):
    s.append(int(sys.stdin.readline()))

# Sort the list in ascending order
s.sort()

# Print the last four numbers of the sorted list
for i in range(9, 6, -1):
    print(s[i])

# End-of-code comment
