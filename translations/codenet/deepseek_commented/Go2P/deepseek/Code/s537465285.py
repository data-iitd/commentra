import sys
import io

# Read input from stdin
def input():
    return sys.stdin.readline().strip()

# Print output to stdout
def print(s):
    sys.stdout.write(str(s) + '\n')

# Bipartite checks if a graph is bipartite
def bipartite(S):
    N = len(S)
    D = [0] * N  # Distance array
    D[0] = 1  # Start from the first vertex
    Q = [0] * N  # Queue for BFS
    ret = True  # Return value
    pos = 1  # Position in the queue
    for i in range(N):
        q = Q[i]
        for j, s in enumerate(S[q]):
            if s == '0':
                continue
            if D[j] == 0:
                D[j] = D[q] + 1
                Q[pos] = j
                pos += 1
                continue
            if D[j] % 2 == D[q] % 2:
                ret = False
                break
        if not ret:
            break
    return ret

# WarshallFloyd computes the shortest paths between all pairs of vertices
def warshall_floyd(S):
    N = len(S)
    G = [[N if i == j else 1 if S[i][j] == '0' else 0 for j in range(N)] for i in range(N)]
    for k in range(N):
        for i in range(N):
            for j in range(N):
                if G[i][k] + G[k][j] < G[i][j]:
                    G[i][j] = G[i][k] + G[k][j]  # Update shortest path
    ans = max(max(row) for row in G)  # Find the maximum distance
    return ans + 1  # Return the result

# Main function to execute the program
def main():
    N = int(input())
    S = [input() for _ in range(N)]
    if not bipartite(S):
        print(-1)  # If not bipartite, print -1
    else:
        print(warshall_floyd(S))  # Otherwise, compute and print the result

main()

