
import sys
import math

def solve(testNumber, in, out):
    S = in.readline().strip()
    score = 0
    for i in range(len(S)):
        my = 'g' if i % 2 == 0 else 'p'
        his = S[i]
        if my != his:
            score += 1 if my == 'p' else -1
    out.write(str(score) + '\n')

if __name__ == '__main__':
    solve(1, sys.stdin, sys.stdout)

