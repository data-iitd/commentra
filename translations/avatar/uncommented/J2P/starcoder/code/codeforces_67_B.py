
import sys
import java.io.* ; import java.util.* ;
class Main:
    def __init__(self):
        self.sc = Scanner(System.in)
        self.out = PrintWriter(sys.stdout, True)
    def main(self):
        n = self.sc.nextInt()
        k = self.sc.nextInt()
        bb = [0] * n
        for i in range(n):
            bb[i] = self.sc.nextInt()
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
            print(aa[i] + 1, end=" ")
        print()
    def flush(self):
        self.out.flush()

if __name__ == "__main__":
    o = Main()
    o.main()
    o.flush()

