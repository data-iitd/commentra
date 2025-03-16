import sys

class Main:
    def __init__(self, output_stream=sys.stdout, auto_flush=True):
        self.output_stream = output_stream
        if auto_flush:
            self.flush = lambda: self.output_stream.flush()
        else:
            self.flush = lambda: None
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

            for j_ in range(m, j - 1, -1):
                aa[j_] = aa[j_ - 1]

            aa[j] = a
            m += 1

        print(" ".join(str(x + 1) for x in aa))
        self.flush()

if __name__ == "__main__":
    main_instance = Main()
    main_instance.main()
