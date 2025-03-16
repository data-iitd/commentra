# Read an integer input n, which defines the range of numbers to permute
n = int(input())

# Import the itertools module to use its permutations function
import itertools

# Generate all possible permutations of the numbers from 1 to n
orig = list(itertools.permutations(list(range(1, n + 1))))

# Read the first permutation input as a tuple of integers
p = tuple(map(int, input().split()))

# Read the second permutation input as a tuple of integers
q = tuple(map(int, input().split()))

# Find the index of the first permutation in the list of all permutations
pn = orig.index(p)

# Find the index of the second permutation in the list of all permutations
qn = orig.index(q)

# Calculate and print the absolute difference between the two indices
print(abs(pn - qn))
