import sys

class Main:
    def __init__(self):
        self.sc = sys.stdin
        self.out = sys.stdout
        self.flush = self.out.flush

    def main(self):
        n = int(self.sc.readline())
        k = int(self.sc.readline())
        bb = [int(self.sc.readline()) for i in range(n)]
        aa = [0] * n
        m = 0
        for a in range(n - 1, -1, -1):
            j = 0
            while bb[a] > 0:
                if aa[j] >= a + k:
                    bb[a] -= 1
                j += 1
            for j_ in range(m, j, -1):
                aa[j_] = aa[j_ - 1]
            aa[j] = a
            m += 1
        for i in range(n):
            print(aa[i] + 1, end=' ')
        print()

if __name__ == '__main__':
    o = Main()
    o.main()
    o.flush()

