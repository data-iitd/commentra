import sys
import bisect

class Main:
    def __init__(self):
        self.n = 0
        self.a = []
        self.s = {}

    def set(self):
        input_line = sys.stdin.readline().strip()
        self.n = int(input_line)
        self.a = list(map(int, sys.stdin.readline().strip().split()))
        self.s = {}

    def solve(self):
        self.set()
        ng = 0
        ok = self.n
        while ok - ng > 1:
            k = (ng + ok) // 2
            if self.is_possible(k):
                ok = k
            else:
                ng = k
        print(ok)

    def is_possible(self, k):
        self.s.clear()
        current = 0
        for ai in self.a:
            if ai <= current:
                if k == 1:
                    return False
                while self.s and max(self.s) >= ai:
                    del self.s[max(self.s)]
                p = ai - 1
                while True:
                    if p < 0:
                        return False
                    if p not in self.s:
                        self.s[p] = 0
                    self.s[p] += 1
                    if self.s[p] == k:
                        del self.s[p]
                        p -= 1
                    else:
                        break
            current = ai
        return True

# Create an instance of Main and call the solve method
m = Main()
m.solve()
