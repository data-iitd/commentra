# Import necessary libraries
import numpy as np
import itertools

# Take input dimensions and threshold from user
n, m, x = list(map(int, input().split()))

# Initialize numpy array 'c' with dimensions (n, m)
c = np.array([list(map(int, input().split())) for _ in range(n)])

# Initialize empty lists 'l' for storing combinations and 'rem' for storing indices
l = []
rem = []

# Initialize variable 'ans' for storing minimum number of tests
ans = 0

# Loop through all possible combinations of 'pre' indices
for i in range(len(pre) + 1):
    # Generate all combinations of 'pre' indices of size 'i'
    for j in itertools.combinations(pre, i):
        # Append the combination to list 'l'
        l.append(list(j))

# Loop through each iteration 'i' of test cases
for i in range(1, m + 1):
    # Initialize variable 'ca' to 0 for sum of tests in current combination
    ca = 0

    # Loop through each index 'j' in current combination
    for j in l[i]:
        # Add the test result at index 'j' and test case 'i' to 'ca'
        ca += c[j, i]

    # If the sum of tests in current combination is less than threshold 'x',
    # add the index of the current combination to 'rem' list
    if ca < x:
        rem.insert(0, i)
    # If the sum of tests in current combination is greater than or equal to threshold 'x',
    # continue to next combination
    else:
        pass

    # If 'rem' list is not empty, remove the combinations with indices in 'rem' from 'l' list
    if len(rem) > 0:
        for j in rem:
            l.pop(j)
        rem = []

    # If 'l' list is empty, print -1 and break the loop
    if len(l) == 0:
        print(-1)
        break

# If the loop completes without finding a valid combination,
# calculate the minimum number of tests in all valid combinations
else:
    # Initialize variable 'ca' to 0 for sum of tests in current combination
    ca = 0

    # Loop through each valid combination and calculate the sum of tests
    for i in l:
        ca = 0
        for j in i:
            ca += c[j, 0]

        # Update 'ans' with minimum number of tests among all valid combinations
        if ans == 0:
            ans = ca
        else:
            ans = min(ans, ca)

    # Print the minimum number of tests required
    print(ans)
