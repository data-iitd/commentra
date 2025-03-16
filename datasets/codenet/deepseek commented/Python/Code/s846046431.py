
#ABC161B
import sys

# Read two integers N and M from the standard input
N, M = map(int, sys.stdin.readline().split())

# Read N integers from the standard input and store them in a list A
A = list(map(int, sys.stdin.readline().split()))

# Sort the list A in descending order
A.sort(reverse=True)

# Calculate the sum of the elements in A and store it in the variable S
S = sum(A)

# Iterate over the first M elements of A
for a in A[:M]:
    # Check if each element divided by S minus 1 over 4M is less than 0
    if a/S - 1/(4*M) < 0:
        # If any element does not satisfy the condition, print 'No' and break out of the loop
        print('No')
        break
# If all elements satisfy the condition, print 'Yes'
else:
    print('Yes')

