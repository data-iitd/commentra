#ABC161B
# This script is for solving problem ABC161B
import sys

# Read input
N, M = map(int, sys.stdin.readline().split())
# Read and store numbers in a list
A = list(map(int, sys.stdin.readline().split()))
# Sort the list in descending order
A.sort(reverse=True)

# Calculate the sum of all numbers in the list
S = sum(A)

# Check if the condition is met
for a in A[:M]:
    # Calculate a/S and 1/(4*M)
    if a/S - 1/(4*M) < 0:
        # If the condition is not met, print 'No' and break the loop
        print('No')
        break
# If the loop finishes without breaking, it means the condition is met
else:
    # Print 'Yes'
    print('Yes')
