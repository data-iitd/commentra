import sys
from math import gcd
from functools import reduce

# Read the number of integers.
n = int(input())

# Read the first integer and initialize the answer.
ans = int(input())

# Read the remaining integers, compute their GCD with the current answer,
# and update the answer accordingly.
for _ in range(1, n):
    a = int(input())
    ans = gcd(ans, a)

# Print the final result, which is the GCD of all the input integers.
print(ans)

# <END-OF-CODE>
