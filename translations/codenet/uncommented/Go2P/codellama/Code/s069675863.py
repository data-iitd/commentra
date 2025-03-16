
import sys

def main():
    # input
    S = sys.stdin.readline().rstrip()
    x, y = map(int, sys.stdin.readline().split())

    # compute
    F = []
    # if S[0] == 'T':
    #     F = [0]
    cur = 0
    for i in range(len(S)):
        if S[i] == 'F':
            cur += 1
        else:
            F.append(cur)
            cur = 0
    F.append(cur)
    # print(F)

    evens, odds = [], []
    for i in range(len(F)):
        if i % 2 == 0:
            evens.append(F[i])
        else:
            odds.append(F[i])

    dpx, dpy = [[False] * 18001 for _ in range(len(evens)+1)], [[False] * 18001 for _ in range(len(odds)+1)]
    dpx[0][10000], dpy[0][10000] = True, True
    for i in range(len(evens)):
        val = evens[i]
        for j in range(2000, 18001):
            if j+val <= 18000:
                dpx[i+1][j+val] = dpx[i+1][j+val] or dpx[i][j]
            if j-val >= 2000 and i != 0:
                dpx[i+1][j-val] = dpx[i+1][j-val] or dpx[i][j]
    for i in range(len(odds)):
        val = odds[i]
        for j in range(2000, 18001):
            if j+val <= 18000:
                dpy[i+1][j+val] = dpy[i+1][j+val] or dpy[i][j]
            if j-val >= 2000:
                dpy[i+1][j-val] = dpy[i+1][j-val] or dpy[i][j]

    # output
    if dpx[len(evens)][x+10000] and dpy[len(odds)][y+10000]:
        print('Yes')
    else:
        print('No')

if __name__ == '__main__':
    main()

