
import sys

MAX = 100

def main():
    n = int(input())
    x = []
    y = []
    h = []
    for i in range(n):
        x_i, y_i, h_i = map(int, input().split())
        x.append(x_i)
        y.append(y_i)
        h.append(h_i)
    for cx in range(MAX + 1):
        for cy in range(MAX + 1):
            ch = check(n, x, y, h, cx, cy)
            if ch > 0:
                print(cx, cy, ch)
                sys.exit()

def check(n, x, y, h, cx, cy):
    ch = -1
    for i in range(n):
        if h[i] > 0:
            ch = abs(x[i] - cx) + abs(y[i] - cy) + h[i]
            break
    for i in range(n):
        if h[i]!= max(ch - abs(x[i] - cx) - abs(y[i] - cy), 0):
            return -1
    return ch

if __name__ == '__main__':
    main()

