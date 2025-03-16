
import sys

# Step 1: Input Reading
n, c = map(int, input().split())

# Step 2: Vector Initialization
x = [0] * (n + 1)
v = [0] * (n + 1)

# Step 3: Reading Positions and Values
for i in range(1, n + 1):
    x[i], v[i] = map(int, input().split())

# Step 4: Calculate Total Value Moving Left
lefttotal = [0] * (n + 1)
for i in range(1, n + 1):
    lefttotal[i] = lefttotal[i - 1] + v[i]

# Step 5: Calculate Maximum Value Left
maxlefttotal = [0] * (n + 1)
for i in range(1, n + 1):
    maxlefttotal[i] = max(maxlefttotal[i - 1], lefttotal[i] - x[i])

# Step 6: Calculate Total Value Moving Right
righttotal = [0] * (n + 1)
for i in range(1, n + 1):
    righttotal[i] = righttotal[i - 1] + v[n - i + 1]

# Step 7: Calculate Maximum Value Right
maxrighttotal = [0] * (n + 1)
for i in range(1, n + 1):
    maxrighttotal[i] = max(maxrighttotal[i - 1], righttotal[i] - (c - x[n - i + 1]))

# Step 8: Calculate the Maximum Value
ans = 0
for i in range(1, n + 1):
    ans = max(ans, lefttotal[i] - x[i])
    ans = max(ans, lefttotal[i] - 2 * x[i] + maxrighttotal[n - i])
    ans = max(ans, righttotal[i] - (c - x[n - i + 1]))
    ans = max(ans, righttotal[i] - 2 * (c - x[n - i + 1]) + maxlefttotal[n - i])

# Step 9: Output the Result
print(ans)

