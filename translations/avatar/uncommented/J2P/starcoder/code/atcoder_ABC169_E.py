
# <START-OF-CODE>

import sys

def main():
    num = 998244353
    bf = sys.stdin
    out = sys.stdout
    n = int(bf.readline())
    ai = []
    bi = []
    for i in range(n):
        st = bf.readline().split()
        ai.append(int(st[0]))
        bi.append(int(st[1]))
    ai.sort()
    bi.sort()
    if n % 2 == 1:
        out.write(str(bi[len(bi)/2] - ai[len(ai)/2] + 1) + '\n')
    else:
        b = (ai[len(ai)/2] + ai[len(ai)/2 - 1] + 0.0) / 2
        c = (bi[len(bi)/2] + bi[len(bi)/2 - 1] + 0.0) / 2
        out.write(str(int(2 * (c - b) + 1)) + '\n')

if __name__ == '__main__':
    main()

# 