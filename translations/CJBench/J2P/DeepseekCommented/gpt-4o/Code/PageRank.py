import sys

class Main:
    # Matrix to store the paths between nodes
    path = [[0 for _ in range(10)] for _ in range(10)]
    # Array to store the PageRank values for each node
    pagerank = [0.0] * 10

    def calc(self, totalNodes):
        # Initial PageRank for each node
        initialPageRank = 1.0 / totalNodes
        # Damping factor
        dampingFactor = 0.85
        # Temporary array to hold PageRank values during each iteration
        tempPageRank = [0.0] * 10
        # Initialize the PageRank values
        for i in range(1, totalNodes + 1):
            self.pagerank[i] = initialPageRank

        # Number of iterations (fixed at 2 in this case)
        iterationStep = 1
        # PageRank loop to iterate and update PageRank values
        while iterationStep <= 2:
            # Copy current PageRank values to tempPageRank array
            for i in range(1, totalNodes + 1):
                tempPageRank[i] = self.pagerank[i]
                self.pagerank[i] = 0.0  # Reset current PageRank values

            # Update PageRank values based on incoming links
            for internalNode in range(1, totalNodes + 1):
                for externalNode in range(1, totalNodes + 1):
                    if self.path[externalNode][internalNode] == 1:
                        outgoingLinks = sum(self.path[externalNode][k] for k in range(1, totalNodes + 1))
                        # Add to the PageRank of the internalNode
                        self.pagerank[internalNode] += tempPageRank[externalNode] / outgoingLinks

            # Apply damping factor to the PageRank values
            for i in range(1, totalNodes + 1):
                self.pagerank[i] = (1 - dampingFactor) + dampingFactor * self.pagerank[i]

            # Increment the iteration step
            iterationStep += 1

        # Print the PageRank values for each node
        for i in range(1, totalNodes + 1):
            print(f"Page Rank of Node {i}: {self.pagerank[i]:.6f}")

# Main function to read input and initialize the object
if __name__ == "__main__":
    # Read the number of nodes
    nodes = int(sys.stdin.readline().strip())
    p = Main()
    # Read the path matrix from the user
    for i in range(1, nodes + 1):
        row = list(map(int, sys.stdin.readline().strip().split()))
        for j in range(1, nodes + 1):
            p.path[i][j] = row[j - 1]
            # Diagonal elements are set to 0 as they represent a node pointing to itself
            if i == j:
                p.path[i][j] = 0

    # Calculate the PageRank values
    p.calc(nodes)
