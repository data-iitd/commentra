
rr, cc, k = map(int, input().split())
mat = [[0] * cc for _ in range(rr)]
for _ in range(k):
    r, c, v = map(int, input().split())
    mat[r - 1][c - 1] = v
dp = [[[0] * 4 for _ in range(cc)] for _ in range(rr)]
dp[0][0][1] = mat[0][0]
for y in range(rr):
    for x in range(cc):
        for c in range(4):
            v = mat[y][x]
            q = 0
            if c == 0 or v == 0:
                q = 0 if x == 0 else max(dp[y][x - 1][c])
            else:
                q = 0 if x == 0 else max(dp[y][x - 1][c], dp[y][x - 1][c - 1] + v)
            dp[y][x][c] = q
dpl = [0] * cc
for x in range(cc):
    dpl[x] = max(max(dp[rr - 1][x][0], dp[rr - 1][x][1]), max(dp[rr - 1][x][2], dp[rr - 1][x][3]))
print(dpl[cc - 1])
