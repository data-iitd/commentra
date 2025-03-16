import sys

# Set the maximum recursion limit to handle deep recursions
sys.setrecursionlimit(10 ** 6)

def dfs(links, n, k, v, p):
    # Initialize height from the leaf node and cut count
    height_from_leaf = 0
    cut_count = 0
    
    # Iterate through all connected nodes (children) of the current node
    for u in links[v]:
        # Skip if the child node is 0 (indicating no further connections)
        if u == 0:
            continue
        
        # Recursively perform DFS on the child node and get its height and cut count
        hgt, cut = dfs(links, n, k, u, v)
        
        # Update the maximum height from the leaf node
        height_from_leaf = max(height_from_leaf, hgt)
        
        # Accumulate the cut count from the child nodes
        cut_count += cut
    
    # Increment the height from the leaf node as we return to the parent
    height_from_leaf += 1
    
    # Check if the current height matches k and we are not at the root node
    if p != 0 and height_from_leaf == k:
        # Reset height from leaf to 0 and increment cut count
        height_from_leaf = 0
        cut_count += 1
    
    # Return the height from the leaf and the total cut count
    return height_from_leaf, cut_count

# Read input values for n (number of nodes), k (target height), and the rest of the connections
n, k, *aaa = map(int, sys.stdin.buffer.read().split())

# Create a list of sets to represent the graph (tree) connections
links = [set() for _ in range(n)]

# Populate the links based on the input connections
for i, a in enumerate(aaa):
    a -= 1  # Adjust for 0-based indexing
    links[a].add(i)

# Perform DFS starting from the root node (0) and get the total cuts
_, ans = dfs(links, n, k, 0, 0)

# If the first node is not the root, increment the answer
if aaa[0] != 1:
    ans += 1

# Print the final answer (total cuts)
print(ans)
