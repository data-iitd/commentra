import sys

# Create a Scanner object to read input from the user
in = sys.stdin

# Read the number of nodes from user input
nodes = int(in.readline())
# Create an instance of the Main class to access its methods
p = Main()

# Read the adjacency matrix from user input
for i in range(1, nodes + 1):
    for j in range(1, nodes + 1):
        p.path[i][j] = int(in.readline())
        # Set the diagonal to 0 since a node does not link to itself
        if i == j:
            p.path[i][j] = 0

# Calculate the Main values based on the input graph
p.calc(nodes)
# Close the scanner to prevent resource leaks
in.close()


class Main:
    # 2D array to represent the path (adjacency matrix) between nodes
    path = [[0 for i in range(10)] for j in range(10)]
    # Array to store the Main values of each node
    pagerank = [0 for i in range(10)]

    def calc(self, totalNodes):
        # Initialize the Main value for each node
        initialMain = 1.0 / totalNodes
        # Damping factor for Main calculation
        dampingFactor = 0.85
        # Temporary array to hold the previous Main values
        tempMain = [0 for i in range(10)]

        # Set initial Main values for all nodes
        for i in range(1, totalNodes + 1):
            self.pagerank[i] = initialMain

        # Perform the Main calculation for a fixed number of iterations
        iterationStep = 1
        while iterationStep <= 2:
            # Store the current Main values in a temporary array
            for i in range(1, totalNodes + 1):
                tempMain[i] = self.pagerank[i]
                self.pagerank[i] = 0  # Reset the pagerank for the next iteration

            # Update the Main values based on the adjacency matrix
            for internalNode in range(1, totalNodes + 1):
                for externalNode in range(1, totalNodes + 1):
                    # Check if there is a link from externalNode to internalNode
                    if self.path[externalNode][internalNode] == 1:
                        outgoingLinks = 0
                        # Count the number of outgoing links from externalNode
                        for k in range(1, totalNodes + 1):
                            if self.path[externalNode][k] == 1:
                                outgoingLinks += 1
                        # Update the Main of the internalNode based on the contribution from externalNode
                        self.pagerank[internalNode] += tempMain[externalNode] / outgoingLinks

            # Apply the damping factor to the Main values
            for i in range(1, totalNodes + 1):
                self.pagerank[i] = (1 - dampingFactor) + dampingFactor * self.pagerank[i]
            # Move to the next iteration
            iterationStep += 1

        # Print the final Main values for each node
        for i in range(1, totalNodes + 1):
            print("Page Rank of Node %d: %.6f" % (i, self.pagerank[i]))


