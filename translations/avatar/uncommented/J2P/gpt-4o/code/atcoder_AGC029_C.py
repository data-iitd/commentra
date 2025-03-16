import sys
from collections import defaultdict

class Main:
    def __init__(self):
        self.n = 0
        self.a = []
        self.s = defaultdict(int)

    def set_input(self):
        self.n = int(sys.stdin.readline().strip())
        self.a = list(map(int, sys.stdin.readline().strip().split()))

    def solve(self):
        self.set_input()
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
                while self.s and max(self.s.keys()) >= ai:
                    self.s[max(self.s.keys())] -= 1
                    if self.s[max(self.s.keys())] == 0:
                        del self.s[max(self.s.keys())]
                p = ai - 1
                while True:
                    if p < 0:
                        return False
                    sp = self.s[p] + 1
                    self.s[p] = sp
                    if sp == k:
                        del self.s[p]
                        p -= 1
                    else:
                        break
            current = ai
        return True

if __name__ == "__main__":
    m = Main()
    m.solve()

# <END-OF-CODE>
