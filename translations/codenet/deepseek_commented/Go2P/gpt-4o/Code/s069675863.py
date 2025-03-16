import sys

MOD = 1000000000 + 7
ALPHABET_NUM = 26
INF_INT64 = float('inf')
INF_BIT60 = 1 << 60
INF_INT32 = 2**31 - 1
INF_BIT30 = 1 << 30
NIL = -1
WHITE = 0
GRAY = 1
BLACK = 2

def read_string():
    return sys.stdin.readline().strip()

def read_int():
    return int(read_string())

def read_int2():
    return map(int, read_string().split())

def read_rune_slice():
    return list(read_string())

def main():
    S = read_rune_slice()
    x, y = read_int2()

    F = []
    cur = 0
    for char in S:
        if char == 'F':
            cur += 1
        else:
            F.append(cur)
            cur = 0
    F.append(cur)

    print(F)  # Debug output

    evens, odds = [], []
    for i in range(len(F)):
        if i % 2 == 0:
            evens.append(F[i])
        else:
            odds.append(F[i])

    dpx = [[False] * 20001 for _ in range(len(evens) + 1)]
    dpy = [[False] * 20001 for _ in range(len(odds) + 1)]
    
    dpx[0][10000] = True
    dpy[0][10000] = True

    for i in range(len(evens)):
        val = evens[i]
        for j in range(2000, 18001):
            if j + val <= 18000:
                dpx[i + 1][j + val] = dpx[i + 1][j + val] or dpx[i][j]
            if j - val >= 2000 and i != 0:
                dpx[i + 1][j - val] = dpx[i + 1][j - val] or dpx[i][j]

    for i in range(len(odds)):
        val = odds[i]
        for j in range(2000, 18001):
            if j + val <= 18000:
                dpy[i + 1][j + val] = dpy[i + 1][j + val] or dpy[i][j]
            if j - val >= 2000:
                dpy[i + 1][j - val] = dpy[i + 1][j - val] or dpy[i][j]

    if dpx[len(evens)][x + 10000] and dpy[len(odds)][y + 10000]:
        print("Yes")
    else:
        print("No")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
