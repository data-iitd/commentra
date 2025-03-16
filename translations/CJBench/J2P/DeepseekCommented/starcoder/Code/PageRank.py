import sys

class Main:
    # Matrix to store the paths between nodes
    path = [[0 for x in range(10)] for y in range(10)]
    # Array to store the Main values for each node
    pagerank = [0 for x in range(10)]

    def __init__(self):
        # Read the number of nodes
        nodes = int(sys.stdin.readline())
        # Read the path matrix from the user
        for i in range(1, nodes + 1):
            line = sys.stdin.readline().split()
            for j in range(1, nodes + 1):
                self.path[i][j] = int(line[j - 1])
                # Diagonal elements are set to 0 as they represent a node pointing to itself
                if i == j:
                    self.path[i][j] = 0
        # Calculate the Main values
        self.calc(nodes)

    # Method to calculate the Main values
    def calc(self, totalNodes):
        # Initial Main for each node
        initialMain = 1.0 / totalNodes
        # Damping factor
        dampingFactor = 0.85
        # Temporary array to hold Main values during each iteration
        tempMain = [0 for x in range(10)]
        # Initialize the Main values
        for i in range(1, totalNodes + 1):
            self.pagerank[i] = initialMain
        # Number of iterations (fixed at 2 in this case)
        iterationStep = 1
        # Main loop to iterate and update Main values
        while iterationStep <= 2: 
            # Copy current Main values to tempMain array
            for i in range(1, totalNodes + 1):
                tempMain[i] = self.pagerank[i]
                self.pagerank[i] = 0 # Reset current Main values
            # Update Main values based on incoming links
            for internalNode in range(1, totalNodes + 1):
                for externalNode in range(1, totalNodes + 1):
                    if self.path[externalNode][internalNode] == 1:
                        outgoingLinks = 0
                        # Count outgoing links from the externalNode
                        for k in range(1, totalNodes + 1):
                            if self.path[externalNode][k] == 1:
                                outgoingLinks += 1
                        # Add to the Main of the internalNode
                        self.pagerank[internalNode] += tempMain[externalNode] / outgoingLinks
            # Apply damping factor to the Main values
            for i in range(1, totalNodes + 1):
                self.pagerank[i] = (1 - dampingFactor) + dampingFactor * self.pagerank[i]
            # Increment the iteration step
            iterationStep += 1
        # Print the Main values for each node
        for i in range(1, totalNodes + 1):
            print("Page Rank of Node %d: %.6f" % (i, self.pagerank[i]))

if __name__ == "__main__":
    Main()

