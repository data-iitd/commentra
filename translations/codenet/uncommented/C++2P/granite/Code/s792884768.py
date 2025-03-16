
def count(left, right):
    return left.r * right.c * left.c

class McmSolver:
    def __init__(self, chain):
        self.chain = chain
        self.memo = [[0 for _ in range(len(chain))] for _ in range(len(chain))]

    def solve(self, s, l):
        if s == l:
            return 0
        if self.memo[s][l]!= 0:
            return self.memo[s][l]
        if s + 1 == l:
            self.memo[s][l] = count(self.chain[s], self.chain[l])
        else:
            min_val = float('inf')
            for i in range(s, l):
                c = self.solve(s, i) + count(self.chain[s], self.chain[i]) + self.solve(i+1, l)
                if c < min_val:
                    min_val = c
            self.memo[s][l] = min_val
        return self.memo[s][l]

    def answer(self):
        return self.solve(0, len(self.chain)-1)

if __name__ == "__main__":
    n = int(input())
    if n == 1:
        print(0)
        exit(0)
    chain = []
    for _ in range(n):
        r, c = map(int, input().split())
        chain.append((r, c))
    solver = McmSolver(chain)
    print(solver.answer())

