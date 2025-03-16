
# <START-OF-CODE>
import sys

class Main:
    def __init__(self):
        self.sc = Scanner(sys.stdin)
        self.n = self.sc.nextInt()
        self.k = self.sc.nextInt()
        self.as = []
        for i in range(self.n):
            self.as.append(self.sc.nextInt() - 1)
        self.answer = 0
        self.isCalculate = False
        self.lists = []
        for i in range(self.n):
            self.lists.append([])
        for i in range(self.n):
            j = self.as[i]
            if 0 < i:
                self.lists[j].append(i)
            elif 0 < j:
                self.answer += 1
        self.dfs(0, 0)
        self.isCalculate = True

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

    def calculate(self):
        return self.answer

if __name__ == "__main__":
    main = Main()
    print(main.calculate())
# 