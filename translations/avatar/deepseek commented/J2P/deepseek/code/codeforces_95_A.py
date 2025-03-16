import sys

class Main:
    def __init__(self):
        self.out = sys.stdout
        self.out.flush = self.flush

    def main(self):
        sc = Scanner(sys.stdin)
        n = sc.nextInt()
        ss = [sc.next().upper() for _ in range(n)]
        cc = sc.next().upper().strip()
        m = len(cc)
        c = sc.next().strip().upper()
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
                if cc[j] == c:
                    cc = cc[:j] + (cc[j].lower() if cc[j].isupper() else cc[j].upper()) + cc[j+1:]
                else:
                    cc = cc[:j] + (cc[j].lower() if cc[j].isupper() else cc[j].upper()) + cc[j+1:]

        self.out.write(cc + '\n')

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

    def flush(self):
        self.out.flush()

class Scanner:
    def __init__(self, stream):
        self.sc = stream

    def nextInt(self):
        return int(self.sc.readline().strip())

    def next(self):
        return self.sc.readline().strip()

    def nextLine(self):
        return self.sc.readline().strip()

if __name__ == "__main__":
    main = Main()
    main.main()
