import sys
import math

def solve(testNumber, in, out):
    s = in.readline().replace("BC", "D")
    cnt = 0
    tmp = 0
    for i in range(len(s)):
        if s[i] == "A":
            tmp += 1
        elif s[i] == "D":
            cnt += tmp
        else:
            tmp = 0
    out.write(str(cnt) + "\n")

if __name__ == "__main__":
    solve(1, sys.stdin, sys.stdout)

