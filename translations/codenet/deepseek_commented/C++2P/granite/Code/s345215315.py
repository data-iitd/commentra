
import sys
sys.setrecursionlimit(10**6)

def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

def lcm(a, b):
    return a // gcd(a, b) * b

h, w = 19, 15
dx = [0, 1, 0, -1, 1, 1, 1, -1, -1]
dy = [1, 0, -1, 0, 1, -1, 1, 1, -1]
s = [list(input()) for _ in range(h)]
ans = float('inf')

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
        if s[nx][ny]!= 'X':
            continue
        c = True
        while c and s[nx][ny] == 'X':
            s[nx][ny] = '.'
            nx += dx[i]
            ny += dy[i]
            if nx < 0 or nx >= h or ny < 0 or ny >= w:
                if nx >= h:
                    ans = min(ans, cnt + 1)
                c = False
        if c:
            dfs(nx, ny, cnt + 1)
        while nx!= x or ny!= y:
            nx -= dx[i]
            ny -= dy[i]
            s[nx][ny] = 'X'
        s[x][y] = '.'

for i in range(h):
    for j in range(w):
        if s[i][j] == 'O':
            dfs(i, j, 0)
            break

print(ans if ans!= float('inf') else -1)

