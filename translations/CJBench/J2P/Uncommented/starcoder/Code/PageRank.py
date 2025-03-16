
import sys
import math

class Main:
    def __init__(self):
        self.path = [[0 for x in range(10)] for y in range(10)]
        self.pagerank = [0.0 for x in range(10)]

    def calc(self, totalNodes):
        initialMain = 1.0 / totalNodes
        dampingFactor = 0.85
        tempMain = [0.0 for x in range(10)]
        for i in range(1, totalNodes + 1):
            self.pagerank[i] = initialMain
        iterationStep = 1
        while iterationStep <= 2:
            for i in range(1, totalNodes + 1):
                tempMain[i] = self.pagerank[i]
                self.pagerank[i] = 0.0
            for internalNode in range(1, totalNodes + 1):
                for externalNode in range(1, totalNodes + 1):
                    if self.path[externalNode][internalNode] == 1:
                        outgoingLinks = 0
                        for k in range(1, totalNodes + 1):
                            if self.path[externalNode][k] == 1:
                                outgoingLinks += 1
                        self.pagerank[internalNode] += tempMain[externalNode] / outgoingLinks
            for i in range(1, totalNodes + 1):
                self.pagerank[i] = (1 - dampingFactor) + dampingFactor * self.pagerank[i]
            iterationStep += 1
        for i in range(1, totalNodes + 1):
            print("Page Rank of Node %d: %.6f" % (i, self.pagerank[i]))

if __name__ == "__main__":
    main = Main()
    totalNodes = int(sys.stdin.readline())
    for i in range(1, totalNodes + 1):
        for j in range(1, totalNodes + 1):
            main.path[i][j] = int(sys.stdin.readline())
            if i == j:
                main.path[i][j] = 0
    main.calc(totalNodes)

# 