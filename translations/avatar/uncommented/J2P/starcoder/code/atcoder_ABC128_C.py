
# <START-OF-CODE>

import sys

class Main:
    def __init__(self):
        self.sc = None
        self.N = 0
        self.M = 0
        self.a = []
        self.p = 0
        self.ans = 0

    def run(self):
        self.sc = sys.stdin
        self.N = int(self.sc.readline())
        self.M = int(self.sc.readline())
        self.a = [0] * self.N
        for i in range(self.M):
            k = int(self.sc.readline())
            for j in range(k):
                s = int(self.sc.readline())
                s -= 1
                self.a[s] |= (1 << i)
        self.p = int(self.sc.readline())
        for i in range(self.M):
            x = int(self.sc.readline())
            self.p |= (x << i)
        for s in range(1 << self.N):
            t = 0
            for i in range(self.N):
                if (s >> i) & 1:
                    t ^= self.a[i]
            if self.p == t:
                self.ans += 1
        print(self.ans)

if __name__ == '__main__':
    main = Main()
    main.run()

# 