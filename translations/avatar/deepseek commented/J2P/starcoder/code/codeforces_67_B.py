import sys

class Main:
    def __init__(self):
        self.sc = sys.stdin
        self.out = sys.stdout

    def flush(self):
        self.out.flush()

    def print(self, *args, **kwargs):
        self.out.write(*args, **kwargs)

    def println(self, *args, **kwargs):
        self.print(*args, **kwargs)
        self.print("\n")

    def main(self):
        n = int(self.sc.readline())
        k = int(self.sc.readline())
        bb = [int(x) for x in self.sc.readline().split()]

        aa = [0] * n
        m = 0

        for a in range(n - 1, -1, -1):
            j = 0
            while bb[a] > 0:
                if aa[j] >= a + k:
                    bb[a] -= 1
                j += 1
            for j_ in range(m, j):
                aa[j_] = aa[j_ - 1]
            aa[j] = a
            m += 1

        for i in range(n):
            self.print(aa[i] + 1, " ")
        self.println()

if __name__ == "__main__":
    m = Main()
    m.main()
    m.flush()

