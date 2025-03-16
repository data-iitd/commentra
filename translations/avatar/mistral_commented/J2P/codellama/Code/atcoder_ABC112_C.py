import sys

def main():
    n = int(sys.stdin.readline().strip())
    x = [int(i) for i in sys.stdin.readline().strip().split()]
    y = [int(i) for i in sys.stdin.readline().strip().split()]
    h = [int(i) for i in sys.stdin.readline().strip().split()]

    for i in range(101):
        for j in range(101):
            ch = check(n, x, y, h, i, j)
            if ch > 0:
                print(i, j, ch)

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

if __name__ == "__main__":
    main()

