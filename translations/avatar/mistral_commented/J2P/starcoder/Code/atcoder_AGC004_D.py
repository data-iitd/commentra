
import sys

class Main:
    def __init__(self):
        self.sc = sys.stdin
        self.n = 0
        self.k = 0
        self.as = []
        self.lists = []
        self.answer = 0
        self.isCalculate = False

    def run(self):
        self.n = int(self.sc.readline())
        self.k = int(self.sc.readline())
        self.as = [int(x) - 1 for x in self.sc.readline().split()]
        self.lists = [[] for _ in range(self.n)]
        for i in range(self.n):
            for j in range(i + 1, self.n):
                if self.as[i] == self.as[j]:
                    self.answer += 1
                else:
                    self.lists[self.as[i]].append(self.as[j])
        self.dfs(0, -1)
        print(self.answer)

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
    obj = Main()
    obj.run()

