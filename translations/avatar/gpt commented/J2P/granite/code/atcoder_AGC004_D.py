
import sys

class Calculator:
    def __init__(self, n, k, as):
        self.k = k
        self.answer = 0
        self.isCalculate = False
        self.lists = [[] for _ in range(n)]
        for i in range(n):
            j = as[i] - 1
            if i > 0:
                self.lists[j].append(i)
            elif j > 0:
                self.answer += 1

    def calculate(self):
        if not self.isCalculate:
            self.dfs(0, 0)
            self.isCalculate = True
        return self.answer

    def dfs(self, a, pre):
        h = 0
        for i in self.lists[a]:
            h = max(h, self.dfs(i, a))
        if pre > 0 and h == self.k - 1:
            h = 0
            self.answer += 1
        else:
            h += 1
        return h

def main():
    n = int(input())
    k = int(input())
    as = [int(input()) for _ in range(n)]
    calc = Calculator(n, k, as)
    print(calc.calculate())

if __name__ == "__main__":
    main()

