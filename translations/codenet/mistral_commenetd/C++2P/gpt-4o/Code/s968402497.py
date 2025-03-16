# Enable some optimizations (not applicable in Python)
import sys  # Standard input/output library
from math import isclose  # Mathematical functions library

mod = 1000000007  # Modulus constant
mod9 = 998244353  # Modulus constant
eps = 1e-7  # Small epsilon value
INF = float('inf')  # Maximum integer constant
N = int(1e5 + 7)  # Maximum number of elements in the input

tc, n, m = map(int, sys.stdin.readline().split())  # Read input

# Check if 'n' is greater than 'm' and swap them if necessary
if n > m:
    n, m = m, n

fl = 0  # Flag variable

# Iterate through each possible value of 'i' from 1 to 'm'
for i in range(1, m + 1):
    # Check if 'i' multiplied by 'tc' is within the range of 'n' to 'm'
    if n <= i * tc <= m:
        # If so, print "OK" and set the flag 'fl' to 1
        print("OK")
        fl = 1
        # Break out of the loop since we have found the answer
        break

# If the flag 'fl' is still 0, print "NG"
if fl == 0:
    print("NG")

# End of the code
# <END-OF-CODE>
