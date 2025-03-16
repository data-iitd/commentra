

import sys

# Adjacency matrix to represent the link structure between webpages
path = [[0 for i in range(10)] for j in range(10)]

# Array to store the Main values for each webpage
pagerank = [0 for i in range(10)]

# Read number of webpages
nodes = int(sys.stdin.readline())

# Read adjacency matrix
for i in range(1, nodes + 1):
    for j in range(1, nodes + 1):
        path[i][j] = int(sys.stdin.readline())
        if i == j:
            path[i][j] = 0  # Remove self-loops

# Calculate Main
def calc(totalNodes):
    initialMain = 1.0 / totalNodes
    dampingFactor = 0.85
    tempMain = [0 for i in range(10)]

    # Initialize Main values
    for i in range(1, totalNodes + 1):
        pagerank[i] = initialMain

    iterationStep = 1

    # Perform iterations to compute Main
    while iterationStep <= 2:  # Perform 2 iterations
        for i in range(1, totalNodes + 1):
            tempMain[i] = pagerank[i]
            pagerank[i] = 0

        for internalNode in range(1, totalNodes + 1):
            for externalNode in range(1, totalNodes + 1):
                if path[externalNode][internalNode] == 1:
                    outgoingLinks = 0

                    for k in range(1, totalNodes + 1):
                        if path[externalNode][k] == 1:
                            outgoingLinks += 1

                    # Compute contribution from externalNode to internalNode
                    pagerank[internalNode] += tempMain[externalNode] / outgoingLinks

        # Apply damping factor
        for i in range(1, totalNodes + 1):
            pagerank[i] = (1 - dampingFactor) + dampingFactor * pagerank[i]

        iterationStep += 1

    # Print final Main values
    for i in range(1, totalNodes + 1):
        print("Page Rank of Node %d: %.6f" % (i, pagerank[i]))


# Call the function
calc(nodes)

# END-OF-CODE
