import sys
import io
import os

# Initialize buffered reader and writer for input and output
input_stream = io.TextIOWrapper(sys.stdin.buffer, write_through=True)
output_stream = io.TextIOWrapper(sys.stdout.buffer, write_through=True)

# Function to read the next line from standard input
def next_line():
    return input_stream.readline().decode().strip()

# Function to read the next integer from standard input
def next_int():
    return int(next_line())

# Function to write output to standard output
def write(s):
    output_stream.write(f"{s}\n")

# Function to check if the graph is bipartite
def bipartite(S):
    N = len(S)  # Get the number of nodes
    D = [0] * N  # Distance array to store levels of nodes
    D[0] = 1  # Start with the first node at level 1
    Q = [0] * N  # Queue for BFS
    ret = True  # Variable to track if the graph is bipartite
    pos = 0  # Position in the queue

    # Perform BFS to check for bipartiteness
    for i in range(N):
        if not ret:
            break  # Exit if already determined not bipartite
        q = Q[i]  # Current node
        for j, s in enumerate(S[q]):
            if s == '0':
                continue  # Skip if there is no edge
            if D[j] == 0:
                # Assign level to the adjacent node
                D[j] = D[q] + 1
                Q[pos] = j  # Add to queue
                pos += 1
                continue
            # Check if the adjacent node has the same level
            if D[j] % 2 == D[q] % 2:
                ret = False  # Not bipartite
                break
    return ret  # Return the result of bipartiteness check

# Function to perform the Floyd-Warshall algorithm to find the longest shortest path
def warshall_floyd(S):
    N = len(S)  # Get the number of nodes
    G = [[0] * N for _ in range(N)]  # Initialize the graph matrix

    # Initialize the graph with distances
    for i in range(N):
        for j in range(N):
            if i == j:
                continue  # Skip self-loops
            if S[i][j] == '0':
                G[i][j] = N  # No edge, set to a large value
            else:
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
            if ans < G[i][j]:
                ans = G[i][j]  # Update maximum distance
    return ans + 1  # Return the maximum distance found

# Main function to execute the program
def main():
    N = next_int()  # Read the number of nodes
    S = [next_line() for _ in range(N)]  # Read each line of the adjacency matrix

    # Check if the graph is bipartite and process accordingly
    if not bipartite(S):
        write(-1)  # Output -1 if not bipartite
    else:
        write(warshall_floyd(S))  # Output the longest shortest path if bipartite

# Call the main function
main()

