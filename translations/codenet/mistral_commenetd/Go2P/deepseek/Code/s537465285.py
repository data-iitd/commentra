import sys
import io
import os
import math

# Initialize reader and writer
input_stream = io.TextIOWrapper(sys.stdin.buffer, encoding='utf-8')
output_stream = io.TextIOWrapper(sys.stdout.buffer, encoding='utf-8')

# Function to read a single line from standard input
def NextLine():
    return input_stream.readline().strip()

# Function to read an integer from standard input
def NextInt():
    return int(NextLine())

# Function to write a value to standard output
def Write(s):
    output_stream.write(str(s) + '\n')

# Function to flush the writer buffer
def Output():
    output_stream.flush()

# Function to check if a given graph is bipartite
def Bipartite(S):
    # Initialize number of vertices
    N = len(S)

    # Initialize degree array
    D = [0] * N
    D[0] = 1

    # Initialize queue
    Q = []

    # Initialize result
    ret = True

    # Iterate over each vertex
    for i in range(N):
        if not ret:
            break

        # Get current vertex
        q = Q[i] if i < len(Q) else i

        # Iterate over each neighbor of the current vertex
        for j, s in enumerate(S[q]):
            if s == '0':
                continue

            # If neighbor is not visited yet
            if D[j] == 0:
                # Mark neighbor as visited
                D[j] = D[q] + 1

                # Add neighbor to queue
                Q.append(j)

                # Continue to next neighbor
                continue

            # If degrees of current and neighbor are different
            if D[j] % 2 != D[q] % 2:
                # Graph is not bipartite
                ret = False
                break

    # Return result
    return ret

# Function to find the shortest distance between all pairs of vertices using Floyd-Warshall algorithm
def WarshallFloyd(S):
    # Initialize number of vertices
    N = len(S)

    # Initialize adjacency matrix
    G = [[float('inf') if i != j else 0 for j in range(N)] for i in range(N)]
    for i in range(N):
        for j in range(N):
            if S[i][j] == '1':
                G[i][j] = 1

    # Iterate over all vertices k
    for k in range(N):
        # Iterate over all vertices i
        for i in range(N):
            # Iterate over all vertices j
            for j in range(N):
                # Update shortest distance if found
                G[i][j] = min(G[i][j], G[i][k] + G[k][j])

    # Initialize answer as maximum distance
    ans = 0

    # Iterate over all vertices i
    for i in range(N):
        # Iterate over all vertices j
        for j in range(N):
            # Update answer if found
            ans = max(ans, G[i][j])

    # Return answer plus one
    return ans + 1

# Main function
def main():
    # Read number of vertices
    N = NextInt()

    # Initialize graph
    S = [NextLine() for _ in range(N)]

    # Check if graph is bipartite
    if not Bipartite(S):
        # Write -1 if graph is not bipartite
        Write(-1)
    else:
        # Write shortest distance between all pairs of vertices
        Write(WarshallFloyd(S))

    # Flush writer buffer
    Output()

# Call main function
main()

