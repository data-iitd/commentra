
import sys

def count(left, right):
    return left.r * right.c * left.c

def solve(s, l, memo):
    if s == l:
        return 0
    if memo[s][l]!= 0:
        return memo[s][l]
    min_cost = sys.maxsize
    for i in range(s, l):
        c = solve(s, i, memo) + count(TSize(memo[s][0], memo[s][1]), TSize(memo[i+1][0], memo[i+1][1])) + solve(i+1, l, memo)
        if c < min_cost:
            min_cost = c
    memo[s][l] = min_cost
    return min_cost

class TSize:
    def __init__(self, r, c):
        self.r = r
        self.c = c

class TMcmSolver:
    def __init__(self, chain):
        self.chain = chain
        self.memo = [[0 for _ in range(len(chain))] for _ in range(len(chain))]

    def answer(self):
        return solve(0, len(self.chain)-1, self.memo)

    def print(self):
        for row in self.memo:
            print(row)

if __name__ == "__main__":
    n = int(input())
    if n == 1:
        print(0)
        exit(0)
    chain = []
    for _ in range(n):
        r, c = map(int, input().split())
        chain.append(TSize(r, c))
    solver = TMcmSolver(chain)
    print(solver.answer())
    # solver.print()

