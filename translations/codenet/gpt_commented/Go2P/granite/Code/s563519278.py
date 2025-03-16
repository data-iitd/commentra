
import sys

# Read the integer N from standard input
N = int(input())

# Initialize a list v of size N to hold counts of occurrences
v = [0] * N

# Loop through the range from 1 to N-1 to read N-1 integers
for i in range(1, N):
    # Read the next integer from standard input
    a = int(input())
    # Increment the count at the index corresponding to the value read (adjusted for 0-based index)
    v[a-1] += 1

# Loop through the list v to print the counts of occurrences
for e in v:
    # Print each count to standard output
    print(e)

# End of code
