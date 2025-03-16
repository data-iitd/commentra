
n = int(input())  # Take an integer input `n`
import itertools  # Import the itertools module
orig = list(itertools.permutations(list(range(1, n + 1))))  # Generate all permutations of numbers from 1 to `n`
p = tuple(map(int, input().split()))  # Take the first permutation `p` as a tuple of integers
q = tuple(map(int, input().split()))  # Take the second permutation `q` as a tuple of integers
pn = orig.index(p)  # Find the index of permutation `p` in the list of all permutations
qn = orig.index(q)  # Find the index of permutation `q` in the list of all permutations
print(abs(pn - qn))  # Calculate the absolute difference between the indices and print the result

