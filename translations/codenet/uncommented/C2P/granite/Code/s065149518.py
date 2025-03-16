
import sys

def init(n):
    global x, y
    x, y = 10, 10
    fld = [[0 for _ in range(21)] for _ in range(21)]
    for _ in range(n):
        a, b = map(int, input().split())
        fld[b][a] = 1
    return fld

def move(m):
    global x, y
    d = {'N': 0, 'E': 1, 'S': 2, 'W': 3}
    for _ in range(m):
        buf, a = input().split()
        a = int(a)
        while a > 0:
            x += (d[buf] + 1) % 2 * 2 - 1
            y += d[buf] % 2 * 2 - 1
            if fld[y][x]:
                fld[y][x] = 0
                global n
                n -= 1
            a -= 1
    return fld

def main():
    while True:
        n = int(input())
        if n == 0:
            break
        m = int(input())
        fld = init(n)
        move(m)
        print("No" if n else "Yes")
    return 0

if __name__ == "__main__":
    sys.exit(main())

