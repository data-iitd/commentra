# Set the recursion limit for the function call stack to 1 million
import sys
sys.setrecursionlimit(10 ** 6)

# Define the depth-first search function 'dfs'
def dfs(links, n, k, v, p):
    # Initialize variables for height from leaf node and cut count
    height_from_leaf = 0
    cut_count = 0

    # Iterate through neighbors of the current node 'v'
    for u in links[v]:
        # Skip if the neighbor is not a valid node (0)
        if u == 0:
            continue

        # Recursively call the 'dfs' function for the neighbor 'u'
        hgt, cut = dfs(links, n, k, u, v)

        # Update the height from leaf and cut count
        height_from_leaf = max(height_from_leaf, hgt)
        cut_count += cut

    # Update the height from leaf and cut count for the current node 'v'
    height_from_leaf += 1

    # If the parent node 'p' is not 0 and the height from leaf is equal to 'k',
    # then this node is a cut vertex and we need to add 1 to the cut count
    if p != 0 and height_from_leaf == k:
        height_from_leaf = 0
        cut_count += 1

    # Return the height from leaf and cut count for the current node 'v'
    return height_from_leaf, cut_count

# Read input from standard input
n, k, * aaa = map(int, sys.stdin.buffer.read().split())

# Initialize the 'links' list with sets for each node
links = [set() for _ in range(n)]

# Process the input edges and add them to the 'links' list
for i, a in enumerate(aaa):
    a -= 1
    links[a].add(i)

# Call the 'dfs' function with the initial parameters
_, ans = dfs(links, n, k, 0, 0)

# If the first node is not a root node, add 1 to the answer
if aaa[0] != 1:
    ans += 1

# Print the final answer
print(ans)
