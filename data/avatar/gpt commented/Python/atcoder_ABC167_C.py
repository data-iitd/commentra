import numpy as np
import itertools

# Read input values for n (number of items), m (number of categories), and x (threshold value)
n, m, x = list(map(int, input().split()))

# Read the cost matrix where each row corresponds to an item and each column to a category
c = np.array([list(map(int, input().split())) for _ in range(n)])

# Create an array of indices for the items
pre = np.arange(n)

# Initialize lists to hold combinations and to track remaining combinations
l = []
rem = []

# Initialize the answer variable to store the minimum cost
ans = 0

# Generate all possible combinations of items of varying lengths
for i in pre + 1:
    for j in itertools.combinations(pre, i):
        l.append(list(j))

# Iterate over each category from 1 to m
for i in range(1, m + 1):
    # Check each combination of items
    for j, k in enumerate(l):
        ca = 0  # Initialize cumulative cost for the current combination
        # Calculate the total cost for the current combination in the current category
        for ii in k:
            ca += c[ii, i]
        
        # If the total cost is less than the threshold x, mark this combination for removal
        if ca < x:
            rem.insert(0, j)
        else:
            pass
    
    # Remove combinations that did not meet the cost requirement
    if len(rem) > 0:
        for j in rem:
            l.pop(j)
        rem = []  # Reset the remaining combinations list

    # If no valid combinations remain, print -1 and exit
    if len(l) == 0:
        print(-1)
        break
else:
    # If valid combinations remain, calculate the minimum cost for the first category
    for i in l:
        ca = 0  # Initialize cumulative cost for the current combination
        # Calculate the total cost for the current combination in the first category
        for j in i:
            ca += c[j, 0]
        
        # Update the answer with the minimum cost found
        if ans == 0:
            ans = ca
        else:
            ans = min(ans, ca)
    
    # Print the minimum cost found
    print(ans)
