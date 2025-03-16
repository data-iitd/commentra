# Ask the user for the size of the permutation list
n = int(input())

# Import the itertools module for generating permutations
import itertools

# Create a list of all possible permutations of numbers from 1 to n
orig = list(itertools.permutations(list(range(1, n+1))))

# Ask the user for two permutations as tuples
p = tuple(map(int, input().split()))
q = tuple(map(int, input().split()))

# Find the indices of p and q in the orig list
pn = orig.index(p)
qn = orig.index(q)

# Print the absolute difference between the indices of p and q
print(abs(pn - qn))
