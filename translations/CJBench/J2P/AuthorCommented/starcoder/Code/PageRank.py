
import sys

class Main:

    # Adjacency matrix to represent the link structure between webpages
    path = [[0 for x in range(10)] for x in range(10)]

    # Array to store the Main values for each webpage
    pagerank = [0.0] * 10

    def __init__(self):
        # Read number of webpages
        nodes = int(sys.stdin.readline())

        # Read adjacency matrix
        for i in range(1, nodes + 1):
            line = sys.stdin.readline().split()
            for j in range(1, nodes + 1):
                self.path[i][j] = int(line[j - 1])
                if i == j:
                    self.path[i][j] = 0 # Remove self-loops

        # Calculate Main
        self.calc(nodes)

    def calc(self, totalNodes):
        initialMain = 1.0 / totalNodes
        dampingFactor = 0.85
        tempMain = [0.0] * 10

        # Initialize Main values
        for i in range(1, totalNodes + 1):
            self.pagerank[i] = initialMain

        iterationStep = 1

        # Perform iterations to compute Main
        while iterationStep <= 2: # Perform 2 iterations
            for i in range(1, totalNodes + 1):
                tempMain[i] = self.pagerank[i]
                self.pagerank[i] = 0

            for internalNode in range(1, totalNodes + 1):
                for externalNode in range(1, totalNodes + 1):
                    if self.path[externalNode][internalNode] == 1:
                        outgoingLinks = 0

                        for k in range(1, totalNodes + 1):
                            if self.path[externalNode][k] == 1:
                                outgoingLinks += 1

                        # Compute contribution from externalNode to internalNode
                        self.pagerank[internalNode] += tempMain[externalNode] / outgoingLinks

            # Apply damping factor
            for i in range(1, totalNodes + 1):
                self.pagerank[i] = (1 - dampingFactor) + dampingFactor * self.pagerank[i]

            iterationStep += 1

        # Print final Main values
        for i in range(1, totalNodes + 1):
            print("Page Rank of Node %d: %.6f" % (i, self.pagerank[i]))

if __name__ == "__main__":
    Main()

