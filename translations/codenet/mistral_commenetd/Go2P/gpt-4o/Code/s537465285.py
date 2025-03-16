import sys
from collections import deque

# Function to read a single line from standard input
def next_line():
    return sys.stdin.readline().strip()

# Function to read an integer from standard input
def next_int():
    return int(next_line())

# Function to check if a given graph is bipartite
def is_bipartite(graph):
    N = len(graph)
    D = [0] * N
    D[0] = 1
    queue = deque([0])
    ret = True

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

# Function to find the shortest distance between all pairs of vertices using Floyd-Warshall algorithm
def warshall_floyd(graph):
    N = len(graph)
    G = [[float('inf')] * N for _ in range(N)]
    
    for i in range(N):
        for j in range(N):
            if i == j:
                G[i][j] = 0
            elif graph[i][j] == '1':
                G[i][j] = 1

    for k in range(N):
        for i in range(N):
            for j in range(N):
                if G[i][k] + G[k][j] < G[i][j]:
                    G[i][j] = G[i][k] + G[k][j]

    ans = 0
    for i in range(N):
        for j in range(N):
            if ans < G[i][j] and G[i][j] != float('inf'):
                ans = G[i][j]

    return ans + 1

# Main function
def main():
    N = next_int()
    graph = [next_line() for _ in range(N)]

    if not is_bipartite(graph):
        print(-1)
    else:
        print(warshall_floyd(graph))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
