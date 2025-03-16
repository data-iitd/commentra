# Import necessary modules
import sys
from collections import deque

# Set the maximum recursion limit
sys.setrecursionlimit(10 ** 9)

# Define constant value for INF
INF = 10 ** 18

# Define a custom input function
def input():
    return sys.stdin.readline().rstrip()

# Define the main function
def main():
    # Read input values for N and M
    N, M = map(int, input().split())

    # Initialize an empty list for edge
    edge = [ [ ] for _ in range(N) ]

    # Read edges and add them to the edge list
    for _ in range(M):
        X, Y, Z = map(lambda x: int(x) - 1, input().split())
        edge[X].append(Y)
        edge[Y].append(X)

    # Initialize a list of boolean values for used nodes
    used = [False] * N

    # Initialize a variable for answer
    ans = 0

    # Iterate through all nodes
    for i in range(N):
        # If the current node is not used
        if not used[i]:
            # Increment the answer
            ans += 1
            # Initialize a queue for DFS traversal
            queue = deque()
            # Add the current node to the queue
            queue.append(i)
            # Traverse through the graph using DFS
            while queue:
                # Get the next node from the queue
                node = queue.popleft()
                # Mark the current node as used
                used[node] = True
                # Traverse through the neighbors of the current node
                for nextnode in edge[node]:
                    # If the neighbor is not used
                    if not used[nextnode]:
                        # Add the neighbor to the queue
                        queue.append(nextnode)

    # Print the answer
    print(ans)

# Run the main function if the script is run directly
if __name__ == '__main__':
    main()
