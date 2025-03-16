import sys
from collections import deque

# <START-OF-CODE>

def main():
    H, W = map(int, sys.stdin.readline().split())
    A = [list(sys.stdin.readline().strip()) for _ in range(H)]
    queue = deque()
    for i in range(H):
        for j in range(W):
            if A[i][j] == '#':
                queue.append([i, j, 0])
    flag = [[0] * W for _ in range(H)]
    ans = 0
    dx = [1, -1, 0, 0]
    dy = [0, 0, 1, -1]
    while queue:
        y, x, depth = queue.popleft()
        for i in range(4):
            if 0 <= y + dy[i] < H and 0 <= x + dx[i] < W:
                if flag[y + dy[i]][x + dx[i]] == 0 and A[y + dy[i]][x + dx[i]] == '.':
                    flag[y + dy[i]][x + dx[i]] = 1
                    queue.append([y + dy[i], x + dx[i], depth + 1])
                    ans = max(ans, depth + 1)
    print(ans)

if __name__ == '__main__':
    main()

# 