
# <START-OF-CODE>

class Main:
    def __init__(self):
        self.n = 0
        self.a = []
        self.s = {}

    def set(self):
        self.n = int(input())
        self.a = list(map(int, input().split()))

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
        self.s.clear()
        current = 0
        for ai in self.a:
            if ai <= current:
                if k == 1:
                    return False
                while self.s and self.s[-1][0] >= ai:
                    self.s.pop()
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
    m = Main()
    m.solve()

# 