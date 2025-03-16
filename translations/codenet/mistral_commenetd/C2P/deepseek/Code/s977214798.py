import sys

# Function to read an integer from standard input
def nextint():
    c = sys.stdin.read(1)
    while c not in ['-', ' ', '\n'] and not c.isdigit():
        c = sys.stdin.read(1)
    if c == '-':
        s = True
        c = sys.stdin.read(1)
    else:
        s = False
    x = 0
    while c.isdigit():
        x = x * 10 + int(c)
        c = sys.stdin.read(1)
    return -x if s else x

n = 0

# Function to calculate the result of the given expression p(a, b)
def p(a, b):
    # Check if a is smaller than b
    if a < b:
        return a + b * n
    else:
        return b + a * n

# 2D array a of size n x (n-1)
a = [[0] * (n - 1) for _ in range(n)]

# Arrays e1, e2 and d of size 1000000 each
e1 = [0] * 1000000
e2 = [0] * 1000000
d = [0] * 1000000

# Boolean array b of size 1000000
b = [False] * 1000000

# Function to perform Depth First Search (DFS) from a given vertex 'from'
def f(from_):
    # Check if vertex 'from' has already been visited
    if b[from_]:
        return -1
    # If vertex 'from' has already been processed, return its depth
    if d[from_]:
        return d[from_]
    # Mark vertex 'from' as visited
    b[from_] = True
    # Initialize maximum depth as 0
    max_ = 0
    # Traverse to the adjacent vertices of 'from'
    to = e1[from_]
    # If the adjacent vertex 'to' is not yet visited, perform DFS recursively and update the maximum depth
    if to != 0:
        now = f(to)
        if now < 0:
            return now
        if now > max_:
            max_ = now
    # Traverse to the next adjacent vertex of 'from'
    to = e2[from_]
    # If the adjacent vertex 'to' is not yet visited, perform DFS recursively and update the maximum depth
    if to != 0:
        now = f(to)
        if now < 0:
            return now
        if now > max_:
            max_ = now
    # Mark vertex 'from' as not visited
    b[from_] = False
    # Update the depth of vertex 'from' with the maximum depth found during DFS
    d[from_] = max_ + 1
    return d[from_]

# Read the number of vertices n from standard input
n = nextint()

# Initialize 2D array a of size n x (n-1)
for i in range(n):
    for j in range(n - 1):
        # Read an edge weight from standard input and store it in the corresponding position of array a
        a[i][j] = nextint() - 1

# Initialize arrays e1, e2 and d with zeros
for i in range(n):
    for j in range(n - 2):
        # Read an edge from standard input and store it in the corresponding position of arrays e1 or e2 based on its direction
        from_ = p(i, a[i][j])
        to = p(i, a[i][j + 1])
        if e1[from_] == 0:
            e1[from_] = to
        elif e2[from_] == 0:
            e2[from_] = to
        else:
            # If there is a cycle in the graph, print '-1' and exit the program
            print(-1)
            sys.exit(0)

# Initialize an empty stack or array to store the vertices in Depth First Search order
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
