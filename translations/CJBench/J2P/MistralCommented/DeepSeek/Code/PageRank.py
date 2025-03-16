import sys

class Main:
    def __init__(self):
        self.path = [[0] * 10 for _ in range(10)]
        self.pagerank = [0.0] * 10

    def calc(self, totalNodes):
        initialMain = 1.0 / totalNodes
        dampingFactor = 0.85
        tempMain = [0.0] * 10

        for i in range(1, totalNodes + 1):
            self.pagerank[i] = initialMain

        iterationStep = 1

        while iterationStep <= 2:
            for i in range(1, totalNodes + 1):
                tempMain[i] = self.pagerank[i]

            for internalNode in range(1, totalNodes + 1):
                for externalNode in range(1, totalNodes + 1):
                    if self.path[externalNode][internalNode] == 1:
                        outgoingLinks = sum(self.path[externalNode][k] for k in range(1, totalNodes + 1))
                        self.pagerank[internalNode] += tempMain[externalNode] / outgoingLinks

            for i in range(1, totalNodes + 1):
                self.pagerank[i] = (1 - dampingFactor) + dampingFactor * self.pagerank[i]

            iterationStep += 1

        for i in range(1, totalNodes + 1):
            print(f"Page Rank of Node {i}: {self.pagerank[i]:.6f}")


if __name__ == "__main__":
    inp = sys.stdin.readline
    nodes = int(inp())
    p = Main()

    for i in range(1, nodes + 1):
        row = list(map(int, inp().split()))
        for j in range(1, nodes + 1):
            p.path[i][j] = row[j - 1]
            if i == j:
                p.path[i][j] = 0

    p.calc(nodes)
