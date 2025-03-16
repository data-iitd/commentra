import sys
import numpy as np

# Structure to represent the size of a matrix
class TSize:
    def __init__(self, r=0, c=0):
        self.r = r
        self.c = c

# Class to solve the Matrix Chain Multiplication problem
class TMcmSolver:
    def __init__(self, chain):
        self.FChain = chain
        self.FMemo = [[0] * len(chain) for _ in range(len(chain))]

    # Function to calculate the cost of multiplying two matrices
    @staticmethod
    def Count(left, right):
        return left.r * right.c * left.c

    # Recursive function to solve the matrix chain multiplication problem
    def Solve(self, s, l):
        if s == l:
            return 0
        if self.FMemo[s][l] != 0:
            return self.FMemo[s][l]
        if s + 1 == l:
            self.FMemo[s][l] = TMcmSolver.Count(self.FChain[s], self.FChain[l])
        else:
            min_cost = sys.maxsize
            for i in range(s, l):
                cost = self.Solve(s, i) + TMcmSolver.Count(self.FChain[s], self.FChain[i+1]) + self.Solve(i+1, l)
                min_cost = min(min_cost, cost)
            self.FMemo[s][l] = min_cost
        return self.FMemo[s][l]

    # Function to get the final answer (minimum multiplication cost)
    def Answer(self):
        return self.Solve(0, len(self.FChain) - 1)

    # Function to print the memoization table (for debugging purposes)
    def Print(self):
        for row in self.FMemo:
            print(' '.join(map(str, row)))

# Main function
def main():
    n = int(input().strip())
    if n == 1:
        print(0)
        return
    
    chain = []
    for _ in range(n):
        r, c = map(int, input().strip().split())
        chain.append(TSize(r, c))
    
    solver = TMcmSolver(chain)
    print(solver.Answer())
    # solver.Print()

if __name__ == "__main__":
    main()
