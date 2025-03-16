import sys

class Main:
    def __init__(self):
        self.out = sys.stdout
        self.sc = sys.stdin

    def compare(self, aa, i, bb, j, m):
        while m > 0:
            a = aa[i].upper()
            b = bb[j].upper()
            if a != b:
                return ord(a) - ord(b)
            i += 1
            j += 1
            m -= 1
        return 0

    def main(self):
        n = int(self.sc.readline().strip())
        ss = [self.sc.readline().strip().upper() for _ in range(n)]
        cc = list(self.sc.readline().strip().upper())
        m = len(cc)
        c = self.sc.readline().strip().upper()[0]
        a = 'B' if c == 'A' else 'A'

        lucky = [False] * m

        for j in range(m):
            for i in range(n):
                l = len(ss[i])
                if m - j >= l and self.compare(cc, j, ss[i], 0, l) == 0:
                    for h in range(l):
                        lucky[j + h] = True

        for j in range(m):
            if lucky[j]:
                if cc[j].lower() == c.lower():
                    cc[j] = a if cc[j].isupper() else a.lower()
                else:
                    cc[j] = c if cc[j].isupper() else c.lower()

        self.out.write(''.join(cc) + '\n')

if __name__ == "__main__":
    main_instance = Main()
    main_instance.main()
