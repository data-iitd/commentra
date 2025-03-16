import sys
from collections import deque

# Function to read the next line from standard input
def next_line():
    return sys.stdin.readline().strip()

# Function to read the next integer from standard input
def next_int():
    return int(next_line())

# Function to check if the graph is bipartite
def is_bipartite(S):
    N = len(S)  # Get the number of nodes
    D = [0] * N  # Distance array to store levels of nodes
    D[0] = 1  # Start with the first node at level 1
    queue = deque([0])  # Queue for BFS

    # Perform BFS to check for bipartiteness
    while queue:
        q = queue.popleft()  # Current node
        for j, s in enumerate(S[q]):
            if s == '0':
                continue  # Skip if there is no edge
            if D[j] == 0:
                # Assign level to the adjacent node
                D[j] = D[q] + 1
                queue.append(j)  # Add to queue
            elif D[j] % 2 == D[q] % 2:
                return False  # Not bipartite
    return True  # Return the result of bipartiteness check

# Function to perform the Floyd-Warshall algorithm to find the longest shortest path
def warshall_floyd(S):
    N = len(S)  # Get the number of nodes
    G = [[float('inf')] * N for _ in range(N)]  # Initialize the graph matrix

    # Initialize the graph with distances
    for i in range(N):
        for j in range(N):
            if i == j:
                G[i][j] = 0  # Distance to self is 0
            elif S[i][j] == '1':
                G[i][j] = 1  # Edge exists, set distance to 1

    # Floyd-Warshall algorithm to find shortest paths
    for k in range(N):
        for i in range(N):
            for j in range(N):
                if G[i][k] + G[k][j] < G[i][j]:
                    G[i][j] = G[i][k] + G[k][j]  # Update shortest path

    # Find the maximum distance in the graph
    ans = 0
    for i in range(N):
        for j in range(N):
            if G[i][j] < float('inf'):
                ans = max(ans, G[i][j])  # Update maximum distance
    return ans + 1  # Return the maximum distance found

# Main function to execute the program
def main():
    N = next_int()  # Read the number of nodes
    S = [next_line() for _ in range(N)]  # Initialize the adjacency matrix

    # Check if the graph is bipartite and process accordingly
    if not is_bipartite(S):
        print(-1)  # Output -1 if not bipartite
    else:
        print(warshall_floyd(S))  # Output the longest shortest path if bipartite

if __name__ == "__main__":
    main()  # Execute the main function

# <END-OF-CODE>
