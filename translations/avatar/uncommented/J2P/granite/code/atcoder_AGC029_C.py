
import sys
import io
import bisect

class Main:
    def __init__(self):
        self.n = 0
        self.a = []
        self.s = {}

    def set(self):
        lines = sys.stdin.readlines()
        self.n = int(lines[0])
        self.a = list(map(int, lines[1].split()))
        self.s = {}

    def solve(self):
        self.set()
        ng = 0
        ok = self.n
        while ok - ng > 1:
            k = (ng + ok) // 2
            if self.isPossible(k):
                ok = k
            else:
                ng = k
        print(ok)

    def isPossible(self, k):
        self.s = {}
        current = 0
        for ai in self.a:
            if ai <= current:
                if k == 1:
                    return False
                while len(self.s) > 0 and list(self.s.keys())[-1] >= ai:
                    self.s.pop(list(self.s.keys())[-1])
                p = ai - 1
                while True:
                    if p < 0:
                        return False
                    sp = self.s.get(p, 0) + 1
                    self.s[p] = sp
                    if sp == k:
                        self.s.pop(p)
                        p -= 1
                    else:
                        break
            current = ai
        return True

if __name__ == '__main__':
    Main().solve()

