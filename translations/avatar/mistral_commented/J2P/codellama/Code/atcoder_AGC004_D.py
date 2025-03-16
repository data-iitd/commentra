
import sys

class Calculator:
    def __init__(self, n, k, as):
        self.k = k
        self.answer = 0
        self.isCalculate = False
        self.lists = [[0] * n for _ in range(n)]

        for i in range(n):
            j = as[i]
            if i > 0:
                self.lists[j][i] = 1
            elif j > 0:
                self.answer += 1

    def calculate(self):
        if not self.isCalculate:
            self.dfs(0, -1)
            self.isCalculate = True
        return self.answer

    def dfs(self, a, pre):
        h = 0

        for i in range(len(self.lists[a])):
            if self.lists[a][i] == 1:
                h = max(h, self.dfs(i, a))

        if pre > 0 and h == self.k - 1:
            h = 0
            self.answer += 1
        else:
            h += 1

        return h

if __name__ == "__main__":
    n, k = map(int, input().split())
    as = list(map(int, input().split()))
    print(Calculator(n, k, as).calculate())

