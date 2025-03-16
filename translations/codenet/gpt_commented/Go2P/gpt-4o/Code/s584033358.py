# Import the sys module to read from standard input
import sys

# Read two integers from standard input
# n represents the total number of items, and k represents a threshold value
n, k = map(int, sys.stdin.readline().strip().split())

# Check if k is less than or equal to half of n (rounded up)
if k <= (n + n % 2) // 2:
    # If the condition is true, print "YES"
    print("YES")
else:
    # If the condition is false, print "NO"
    print("NO")

# <END-OF-CODE>
