def count_multiplications(left, right):
    return left.r * right.c * left.c

def solve(s, l, memo, chain):
    if s == l:
        return 0
    if memo[s][l] != 0:
        return memo[s][l]
    if s + 1 == l:
        memo[s][l] = count_multiplications(chain[s], chain[l])
    else:
        min_multiplications = float('inf')
        for i in range(s, l):
            multiplications = solve(s, i, memo, chain) + count_multiplications(TSize(chain[s].r, chain[i].c), TSize(chain[i+1].r, chain[l].c)) + solve(i+1, l, memo, chain)
            min_multiplications = min(min_multiplications, multiplications)
        memo[s][l] = min_multiplications
    return memo[s][l]

class TMcmSolver:
    def __init__(self, chain):
        self.chain = chain
        self.memo = [[0] * len(chain) for _ in range(len(chain))]

    def answer(self):
        return solve(0, len(self.memo) - 1, self.memo, self.chain)

    def print_memo(self):
        for row in self.memo:
            print('\t'.join(map(str, row)))

def main():
    n = int(input())
    if n == 1:
        print(0)
        return
    chain = []
    for _ in range(n):
        r, c = map(int, input().split())
        chain.append(TSize(r, c))
    solver = TMcmSolver(chain)
    print(solver.answer())
    # solver.print_memo()

