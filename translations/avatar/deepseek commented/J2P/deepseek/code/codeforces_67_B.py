import sys

class Main:
    def __init__(self):
        self.out = sys.stdout
        self.sc = sys.stdin

    def main(self):
        n = int(self.sc.readline().strip())
        k = int(self.sc.readline().strip())
        bb = list(map(int, self.sc.readline().strip().split()))

        aa = [0] * n
        m = 0

        for a in range(n - 1, -1, -1):
            j = 0
            while bb[a] > 0:
                if aa[j] >= a + k:
                    bb[a] -= 1
                j += 1
            aa[m:m] = [0] * (j - m)
            aa[j - 1] = a
            m = j

        for i in range(n):
            print(aa[i] + 1, end=' ')
        print()

if __name__ == "__main__":
    main_instance = Main()
    main_instance.main()
