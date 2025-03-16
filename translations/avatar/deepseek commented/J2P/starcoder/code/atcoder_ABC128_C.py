
import sys

class Main:
    def __init__(self):
        self.sc = None
        self.a = None
        self.N = None
        self.M = None
        self.p = None
        self.ans = None

    def run(self):
        self.sc = Scanner(sys.stdin)
        self.N = self.sc.nextInt()
        self.M = self.sc.nextInt()
        self.a = [0] * self.N
        for i in range(self.N):
            self.a[i] = 0
        for i in range(self.M):
            k = self.sc.nextInt()
            for j in range(k):
                s = self.sc.nextInt()
                s -= 1
                self.a[s] |= 1 << i
        self.p = 0
        for i in range(self.M):
            x = self.sc.nextInt()
            self.p |= (x << i)
        self.ans = 0
        for s in range(1 << self.N):
            t = 0
            for i in range(self.N):
                if ((s >> i) & 1) == 1:
                    t ^= self.a[i]
            if self.p == t:
                self.ans += 1
        print(self.ans)
        self.sc.close()

if __name__ == "__main__":
    obj = Main()
    obj.run()

