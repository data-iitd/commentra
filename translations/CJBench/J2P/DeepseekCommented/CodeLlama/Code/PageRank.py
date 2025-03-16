import sys

def main():
    # Read the number of nodes
    nodes = int(sys.stdin.readline())
    # Matrix to store the paths between nodes
    path = [[0 for i in range(nodes+1)] for j in range(nodes+1)]
    # Array to store the Main values for each node
    pagerank = [0 for i in range(nodes+1)]

    # Read the path matrix from the user
    for i in range(1, nodes+1):
        for j in range(1, nodes+1):
            path[i][j] = int(sys.stdin.readline())
            # Diagonal elements are set to 0 as they represent a node pointing to itself
            if i == j:
                path[i][j] = 0

    # Calculate the Main values
    calc(nodes, path, pagerank)

def calc(totalNodes, path, pagerank):
    # Initial Main for each node
    initialMain = 1.0 / totalNodes
    # Damping factor
    dampingFactor = 0.85
    # Temporary array to hold Main values during each iteration
    tempMain = [0 for i in range(totalNodes+1)]
    # Initialize the Main values
    for i in range(1, totalNodes+1):
        pagerank[i] = initialMain

    # Number of iterations (fixed at 2 in this case)
    iterationStep = 1
    # Main loop to iterate and update Main values
    while iterationStep <= 2:
        # Copy current Main values to tempMain array
        for i in range(1, totalNodes+1):
            tempMain[i] = pagerank[i]
            pagerank[i] = 0 # Reset current Main values

        # Update Main values based on incoming links
        for internalNode in range(1, totalNodes+1):
            for externalNode in range(1, totalNodes+1):
                if path[externalNode][internalNode] == 1:
                    outgoingLinks = 0
                    # Count outgoing links from the externalNode
                    for k in range(1, totalNodes+1):
                        if path[externalNode][k] == 1:
                            outgoingLinks += 1
                    # Add to the Main of the internalNode
                    pagerank[internalNode] += tempMain[externalNode] / outgoingLinks

        # Apply damping factor to the Main values
        for i in range(1, totalNodes+1):
            pagerank[i] = (1 - dampingFactor) + dampingFactor * pagerank[i]

        # Increment the iteration step
        iterationStep += 1

    # Print the Main values for each node
    for i in range(1, totalNodes+1):
        print("Page Rank of Node %d: %.6f" % (i, pagerank[i]))

if __name__ == "__main__":
    main()

