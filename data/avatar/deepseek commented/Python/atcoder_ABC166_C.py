# Step 1: Input the number of nodes (n) and the number of edges (m)
(n, m) = [int(x) for x in input().split()]

# Step 2: Create a list of positions (p) from 1 to n
p = [x for x in range(1, n + 1)]

# Step 3: Input the heights (h) of the nodes
h = [int(x) for x in input().split()]

# Step 4: Create a dictionary (hp) mapping positions to heights
hp = dict(zip(p, h))

# Step 5: Initialize a dictionary (path) to store the adjacency list of the graph
path = {i: [] for i in range(1, n + 1)}

# Step 6: Input the edges of the graph and populate the adjacency list
for i in range(m):
    (a, b) = [int(x) for x in input().split()]
    path[a].append(b)
    path[b].append(a)

# Step 7: Count the number of nodes that are the highest in their neighborhoods
c = 0
for i, v in path.items():
    f = 0
    for j in v:
        if hp[i] <= hp[j]:
            f = 1
            break
    if f == 0:
        c += 1

# Step 8: Output the count of such nodes
print(c)
