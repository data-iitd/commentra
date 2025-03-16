import sys

N, M = map(int, sys.stdin.readline().split())
black = [[0] * (N + 2) for _ in range(N + 2)]

for m in range(1, M + 1):
    x, y = map(int, sys.stdin.readline().split())
    for xx in range(x - 1, x + 2):
        for yy in range(y - 1, y + 2):
            if black[xx][yy] == 8:
                print(m)
                sys.exit()
            black[xx][yy] += 1

print(-1)


