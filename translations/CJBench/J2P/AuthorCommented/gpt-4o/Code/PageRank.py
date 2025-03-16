class Main:
    def __init__(self):
        # Adjacency matrix to represent the link structure between webpages
        self.path = [[0] * 10 for _ in range(10)]
        # Array to store the PageRank values for each webpage
        self.pagerank = [0.0] * 10

    def calc(self, total_nodes):
        initial_main = 1.0 / total_nodes
        damping_factor = 0.85
        temp_main = [0.0] * 10

        # Initialize PageRank values
        for i in range(1, total_nodes + 1):
            self.pagerank[i] = initial_main

        iteration_step = 1

        # Perform iterations to compute PageRank
        while iteration_step <= 2:  # Perform 2 iterations
            for i in range(1, total_nodes + 1):
                temp_main[i] = self.pagerank[i]
                self.pagerank[i] = 0

            for internal_node in range(1, total_nodes + 1):
                for external_node in range(1, total_nodes + 1):
                    if self.path[external_node][internal_node] == 1:
                        outgoing_links = sum(1 for k in range(1, total_nodes + 1) if self.path[external_node][k] == 1)

                        # Compute contribution from external_node to internal_node
                        self.pagerank[internal_node] += temp_main[external_node] / outgoing_links

            # Apply damping factor
            for i in range(1, total_nodes + 1):
                self.pagerank[i] = (1 - damping_factor) + damping_factor * self.pagerank[i]

            iteration_step += 1

        # Print final PageRank values
        for i in range(1, total_nodes + 1):
            print(f"Page Rank of Node {i}: {self.pagerank[i]:.6f}")

if __name__ == "__main__":
    import sys

    # Read number of webpages
    nodes = int(sys.stdin.readline().strip())

    # Initialize Main object
    p = Main()

    # Read adjacency matrix
    for i in range(1, nodes + 1):
        row = list(map(int, sys.stdin.readline().strip().split()))
        for j in range(1, nodes + 1):
            p.path[i][j] = row[j - 1]
            if i == j:
                p.path[i][j] = 0  # Remove self-loops

    # Calculate PageRank
    p.calc(nodes)

# <END-OF-CODE>
