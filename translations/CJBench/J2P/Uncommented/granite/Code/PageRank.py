

import sys

class Main:
    def __init__(self):
        self.path = [[0 for i in range(10)] for j in range(10)]
        self.pagerank = [0.1 for i in range(10)]

    def calc(self, totalNodes):
        dampingFactor = 0.85
        tempMain = [0.1 for i in range(10)]
        for i in range(1, totalNodes + 1):
            for j in range(1, totalNodes + 1):
                if i == j:
                    self.path[i - 1][j - 1] = 0
                else:
                    self.path[i - 1][j - 1] = int(sys.stdin.readline())
        for i in range(1, totalNodes + 1):
            for j in range(1, totalNodes + 1):
                if self.path[j - 1][i - 1] == 1:
                    outgoingLinks = 0
                    for k in range(1, totalNodes + 1):
                        if self.path[j - 1][k - 1] == 1:
                            outgoingLinks += 1
                    tempMain[i - 1] += self.pagerank[j - 1] / outgoingLinks
        for i in range(1, totalNodes + 1):
            self.pagerank[i - 1] = (1 - dampingFactor) + dampingFactor * tempMain[i - 1]
        for i in range(1, totalNodes + 1):
            print("Page Rank of Node %d: %.6f" % (i, self.pagerank[i - 1]))

if __name__ == "__main__":
    totalNodes = int(sys.stdin.readline())
    main = Main()
    main.calc(totalNodes)

