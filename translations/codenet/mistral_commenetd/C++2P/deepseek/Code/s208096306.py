import sys
from math import gcd

# Read the number of integers 'n' from the standard input
n = int(input().strip())

# Read the first integer 'ans' from the standard input and store it in the variable 'ans'
ans = int(input().strip())

# Read and process the remaining integers
for _ in range(n - 1):
    # Read the next integer 'a' from the standard input and store it in the variable 'a'
    a = int(input().strip())

    # Update the answer by finding the GCD of the current answer and the new integer 'a'
    ans = gcd(ans, a)

# Print the final answer to the standard output
print(ans)
