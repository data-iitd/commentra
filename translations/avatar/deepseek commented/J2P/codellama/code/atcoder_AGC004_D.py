
import sys

class MyRunnable(object):
    def run(self):
        # Start the MyRunnable thread to handle input and output
        threading.Thread(target=self.run).start()

    def __init__(self):
        # Read input values using Scanner
        sc = sys.stdin.readline()
        n = int(sc)
        k = int(sc)
        as = []
        for i in range(n):
            as.append(int(sc) - 1)

        # Initialize the Calculator object and calculate the result
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

# Start the MyRunnable thread to handle input and output
MyRunnable().run()

