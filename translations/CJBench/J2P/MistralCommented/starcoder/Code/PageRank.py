
import sys

class Main:
    # Declare a 2D integer array 'path' to store the graph data and a 1D double array 'pagerank' to store the pagerank values
    path = [[0 for x in range(10)] for y in range(10)]
    pagerank = [0.0 for x in range(10)]

    def __init__(self):
        # Initialize the 'path' array with the given graph data
        for i in range(1, 10):
            for j in range(1, 10):
                self.path[i][j] = int(sys.stdin.readline())
                if i == j:
                    self.path[i][j] = 0 # Set the diagonal elements to zero since there is no self-loop in the graph

        self.calc(9) # Call the 'calc' method to calculate the pagerank values

    def calc(self, totalNodes):
        # Initialize the 'pagerank' array with the initial main value
        initialMain = 1.0 / totalNodes
        dampingFactor = 0.85
        tempMain = [0.0 for x in range(10)] # Create a temporary array to store the updated pagerank values in each iteration

        # Initialize all the pagerank values with the initial main value
        for i in range(1, 10):
            self.pagerank[i] = initialMain

        iterationStep = 1 # Initialize the iteration counter

        # Perform the pagerank calculation for a maximum of 2 iterations
        while iterationStep <= 2:
            # Initialize the 'tempMain' array with the current pagerank values
            for i in range(1, 10):
                tempMain[i] = self.pagerank[i]

            # Update the pagerank values for each node based on the current pagerank values and the graph data
            for internalNode in range(1, 10):
                for externalNode in range(1, 10):
                    if self.path[externalNode][internalNode] == 1: # If there is a link from externalNode to internalNode
                        outgoingLinks = 0 # Initialize the counter for the number of outgoing links from externalNode

                        # Count the number of outgoing links from externalNode
                        for k in range(1, 10):
                            if self.path[externalNode][k] == 1:
                                outgoingLinks += 1

                        # Update the pagerank value of internalNode based on the updated pagerank value of externalNode and the number of outgoing links
                        self.pagerank[internalNode] += tempMain[externalNode] / outgoingLinks

            # Update the pagerank values by applying the damping factor
            for i in range(1, 10):
                self.pagerank[i] = (1 - dampingFactor) + dampingFactor * self.pagerank[i]

            iterationStep += 1 # Increment the iteration counter

        # Print the pagerank values for all the nodes
        for i in range(1, 10):
            print("Page Rank of Node %d: %.6f" % (i, self.pagerank[i]))

if __name__ == "__main__":
    Main()

