import sys

# Define constants
INF = 1e9
MOD = 1000000007

# Define directions for movement
dx = [0, 1, 0, -1, 1, 1, -1, -1]
dy = [1, 0, -1, 0, 1, -1, 1, -1]

# Read input
h, w = 19, 15
s = [input().strip() for _ in range(h)]

# Find the starting position of 'O'
for i in range(h):
    for j in range(w):
        if s[i][j] == 'O':
            sx, sy = i, j
            s[i] = s[i][:j] + '.' + s[i][j+1:]

# Initialize answer
ans = INF

def dfs(x, y, cnt):
    global ans
    if cnt > 20:
        return
    if x == h - 1:
        ans = min(ans, cnt)
        return
    for i in range(8):
        nx, ny = x + dx[i], y + dy[i]
        if 0 <= nx < h and 0 <= ny < w and s[nx][ny] == 'X':
            c = True
            while 0 <= nx < h and 0 <= ny < w and s[nx][ny] == 'X':
                s[nx] = s[nx][:ny] + '.' + s[nx][ny+1:]
                nx += dx[i]
                ny += dy[i]
            if c:
                dfs(nx, ny, cnt + 1)
            while nx != x or ny != y:
                nx -= dx[i]
                ny -= dy[i]
                s[nx] = s[nx][:ny] + 'X' + s[nx][ny+1:]
            s[x] = s[x][:y] + '.' + s[x][y+1:]

# Start DFS from the starting position
dfs(sx, sy, 0)

# Output the result
if ans == INF:
    print(-1)
else:
    print(ans)

