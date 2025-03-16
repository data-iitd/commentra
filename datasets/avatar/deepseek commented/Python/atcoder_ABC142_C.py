
from operator import itemgetter

# Input the number of elements (N)
N = int(input())

# Input the elements and create a list of tuples
A = [(i + 1, int(x)) for i, x in enumerate(input().split())]

# Sort the list of tuples based on the integer values
A_ = sorted(A, key=itemgetter(1))

# Extract the indices from the sorted list of tuples
A__ = [a[0] for a in A_]

# Print the indices in the required format
for i in A__[:-1]:
    print(i, end=' ')
print(A__[-1])

