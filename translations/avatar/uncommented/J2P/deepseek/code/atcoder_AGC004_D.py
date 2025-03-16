import sys
from typing import List

class MyRunnable:
    def run(self):
        n = int(input().strip())
        k = int(input().strip())
        as_ = [int(x) - 1 for x in input().strip().split()]
        calculator = Calculator(n, k, as_)
        print(calculator.calculate())

class Calculator:
    def __init__(self, n: int, k: int, as_: List[int]):
        self.k = k
        self.answer = 0
        self.is_calculate = False
        self.lists = [[] for _ in range(n)]
        for i in range(n):
            j = as_[i]
            if i > 0:
                self.lists[j].append(i)
            elif j > 0:
                self.answer += 1

    def calculate(self) -> int:
        if not self.is_calculate:
            self.dfs(0, 0)
            self.is_calculate = True
        return self.answer

    def dfs(self, a: int, pre: int) -> int:
        h = 0
        for i in self.lists[a]:
            h = max(h, self.dfs(i, a))
        if pre > 0 and h == self.k - 1:
            h = 0
            self.answer += 1
        else:
            h += 1
        return h

if __name__ == "__main__":
    MyRunnable().run()
