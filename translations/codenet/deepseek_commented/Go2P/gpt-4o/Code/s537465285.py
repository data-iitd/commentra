import sys
from collections import deque

# Function to read a line of input
def next_line():
    return sys.stdin.readline().strip()

# Function to read an integer from input
def next_int():
    return int(next_line())

# Function to check if a graph is bipartite
def is_bipartite(graph):
    N = len(graph)
    D = [0] * N  # Distance array
    D[0] = 1  # Start from the first vertex
    queue = deque([0])  # Queue for BFS
    ret = True  # Return value

    while queue and ret:
        q = queue.popleft()
        for j, s in enumerate(graph[q]):
            if s == '0':
                continue
            if D[j] == 0:
                D[j] = D[q] + 1
                queue.append(j)
            elif D[j] % 2 == D[q] % 2:
                ret = False
                break
    return ret

# Function to compute the shortest paths between all pairs of vertices
def warshall_floyd(graph):
    N = len(graph)
    G = [[float('inf')] * N for _ in range(N)]
    
    for i in range(N):
        for j in range(N):
            if i == j:
                G[i][j] = 0
            elif graph[i][j] == '1':
                G[i][j] = 1  # Direct edge weight

    for k in range(N):
        for i in range(N):
            for j in range(N):
                if G[i][k] + G[k][j] < G[i][j]:
                    G[i][j] = G[i][k] + G[k][j]  # Update shortest path

    ans = 0
    for i in range(N):
        for j in range(N):
            if ans < G[i][j] and G[i][j] != float('inf'):
                ans = G[i][j]  # Find the maximum distance

    return ans + 1  # Return the result

# Main function to execute the program
def main():
    N = next_int()
    S = [next_line() for _ in range(N)]
    
    if not is_bipartite(S):
        print(-1)  # If not bipartite, print -1
    else:
        print(warshall_floyd(S))  # Otherwise, compute and print the result

if __name__ == "__main__":
    main()

# <END-OF-CODE>
