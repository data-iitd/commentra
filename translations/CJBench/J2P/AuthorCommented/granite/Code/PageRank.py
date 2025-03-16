

import sys

# Adjacency matrix to represent the link structure between webpages
path = [[0 for _ in range(10)] for _ in range(10)]

# Array to store the Main values for each webpage
pagerank = [0.1 for _ in range(10)]

def calc(total_nodes):
    damping_factor = 0.85
    temp_pagerank = [0.1 for _ in range(10)]
    iteration_step = 1

    # Initialize Main values
    for i in range(total_nodes):
        pagerank[i] = 0.1

    # Perform iterations to compute Main
    while iteration_step <= 2: # Perform 2 iterations
        for i in range(total_nodes):
            temp_pagerank[i] = pagerank[i]
            pagerank[i] = 0

        for internal_node in range(total_nodes):
            for external_node in range(total_nodes):
                if path[external_node][internal_node] == 1:
                    outgoing_links = 0

                    for k in range(total_nodes):
                        if path[external_node][k] == 1:
                            outgoing_links += 1

                    # Compute contribution from externalNode to internalNode
                    pagerank[internal_node] += temp_pagerank[external_node] / outgoing_links

        # Apply damping factor
        for i in range(total_nodes):
            pagerank[i] = (1 - damping_factor) + damping_factor * pagerank[i]

        iteration_step += 1

    # Print final Main values
    for i in range(total_nodes):
        print(f"Page Rank of Node {i+1}: {pagerank[i]}")

if __name__ == "__main__":
    total_nodes = int(input())

    # Read adjacency matrix
    for i in range(total_nodes):
        for j in range(total_nodes):
            path[i][j] = int(input())

    # Calculate Main
    calc(total_nodes)

