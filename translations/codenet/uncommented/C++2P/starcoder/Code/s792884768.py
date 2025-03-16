
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>

class TSize:
    def __init__(self, r=0, c=0):
        self.r = r
        self.c = c

class TMcmSolver:
    def __init__(self, Chain):
        self.FChain = Chain
        self.FMemo = [[0 for i in range(len(Chain))] for j in range(len(Chain))]

    def Count(self, Left, Right):
        return Left.r * Right.c * Left.c

    def Solve(self, s, l):
        assert(s <= l)
        if(s == l): return 0
        if(self.FMemo[s][l]!= 0): return self.FMemo[s][l]
        if(s + 1 == l):
            self.FMemo[s][l] = self.Count(self.FChain[s], self.FChain[l])
        else:
            min = INT_MAX
            for i in range(s, l):
                c = self.Solve(s, i) + self.Count(TSize(self.FChain[s].r, self.FChain[i].c), TSize(self.FChain[i+1].r, self.FChain[l].c)) + self.Solve(i+1, l)
                min = min if min < c else c
            self.FMemo[s][l] = min
        return self.FMemo[s][l]

    def Answer(self):
        return self.Solve(0, len(self.FChain)-1)

def main():
    n = int(input())
    if(n == 1):
        print(0)
        return 0
    Chain = []
    for i in range(n):
        r, c = map(int, input().split())
        Chain.append(TSize(r, c))
    Solver = TMcmSolver(Chain)
    print(Solver.Answer())
    return 0

# 