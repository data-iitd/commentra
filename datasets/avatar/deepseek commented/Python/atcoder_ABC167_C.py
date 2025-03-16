import numpy as np
import itertools
# Read the number of books (n), the number of skills (m), and the minimum skill level required (x)
n, m, x = list(map(int, input().split()))

# Read the cost matrix where each row represents a book and columns represent cost and skill levels
c = np.array([list(map(int, input().split())) for _ in range(n)])

# Initialize a range array to help generate combinations
pre = np.arange(n)

# Initialize lists to store combinations and removable combinations
l = []
rem = []

# Initialize the answer variable to store the minimum cost
ans = 0

# Generate all possible combinations of books using itertools.combinations
for i in pre + 1:
    for j in itertools.combinations(pre, i):
        l.append(list(j))

# Check each combination to see if the total cost meets the requirement and adjust the list accordingly
for i in range(1, m + 1):
    for j, k in enumerate(l):
        ca = 0
        for ii in k:
            ca += c[ii, i]
        if ca < x:
            rem.insert(0, j)
        else:
            pass
    if len(rem) > 0:
        for j in rem:
            l.pop(j)
        rem = []
    if len(l) == 0:
        print(-1)
        break
else:
    # Find the minimum cost among the valid combinations
    for i in l:
        ca = 0
        for j in i:
            ca += c[j, 0]
        if ans == 0:
            ans = ca
        else:
            ans = min(ans, ca)
    print(ans)
