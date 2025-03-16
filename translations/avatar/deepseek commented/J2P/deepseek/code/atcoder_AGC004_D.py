import sys
from collections import defaultdict, deque

class Calculator:
    def __init__(self, n, k, as_):
        self.k = k
        self.answer = 0
        self.is_calculate = False
        self.lists = defaultdict(list)
        for i in range(n):
            self.lists[i] = []
        for i in range(n):
            j = as_[i]
            if i > 0:
                self.lists[j].append(i)
            elif j > 0:
                self.answer += 1

    def calculate(self):
        if not self.is_calculate:
            self.dfs(0, 0)
            self.is_calculate = True
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
    n = int(sys.stdin.readline().strip())
    k = int(sys.stdin.readline().strip())
    as_ = list(map(lambda x: int(x) - 1, sys.stdin.readline().strip().split()))

    calculator = Calculator(n, k, as_)
    print(calculator.calculate())

if __name__ == "__main__":
    main()

