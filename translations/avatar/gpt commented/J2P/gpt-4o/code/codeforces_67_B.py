import sys

class Main:
    def __init__(self):
        self.sc = sys.stdin.read
        self.data = self.sc().split()
        self.index = 0

    def next_int(self):
        value = int(self.data[self.index])
        self.index += 1
        return value

    def main(self):
        n = self.next_int()
        k = self.next_int()

        bb = [self.next_int() for _ in range(n)]
        aa = [0] * n
        m = 0

        for a in range(n - 1, -1, -1):
            j = 0
            while bb[a] > 0:
                if j < m and aa[j] >= a + k:
                    bb[a] -= 1
                j += 1

            for j_ in range(m, j, -1):
                aa[j_] = aa[j_ - 1]
            aa[j] = a
            m += 1

        print(" ".join(str(aa[i] + 1) for i in range(n)))

if __name__ == "__main__":
    Main().main()

# <END-OF-CODE>
