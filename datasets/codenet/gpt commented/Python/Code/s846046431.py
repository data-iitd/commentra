# ABC161B
import sys

# Read the number of elements (N) and the number of top elements to consider (M)
N, M = map(int, sys.stdin.readline().split())

# Read the list of integers and store them in A
A = list(map(int, sys.stdin.readline().split()))

# Sort the list A in descending order
A.sort(reverse=True)

# Calculate the sum of all elements in A
S = sum(A)

# Check if the top M elements meet the specified condition
for a in A[:M]:
    # If the condition is not met, print 'No' and exit the loop
    if a/S - 1/(4*M) < 0:
        print('No')
        break
else:
    # If all top M elements meet the condition, print 'Yes'
    print('Yes')
