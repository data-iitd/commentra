import sys
from collections import deque

# Read input from standard input
input = sys.stdin.buffer.readline

# Read the number of nodes in the tree
N = int(input())

# Initialize adjacency list for the tree
adj = [[] for _ in range(N + 1)]

# Read edges and build the adjacency list
for _ in range(N - 1):
    a, b = map(int, input().split())
    adj[a].append(b)
    adj[b].append(a)

# Initialize a queue for BFS and mark the starting node
que = deque()
que.append(1)

# Array to keep track of visited nodes
seen = [0] * (N + 1)
seen[1] = 1  # Mark the root node as seen

# Array to store parent of each node
par = [0] * (N + 1)

# Array to count the number of children for each node
child_num = [0] * (N + 1)

# Perform BFS to populate parent and child count information
while que:
    v = que.popleft()  # Get the current node
    for u in adj[v]:  # Iterate through adjacent nodes
        if seen[u] == 0:  # If the node has not been visited
            seen[u] = 1  # Mark it as seen
            par[u] = v  # Set the parent of the node
            child_num[v] += 1  # Increment the child count for the parent
            que.append(u)  # Add the node to the queue for further exploration

# Initialize a deque to process leaf nodes
seq = deque()

# Identify all leaf nodes (nodes with no children)
for i in range(1, N + 1):
    if child_num[i] == 0:
        seq.append(i)

# Process the leaf nodes in reverse order
while seq:
    c = seq.pop()  # Get the current leaf node
    seen[c] = 0  # Mark the leaf node as unseen
    if seen[par[c]] == 0:  # Check if the parent is unseen
        print('First')  # If so, print 'First' and exit
        exit()
    seen[par[c]] = 0  # Mark the parent as unseen
    child_num[par[par[c]]] -= 1  # Decrement the child count of the grandparent
    if child_num[par[par[c]]] == 0:  # If the grandparent has no children left
        seq.append(par[par[c]])  # Add the grandparent to the sequence for processing

# If all nodes are processed without triggering 'First', print 'Second'
print('Second')
