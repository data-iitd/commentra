
import sys

class Main:
    def __init__(self):
        self.sc = sys.stdin
        self.out = sys.stdout

    def compare(self, aa, i, bb, j, m):
        while m > 0:
            a = ord(aa[i].upper())
            b = ord(bb[j].upper())
            if a!= b:
                return a - b
            i += 1
            j += 1
            m -= 1
        return 0

    def main(self):
        n = int(self.sc.readline())
        ss = []
        for i in range(n):
            ss.append(self.sc.readline().strip())

        cc = self.sc.readline().strip()
        m = len(cc)
        c = self.sc.readline().strip()
        c_ = ord(c.upper())
        a = ord('a') if c == 'a' else ord('b')
        a_ = ord(chr(a).upper())

        lucky = [False] * m
        for j in range(m):
            for i in range(n):
                l = len(ss[i])
                if m - j >= l and self.compare(cc, j, ss[i], 0, l) == 0:
                    for h in range(l):
                        lucky[j + h] = True

        for j in range(m):
            if lucky[j]:
                if ord(cc[j].lower()) == c:
                    cc[j] = chr(a) if cc[j].isupper() else chr(a).lower()
                else:
                    cc[j] = chr(c) if cc[j].isupper() else chr(c).lower()

        print(''.join(cc))

    def flush(self):
        self.out.flush()

if __name__ == '__main__':
    main = Main()
    main.main()
    main.flush()

