MAX = 21

def init(n):
    global x, y, fld
    x = y = 10
    fld = [[0] * MAX for _ in range(MAX)]
    for _ in range(n):
        a, b = map(int, input().split())
        fld[b][a] = 1

def move(m):
    global n
    for _ in range(m):
        direction, a = input().split()
        a = int(a)
        if direction == 'N':
            d = 0
        elif direction == 'E':
            d = 1
        elif direction == 'S':
            d = 2
        elif direction == 'W':
            d = 3
        for _ in range(a):
            if d % 2 == 0:
                if d == 0:
                    x -= 1
                else:
                    x += 1
            else:
                if d == 1:
                    y -= 1
                else:
                    y += 1
            if fld[y][x] == 1:
                fld[y][x] = 0
                n -= 1

while True:
    n = int(input())
    if n == 0:
        break
    init(n)
    m = int(input())
    move(m)
    print("Yes" if n == 0 else "No")
