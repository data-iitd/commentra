import sys
from collections import deque

def next_line():
    return sys.stdin.readline().strip()

def next_int():
    return int(next_line())

def write(s):
    print(s)

def bipartite(S):
    N = len(S)
    D = [0] * N
    D[0] = 1
    Q = deque([0])
    ret = True

    while Q and ret:
        q = Q.popleft()
        for j, s in enumerate(S[q]):
            if s == '0':
                continue
            if D[j] == 0:
                D[j] = D[q] + 1
                Q.append(j)
            elif D[j] % 2 == D[q] % 2:
                ret = False
                break
    return ret

def warshall_floyd(S):
    N = len(S)
    G = [[float('inf')] * N for _ in range(N)]
    
    for i in range(N):
        for j in range(N):
            if i == j:
                G[i][j] = 0
            elif S[i][j] == '1':
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

def main():
    N = next_int()
    S = [next_line() for _ in range(N)]
    
    if not bipartite(S):
        write(-1)
    else:
        write(warshall_floyd(S))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
