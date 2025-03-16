# <START-OF-CODE>
import sys

class TaskC:
    def __init__(self):
        pass

    def solve(self, testNumber, in_, out_):
        n = int(in_.readline())
        cnt = [0] * 5
        for i in range(n):
            str = in_.readline()
            if str[0] == 'M':
                cnt[0] += 1
            elif str[0] == 'A':
                cnt[1] += 1
            elif str[0] == 'R':
                cnt[2] += 1
            elif str[0] == 'C':
                cnt[3] += 1
            elif str[0] == 'H':
                cnt[4] += 1
        res = cnt[0] * cnt[1] * cnt[2] + cnt[0] * cnt[1] * cnt[3] + cnt[0] * cnt[1] * cnt[4] + cnt[0] * cnt[2] * cnt[3] + cnt[0] * cnt[2] * cnt[4] + cnt[0] * cnt[3] * cnt[4] + cnt[1] * cnt[2] * cnt[3] + cnt[1] * cnt[2] * cnt[4] + cnt[1] * cnt[3] * cnt[4] + cnt[2] * cnt[3] * cnt[4]
        out_.write(str(res) + '\n')

if __name__ == '__main__':
    task = TaskC()
    task.solve(1, sys.stdin, sys.stdout)
# 