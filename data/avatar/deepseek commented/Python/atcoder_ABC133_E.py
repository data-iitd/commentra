from collections import defaultdict
import sys
sys.setrecursionlimit(10 ** 7)  # Set recursion limit to prevent stack overflow

graph = defaultdict(list)  # Initialize a defaultdict to store the graph
N, K = map(int, input().split())  # Read the number of nodes and the number of colors

# Construct the graph by reading edges
for i in range(N - 1):
    a, b = map(int, input().split())
    graph[a - 1].append(b - 1)  # Append the edge to the graph
    graph[b - 1].append(a - 1)  # Since the graph is undirected, append the reverse edge as well

mod = 10 ** 9 + 7  # Set the modulo value to prevent overflow

# Define the DFS function to calculate the number of valid colorings
def dfs(fro, to, f):
    caseNum = f  # Initialize the number of valid colorings with the initial number of colors
    colorNum = K - 1 if f == K else K - 2  # Set the number of available colors for the current node
    for u in graph[fro]:
        if u == to:
            continue  # Skip if the neighbor is the parent node
        pat = dfs(u, fro, colorNum)  # Recursively call dfs for the neighbor
        if pat == 0:
            caseNum = 0  # If no valid colorings, set the current number to 0
            break  # Break out of the loop as further calculations are unnecessary
        caseNum = caseNum * pat % mod  # Multiply the current number of valid colorings by the recursive result
        colorNum -= 1  # Decrease the number of available colors for the next node
    return caseNum  # Return the number of valid colorings for the current node

ans = dfs(0, -1, K)  # Call the dfs function starting from the root node with the initial number of colors
print(ans)  # Print the final result
