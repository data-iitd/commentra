

import sys

def main():
    S = input()
    x, y = map(int, input().split())

    F = []
    cur = 0
    for c in S:
        if c == 'F':
            cur += 1
        else:
            F.append(cur)
            cur = 0
    F.append(cur)

    evens = []
    odds = []
    for i, f in enumerate(F):
        if i % 2 == 0:
            evens.append(f)
        else:
            odds.append(f)

    dpx = [[False] * 20001 for _ in range(len(evens) + 1)]
    dpy = [[False] * 20001 for _ in range(len(odds) + 1)]

    dpx[0][10000] = True
    dpy[0][10000] = True

    for i, f in enumerate(evens):
        for j in range(20000):
            if j + f <= 20000:
                dpx[i + 1][j + f] |= dpx[i][j]
            if j - f >= 2000 and i!= 0:
                dpx[i + 1][j - f] |= dpx[i][j]

    for i, f in enumerate(odds):
        for j in range(20000):
            if j + f <= 20000:
                dpy[i + 1][j + f] |= dpy[i][j]
            if j - f >= 2000:
                dpy[i + 1][j - f] |= dpy[i][j]

    if dpx[len(evens)][x + 10000] and dpy[len(odds)][y + 10000]:
        print("Yes")
    else:
        print("No")

if __name__ == "__main__":
    main()

