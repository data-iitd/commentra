
import sys
import queue

def bfs(S, start):
    N = len(S)
    D = [0] * N
    Q = queue.Queue()
    Q.put(start)
    D[start] = 1
    while not Q.empty():
        q = Q.get()
        for j, s in enumerate(S[q]):
            if s == '0':
                continue
            if D[j] == 0:
                D[j] = D[q] + 1
                Q.put(j)
    return D

def warshall_floyd(S):
    N = len(S)
    G = [[0] * N for _ in range(N)]
    for i in range(N):
        for j in range(N):
            if i == j:
                continue
            if S[i][j] == '0':
                G[i][j] = 100000000 # Set distance to a large number
            else:
                G[i][j] = 1 # Direct edge weight
    for k in range(N):
        for i in range(N):
            for j in range(N):
                if G[i][k] + G[k][j] < G[i][j]:
                    G[i][j] = G[i][k] + G[k][j] # Update shortest path
    ans = 0
    for i in range(N):
        for j in range(N):
            if ans < G[i][j]:
                ans = G[i][j] # Find the maximum distance
    return ans + 1 # Return the result

def main():
    N = int(input())
    S = [input() for _ in range(N)]
    D = [bfs(S, i) for i in range(N)]
    for i in range(N):
        for j in range(N):
            if D[i][j] % 2 == D[0][i] % 2:
                print(-1) # If not bipartite, print -1
                sys.exit()
    print(warshall_floyd(S)) # Otherwise, compute and print the result

if __name__ == "__main__":
    main()

