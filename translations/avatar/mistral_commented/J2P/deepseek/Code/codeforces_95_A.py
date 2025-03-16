class Main:
    def __init__(self):
        self.output = []

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
        n = int(input().strip())
        ss = [input().strip().upper() for _ in range(n)]
        cc = input().strip().upper()
        m = len(cc)
        c = input().strip().upper()[0]
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
                if cc[j].lower() == c:
                    cc = cc[:j] + (cc[j].upper() if cc[j].isupper() else cc[j].lower()) + cc[j+1:]
                else:
                    cc = cc[:j] + (cc[j].upper() if cc[j].isupper() else cc[j].lower()) + cc[j+1:]

        print(cc)


# Create an instance of Main and call the main method
o = Main()
o.main()
