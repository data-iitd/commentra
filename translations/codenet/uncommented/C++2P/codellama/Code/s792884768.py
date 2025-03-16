#include <cassert>
#include <iostream>
#include <vector>
#include <climits>

class TSize:
    def __init__(self, r, c):
        self.r = r
        self.c = c

class TMcmSolver:
    def __init__(self, chain):
        self.chain = chain
        self.memo = [[0] * len(chain) for _ in range(len(chain))]

    def count(self, left, right):
        return left.r * right.c * left.c

    def solve(self, s, l):
        assert s <= l
        if s == l:
            return 0
        if self.memo[s][l] != 0:
            return self.memo[s][l]
        if s + 1 == l:
            self.memo[s][l] = self.count(self.chain[s], self.chain[l])
        else:
            min = INT_MAX
            for i in range(s, l):
                c = self.solve(s, i) + self.count(TSize(self.chain[s].r, self.chain[i].c), TSize(self.chain[i+1].r, self.chain[l].c)) + self.solve(i+1, l)
                min = min(min, c)
            self.memo[s][l] = min
        # print("Solve! [" + str(s) + "], [" + str(l) + "]")
        return self.memo[s][l]

    def answer(self):
        return self.solve(0, len(self.chain) - 1)

    def print(self):
        for s in range(len(self.memo)):
            for l in range(len(self.memo[0])):
                print(self.memo[s][l], end="\t")
            print()

n = int(input())
if n == 1:
    print(0)
    exit()
chain = [TSize(int(input()), int(input())) for _ in range(n)]
solver = TMcmSolver(chain)

print(solver.answer())
# solver.print()

