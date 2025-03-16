import sys
import math

class TSize:
    def __init__(self, r=0, c=0):
        self.r = r
        self.c = c

class TMcmSolver:
    def __init__(self, chain):
        self.FChain = chain
        self.FMemo = [[0] * len(chain) for _ in range(len(chain))]

    @staticmethod
    def Count(left, right):
        return left.r * right.c * left.c

    def Solve(self, s, l):
        assert s <= l
        if s == l:
            return 0
        if self.FMemo[s][l] != 0:
            return self.FMemo[s][l]
        if s + 1 == l:
            self.FMemo[s][l] = self.Count(self.FChain[s], self.FChain[l])
        else:
            min_cost = math.inf
            for i in range(s, l):
                c = (self.Solve(s, i) + 
                     self.Count(TSize(self.FChain[s].r, self.FChain[i].c), 
                                TSize(self.FChain[i + 1].r, self.FChain[l].c)) + 
                     self.Solve(i + 1, l))
                min_cost = min(min_cost, c)
            self.FMemo[s][l] = min_cost
        return self.FMemo[s][l]

    def Answer(self):
        return self.Solve(0, len(self.FMemo) - 1)

    def Print(self):
        for s in range(len(self.FMemo)):
            for l in range(len(self.FMemo[0])):
                print(self.FMemo[s][l], end='\t')
            print()

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
    
    print(solver.Answer())
    # solver.Print()

if __name__ == "__main__":
    main()

# <END-OF-CODE>
