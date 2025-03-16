import sys
from collections import deque

# Set the recursion limit to a high value to handle deep recursions if needed
sys.setrecursionlimit(10 ** 9)

# Define a constant for infinity
INF = 10 ** 18

# Function to read input from standard input
def input():
    return sys.stdin.readline().rstrip()

def main():
    # Read the number of nodes (N) and edges (M)
    N, M = map(int, input().split())
    
    # Initialize an adjacency list to represent the graph
    edge = [[] for _ in range(N)]
    
    # Read each edge and populate the adjacency list
    for i in range(M):
        X, Y, Z = map(lambda x: int(x) - 1, input().split())
        edge[X].append(Y)
        edge[Y].append(X)
    
    # Array to track visited nodes
    used = [False] * N
    
    # Variable to count the number of connected components
    ans = 0
    
    # Iterate through each node to find connected components
    for i in range(N):
        if not used[i]:  # If the node has not been visited
            ans += 1  # Increment the count of connected components
            queue = deque()  # Initialize a queue for BFS
            queue.append(i)  # Start BFS from the current node
            
            # Perform BFS to mark all reachable nodes from the current node
            while queue:
                node = queue.popleft()  # Dequeue a node
                used[node] = True  # Mark the node as visited
                
                # Explore all adjacent nodes
                for nextnode in edge[node]:
                    if not used[nextnode]:  # If the adjacent node has not been visited
                        queue.append(nextnode)  # Enqueue the adjacent node
    
    # Output the number of connected components found
    print(ans)

# Entry point of the program
if __name__ == '__main__':
    main()
