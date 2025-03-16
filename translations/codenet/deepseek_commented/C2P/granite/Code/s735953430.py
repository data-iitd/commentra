
import sys

# Step 1: Reading Input
X, N = map(int, sys.stdin.readline().split())

# If no values are excluded, print X and exit
if N == 0:
    print(X)
    sys.exit(0)

# Step 2: Initializing Arrays
plus = [i for i in range(256)]
minus = [-i for i in range(256)]

# Step 3: Marking Excluded Values
for _ in range(N):
    j = int(sys.stdin.readline())
    plus[j] = 0

# Step 4: Finding the Nearest Non-Zero Value
i_min = 0
min = 1000
for i in range(255, -1, -1):
    if plus[i] == 0 and i > 0:
        continue
    k = X - plus[i]
    if k < 0:
        k *= -1
    if k <= min:
        min = k
        i_min = i

# Step 5: Outputting the Result
print(i_min)

