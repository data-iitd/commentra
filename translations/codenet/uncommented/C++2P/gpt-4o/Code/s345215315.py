import sys
from collections import deque
from math import gcd

INF = 10**9
h, w = 19, 15
dx = [0, 1, 0, -1, 1, 1, -1, -1]
dy = [1, 0, -1, 0, 1, -1, 1, -1]
s = [input().strip() for _ in range(h)]

def dfs(x, y, cnt):
    global ans
    if cnt > 20:
        return
    if x == h - 1:
        ans = min(ans, cnt)
        return
    for i in range(8):
        nx, ny = x + dx[i], y + dy[i]
        if nx < 0 or nx >= h or ny < 0 or ny >= w:
            continue
        if s[nx][ny] != 'X':
            continue
        c = True
        while c and s[nx][ny] == 'X':
            s[nx] = s[nx][:ny] + '.' + s[nx][ny + 1:]  # Mark as visited
            nx += dx[i]
            ny += dy[i]
            if nx < 0 or nx >= h or ny < 0 or ny >= w:
                if nx >= h:
                    ans = min(ans, cnt + 1)
                c = False
        if c:
            dfs(nx, ny, cnt + 1)
        while nx != x or ny != y:
            nx -= dx[i]
            ny -= dy[i]
            s[nx] = s[nx][:ny] + 'X' + s[nx][ny + 1:]  # Restore the state
        s[x] = s[x][:y] + '.' + s[x][y + 1:]  # Mark the original position as visited

ans = INF
sx, sy = -1, -1
for i in range(h):
    for j in range(w):
        if s[i][j] == 'O':
            sx, sy = i, j
            s[i] = s[i][:j] + '.' + s[i][j + 1:]  # Mark as visited

dfs(sx, sy, 0)
if ans == INF:
    print(-1)
else:
    print(ans)

# <END-OF-CODE>
