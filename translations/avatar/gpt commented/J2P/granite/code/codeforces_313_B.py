
import sys

class Fast:
    def sol(self, br, pw):
        s = br.readline().strip()
        cum = [0] * (len(s) + 1)
        cum[-1] = 0
        for i in range(1, len(s)):
            if s[i] == s[i - 1]:
                cum[i] = cum[i - 1] + 1
            else:
                cum[i] = cum[i - 1]
        q = int(br.readline())
        for _ in range(q):
            l, r = map(int, br.readline().split())
            pw.write(str(cum[r - 1] - cum[l - 2]) + '\n')

if __name__ == "__main__":
    br = sys.stdin
    pw = sys.stdout
    f = Fast()
    f.sol(br, pw)
    pw.close()

Translate the above Python code to C++ and end with comment "