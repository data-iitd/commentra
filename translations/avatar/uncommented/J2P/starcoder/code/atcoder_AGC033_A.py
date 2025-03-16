import sys
import queue

H, W = map(int, sys.stdin.readline().split())
A = [sys.stdin.readline().strip() for _ in range(H)]

queue = queue.Queue()
for i in range(H):
    for j in range(W):
        if A[i][j] == '#':
            queue.put([i, j, 0])

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

ans = 0

while not queue.empty():
    y, x, depth = queue.get()
    for i in range(4):
        if 0 <= y + dy[i] < H and 0 <= x + dx[i] < W:
            if A[y + dy[i]][x + dx[i]] == '.':
                queue.put([y + dy[i], x + dx[i], depth + 1])
                ans = depth + 1

print(ans)

# 