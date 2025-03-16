import sys
sys.setrecursionlimit(1 << 25)

readline = sys.stdin.buffer.readline
read = sys.stdin.readline
ra = range
enu = enumerate

def exit(*argv, **kwarg):
    print(*argv, **kwarg)
    sys.exit()

def mina(*argv, sub=1): return list(map(lambda x: x - sub, argv))

def a_int(): return int(readline())

def ints(): return list(map(int, readline().split()))

def read_col(H):
    ret = []
    for _ in range(H):
        ret.append(list(map(int, readline().split())))
    return tuple(map(list, zip(*ret)))

def read_map_as(H, replace={'#': 1, '.': 0}, pad=None):
    if pad is None:
        ret = []
        for _ in range(H):
            ret.append([replace[s] for s in read()[:-1]])
    else:
        ret = [[pad] * (W + 2)]
        for _ in range(H):
            ret.append([pad] + [replace[s] for s in read()[:-1]] + [pad])
        ret.append([pad] * (W + 2))
    return ret

def grid_dijkstra(grid, si: int, sj: int):
    from heapq import heappop, heappush
    H = len(grid)
    W = len(grid[0])
    D = [[-1] * W for _ in [0] * H]
    que = [(0, si, sj)]
    while que:
        c, i, j = heappop(que)
        if D[i][j] != -1:
            continue
        D[i][j] = c
        for di, dj in product([-2, -1, 0, 1, 2], repeat=2):
            ni, nj = i + di, j + dj
            if not (0 <= ni < H and 0 <= nj < W) or D[ni][nj] != -1 or ni == nj == 0 or grid[ni][nj] == 1:
                continue
            if (di == 0 and abs(dj) == 1) or (dj == 0 and abs(di) == 1):
                nc = c
            else:
                nc = c + 1
            heappush(que, (nc, ni, nj))
    return D

MOD = 10**9 + 7
INF = 2**31

H, W = ints()
si, sj = mina(*ints())
ti, tj = mina(*ints())

S = read_map_as(H)
D = [[-1] * W for _ in [0] * H]
que = deque([(0, si, sj)])
while que:
    c, i, j = que.popleft()
    if D[i][j] != -1:
        continue
    D[i][j] = c
    for di, dj in product([-2, -1, 0, 1, 2], repeat=2):
        ni, nj = i + di, j + dj
        if not (0 <= ni < H and 0 <= nj < W) or D[ni][nj] != -1 or ni == nj == 0 or S[ni][nj] == 1:
            continue
        if (di == 0 and abs(dj) == 1) or (dj == 0 and abs(di) == 1):
            que.appendleft((c, ni, nj))
        else:
            que.append((c + 1, ni, nj))

print(D[ti][tj])
