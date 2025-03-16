
import sys

def next_line():
    return sys.stdin.readline().strip()

def next_int():
    return int(next_line())

def write(s):
    sys.stdout.write(str(s) + '\n')

def output():
    sys.stdout.flush()

def bipartite(S):
    N = len(S)
    D = [0] * N
    D[0] = 1
    Q = [0] * N
    ret = True
    pos = 1
    for i in range(N):
        if not ret: break
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
    return ret

def warshall_floyd(S):
    N = len(S)
    G = [[0] * N for _ in range(N)]
    for i in range(N):
        for j in range(N):
            if i == j: continue
            if S[i][j] == '0':
                G[i][j] = N
            else:
                G[i][j] = 1
    for k in range(N):
        for i in range(N):
            for j in range(N):
                if G[i][k] + G[k][j] < G[i][j]:
                    G[i][j] = G[i][k] + G[k][j]
    ans = 0
    for i in range(N):
        for j in range(N):
            if ans < G[i][j]: ans = G[i][j]
    return ans + 1

N = next_int()
S = [next_line() for _ in range(N)]
if not bipartite(S):
    write(-1)
else:
    write(warshall_floyd(S))
output()

