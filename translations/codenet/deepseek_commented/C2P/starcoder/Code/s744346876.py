# Include the standard input/output header
import sys

# Declare two integer variables A and B
A = int(sys.stdin.readline())
B = int(sys.stdin.readline())

# Check if both A and B are less than 10, if true, print the multiplication result
if A < 10 and B < 10:
    print(A * B)
# If the condition is false, print -1
else:
    print(-1)

# 