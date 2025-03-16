import math

def check(n, x, y, h, cx, cy):
    ch = -1
    for i in range(n):
        if h[i] > 0:
            ch = abs(x[i] - cx) + abs(y[i] - cy) + h[i]
            break
    for i in range(n):
        if h[i] != max(ch - abs(x[i] - cx) - abs(y[i] - cy), 0):
            return -1
    return ch

def main():
    n = int(input())
    x = [int(input()) for _ in range(n)]
    y = [int(input()) for _ in range(n)]
    h = [int(input()) for _ in range(n)]

    for i in range(101):
        for j in range(101):
            ch = check(n, x, y, h, i, j)
            if ch > 0:
                print(i, j, ch)

if __name__ == "__main__":
    main()

