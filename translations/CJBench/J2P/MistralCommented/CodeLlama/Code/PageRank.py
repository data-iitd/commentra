
import sys

def main():
    # Declare a 2D integer array 'path' to store the graph data and a 1D double array 'pagerank' to store the pagerank values
    path = [[0 for i in range(10)] for j in range(10)]
    pagerank = [0.0 for i in range(10)]

    # Read the number of nodes from the console
    nodes = int(sys.stdin.readline())

    # Initialize the 'path' array with the given graph data
    for i in range(1, nodes + 1):
        for j in range(1, nodes + 1):
            path[i][j] = int(sys.stdin.readline())
            if i == j:
                path[i][j] = 0 # Set the diagonal elements to zero since there is no self-loop in the graph

    # Call the 'calc' method to calculate the pagerank values
    calc(nodes)

def calc(totalNodes):
    # Initialize the 'pagerank' array with the initial main value
    initialMain = 1.0 / totalNodes
    dampingFactor = 0.85
    tempMain = [0.0 for i in range(10)] # Create a temporary array to store the updated pagerank values in each iteration

    # Initialize all the pagerank values with the initial main value
    for i in range(1, totalNodes + 1):
        pagerank[i] = initialMain

    iterationStep = 1 # Initialize the iteration counter

    # Perform the pagerank calculation for a maximum of 2 iterations
    while iterationStep <= 2:
        # Initialize the 'tempMain' array with the current pagerank values
        for i in range(1, totalNodes + 1):
            tempMain[i] = pagerank[i]

        # Update the pagerank values for each node based on the current pagerank values and the graph data
        for internalNode in range(1, totalNodes + 1):
            for externalNode in range(1, totalNodes + 1):
                if path[externalNode][internalNode] == 1: # If there is a link from externalNode to internalNode
                    outgoingLinks = 0 # Initialize the counter for the number of outgoing links from externalNode

                    # Count the number of outgoing links from externalNode
                    for k in range(1, totalNodes + 1):
                        if path[externalNode][k] == 1:
                            outgoingLinks += 1

                    # Update the pagerank value of internalNode based on the updated pagerank value of externalNode and the number of outgoing links
                    pagerank[internalNode] += tempMain[externalNode] / outgoingLinks

        # Update the pagerank values by applying the damping factor
        for i in range(1, totalNodes + 1):
            pagerank[i] = (1 - dampingFactor) + dampingFactor * pagerank[i]

        iterationStep += 1 # Increment the iteration counter

    # Print the pagerank values for all the nodes
    for i in range(1, totalNodes + 1):
        print("Page Rank of Node %d: %.6f" % (i, pagerank[i]))

if __name__ == "__main__":
    main()

