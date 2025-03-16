
import sys
import threading
import time

class MyRunnable(object):
    def run(self):
        n = int(sys.stdin.readline())
        k = int(sys.stdin.readline())
        as = []
        for i in range(n):
            as.append(int(sys.stdin.readline()) - 1)
        print(Calculator(n, k, as).calculate())

class Calculator(object):
    def __init__(self, n, k, as):
        self.k = k
        self.answer = 0
        self.isCalculate = False
        self.lists = []
        for i in range(n):
            self.lists.append([])
        for i in range(n):
            j = as[i]
            if 0 < i:
                self.lists[j].append(i)
            elif 0 < j:
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
        if 0 < pre and h == self.k - 1:
            h = 0
            self.answer += 1
        else:
            h += 1
        return h

if __name__ == '__main__':
    threading.Thread(target=MyRunnable().run).start()

