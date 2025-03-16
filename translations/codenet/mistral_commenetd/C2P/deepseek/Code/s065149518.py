import sys

def init(n):
    global x, y, fld
    x = y = 10
    fld = [[0] * 21 for _ in range(21)]
    for _ in range(n):
        a, b = map(int, sys.stdin.readline().split())
        fld[b][a] = 1

def move(m):
    global n
    for _ in range(m):
        buf = sys.stdin.readline().strip().split()
        direction = {'N': 0, 'E': 1, 'S': 2, 'W': 3}[buf[0]]
        steps = int(buf[1])
        for _ in range(steps):
            if direction % 2:
                direction = direction - 1 if direction % 2 == 0 else direction + 1
                x += [-1, 1][direction % 2]
            else:
                direction = direction - 2 if direction else direction + 2
                y += [-1, 1][direction // 2]
                x += direction // 2
            if fld[y][x]:
                fld[y][x] = 0
                n -= 1

while True:
    n = int(sys.stdin.readline().strip())
    if n <= 0:
        break
    init(n)
    m = int(sys.stdin.readline().strip())
    move(m)
    print("Yes" if n else "No")
