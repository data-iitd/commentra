# <START-OF-CODE>
import sys

class BABC:
    def solve(self, testNumber, in_, out_):
        s = in_.next().replace('BC', 'D')
        cnt = 0
        tmp = 0
        for i in range(len(s)):
            if s[i] == 'A':
                tmp += 1
            elif s[i] == 'D':
                cnt += tmp
            else:
                tmp = 0
        out_.println(cnt)

if __name__ == '__main__':
    solver = BABC()
    solver.solve(1, sys.stdin, sys.stdout)
# 