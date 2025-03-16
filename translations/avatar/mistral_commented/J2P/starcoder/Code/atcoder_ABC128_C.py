
import sys

class Main:
    def __init__(self):
        self.sc = sys.stdin

    def run(self):
        N = int(self.sc.readline())
        M = int(self.sc.readline())

        a = [0] * N

        for i in range(N):
            a[i] = 0

        for i in range(M):
            k = int(self.sc.readline())

            for j in range(k):
                s = int(self.sc.readline())
                s -= 1

                a[s] |= (1 << i)

        p = 0

        for i in range(M):
            x = int(self.sc.readline())
            p |= (x << i)

        ans = 0

        for s in range(1 << N):
            t = 0

            for i in range(N):
                if ((s >> i) & 1) == 1:
                    t ^= a[i]

            if p == t:
                ans += 1

        print(ans)

if __name__ == "__main__":
    obj = Main()
    obj.run()

