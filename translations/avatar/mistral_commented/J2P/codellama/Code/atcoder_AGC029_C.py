
import sys
import io
import array
import collections

class Solution:
    def solve(self):
        self.n = int(self.read_line())
        self.a = array.array('i', map(int, self.read_line().split()))
        self.s = collections.defaultdict(int)

        ng = 0
        ok = self.n

        while ok - ng > 1:
            k = (ng + ok) // 2
            if self.is_possible(k):
                ok = k
            else:
                ng = k

        print(ok)

    def read_line(self):
        return sys.stdin.readline().strip()

    def is_possible(self, k):
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
    Solution().solve()

