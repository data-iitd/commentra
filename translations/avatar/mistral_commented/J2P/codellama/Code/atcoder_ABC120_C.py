
import sys
import math

def solve(testNumber, in, out):
    x = in.readline().strip()
    s = []
    c = 0

    for i in range(len(x)):
        s.append(x[i])

        while len(s) > 1:
            p = s.pop()
            q = s.pop()

            if (p == '1' and q == '0') or (p == '0' and q == '1'):
                c += 1
                continue

            s.append(q)
            s.append(p)
            break

    out.write(str(c * 2) + '\n')

if __name__ == '__main__':
    solve(1, sys.stdin, sys.stdout)

