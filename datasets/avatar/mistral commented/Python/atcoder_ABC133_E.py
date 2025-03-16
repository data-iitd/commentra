#######
# Import necessary modules and set recursion limit
#######
import sys
sys.setrecursionlimit(10 ** 7)

#######
# Initialize an empty graph using defaultdict
#######
from collections import defaultdict
graph = defaultdict(list)

#######
# Read input: number of nodes N and color limit K
#######
N, K = map(int, input().split())

#######
# Read edges between nodes and add them to the graph
#######
for i in range(N - 1):
    a, b = map(int, input().split())
    graph[a - 1].append(b - 1)
    graph[b - 1].append(a - 1)

#######
# Define a recursive function dfs to calculate the answer
#######
mod = 10 ** 9 + 7
def dfs(fro, to, f):
    """
    Calculate the answer using Depth First Search.

    Parameters:
    fro (int): The current node.
    to (int): The target node.
    f (int): The current color.

    Returns:
    int: The number of ways to color the graph.
    """

    # Initialize case number and color number
    caseNum = 1 if f == K else 0
    colorNum = K - 1 if f == K else K - 2

    # Iterate through the neighbors of the current node
    for u in graph[fro]:
        # Skip the target node
        if u == to:
            continue

        # Recursively call dfs on the neighbor and update case number
        pat = dfs(u, fro, colorNum)
        if pat == 0:
            caseNum = 0
            break
        caseNum = caseNum * pat % mod
        colorNum -= 1

    # Return the final case number
    return caseNum

#######
# Call the dfs function with initial values and print the result
#######
ans = dfs(0, -1, K)
print(ans)
