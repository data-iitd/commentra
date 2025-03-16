

import sys

# Function to read an integer from standard input
def nextint():
    c = sys.stdin.read(1)
    while c!= '-' and (c < '0' or '9' < c):
        c = sys.stdin.read(1)
    s = False
    if c == '-':
        s = True
        c = sys.stdin.read(1)
    x = 0
    while '0' <= c and c <= '9':
        x = x * 10 + ord(c) - ord('0')
        c = sys.stdin.read(1)
    return -x if s else x

n = nextint()

# Function to calculate the result of the given expression p(a, b)
def p(a, b):
    # Check if a is smaller than b
    if a < b:
        return a + b * n
    else:
        return b + a * n

# 2D array a of size n x (n-1)
a = [[0] * (n - 1) for _ in range(n)]
for i in range(n):
    for j in range(n - 1):
        # Read an edge weight from standard input and store it in the corresponding position of array a
        a[i][j] = nextint() - 1

# Arrays e1, e2 and d of size 1000000 each
e1 = [0] * 1000000
e2 = [0] * 1000000
d = [0] * 1000000

# Boolean array b of size 1000000
b = [False] * 1000000

# Function to perform Depth First Search (DFS) from a given vertex 'from'
def f(from):
    # Check if vertex 'from' has already been visited
    if b[from]:
        return -1
    # If vertex 'from' has already been processed, return its depth
    if d[from]:
        return d[from]
    # Mark vertex 'from' as visited
    b[from] = True
    # Initialize maximum depth as 0
    max = 0
    # Traverse to the adjacent vertices of 'from'
    to = e1[from]
    # If the adjacent vertex 'to' is not yet visited, perform DFS recursively and update the maximum depth
    if to!= 0:
        now = f(to)
        if now < 0:
            return now
        if now > max:
            max = now
    # Traverse to the next adjacent vertex of 'from'
    to = e2[from]
    # If the adjacent vertex 'to' is not yet visited, perform DFS recursively and update the maximum depth
    if to!= 0:
        now = f(to)
        if now < 0:
            return now
        if now > max:
            max = now
    # Mark vertex 'from' as not visited
    b[from] = False
    # Update the depth of vertex 'from' with the maximum depth found during DFS
    return d[from] = max + 1

ans = 0
# Perform Depth First Search from each vertex and update the answer with the maximum depth found
for i in range(n):
    from_ = p(i, a[i][0])
    now = f(from_)
    if now < 0:
        ans = -1
        break
    if now > ans:
        ans = now

# Print the answer
print(ans)

