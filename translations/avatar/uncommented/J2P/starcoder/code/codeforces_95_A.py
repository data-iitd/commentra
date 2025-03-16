
import sys
import string

class Main:
    def __init__(self):
        self.sc = sys.stdin
        self.out = sys.stdout
        self.out.write = self.write
        self.flush = self.out.flush
        self.buffer = []

    def write(self, s):
        self.buffer.append(s)

    def main(self):
        n = int(self.sc.readline())
        ss = []
        for i in range(n):
            ss.append(self.sc.readline().strip())
        cc = self.sc.readline().strip()
        m = len(cc)
        c = self.sc.readline().strip()
        c_ = c.upper()
        a = c == 'a' and 'b' or 'a'
        a_ = a.upper()
        lucky = [False] * m
        for j in range(m):
            for i in range(n):
                l = len(ss[i])
                if m - j >= l and self.compare(cc, j, ss[i], 0, l) == 0:
                    for h in range(l):
                        lucky[j + h] = True
        for j in range(m):
            if lucky[j]:
                if cc[j].lower() == c:
                    cc[j] = cc[j].isupper() and a_ or a
                else:
                    cc[j] = cc[j].isupper() and c_ or c
        self.println(cc)

    def compare(self, aa, i, bb, j, m):
        while m > 0:
            a = aa[i].upper()
            b = bb[j].upper()
            if a!= b:
                return a - b
            i += 1
            j += 1
            m -= 1
        return 0

    def println(self, s):
        self.out.write(''.join(s))
        self.out.write('\n')

if __name__ == '__main__':
    m = Main()
    m.main()
    m.flush()

# 