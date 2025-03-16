# Declare variables for the number of nodes (n) and edges (m)
n, m = map(int, input().split())

# Initialize an array to track connections (r0) and set all values to false
r0 = [False] * n

# Initialize an array to store nodes connected to node n (r1) and a counter for it
r1 = []
nr1 = 0

# Process each edge input
for i in range(m):
    a, b = map(int, input().split())
    
    # Ensure a is the smaller node and b is the larger node
    if a > b:
        a, b = b, a
    
    # Mark the connection from node a to node b in r0
    if a == 1:
        r0[b - 1] = True
    
    # If b is the last node (n), store a-1 in r1
    if b == n:
        r1.append(a - 1)
        nr1 += 1

# Initialize a result variable to determine if a connection is possible
res = False

# Check if any of the nodes connected to node n are also connected to node 1
for i in range(nr1):
    if r0[r1[i]]:
        res = True

# Output the result based on the value of res
print("POSSIBLE" if res else "IMPOSSIBLE")

# 