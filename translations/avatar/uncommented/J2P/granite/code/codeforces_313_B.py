
import sys

class Fast:
    def sol(self, br, pw):
        st = br.readline().split()
        s = st[0]
        cum = [0] * (len(s) + 1)
        for i in range(1, len(s)):
            if s[i] == s[i - 1]:
                cum[i] = cum[i - 1] + 1
            else:
                cum[i] = cum[i - 1]
        q = int(br.readline())
        for _ in range(q):
            st = br.readline().split()
            l = int(st[0])
            r = int(st[1]) - 1
            pw.write(str(cum[r] - cum[l - 1]) + '\n')

if __name__ == '__main__':
    br = sys.stdin
    pw = sys.stdout
    f = Fast()
    f.sol(br, pw)
    pw.close()

Translate the above Python code to C++ and end with comment "