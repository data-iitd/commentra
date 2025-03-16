import sys

class Main:
    def __init__(self, nodes):
        self.path = [[0 for _ in range(nodes)] for _ in range(nodes)]
        self.pagerank = [0.0] * nodes

    def calc(self, total_nodes):
        initial_pagerank = 1.0 / total_nodes
        damping_factor = 0.85
        temp_pagerank = [0.0] * total_nodes

        # Initialize PageRank values
        for i in range(total_nodes):
            self.pagerank[i] = initial_pagerank

        iteration_step = 1

        # Perform iterations to compute PageRank
        while iteration_step <= 2:  # Perform 2 iterations
            for i in range(total_nodes):
                temp_pagerank[i] = self.pagerank[i]
                self.pagerank[i] = 0

            for internal_node in range(total_nodes):
                for external_node in range(total_nodes):
                    if self.path[external_node][internal_node] == 1:
                        outgoing_links = sum(self.path[external_node][k] for k in range(total_nodes))

                        # Compute contribution from externalNode to internalNode
                        self.pagerank[internal_node] += temp_pagerank[external_node] / outgoing_links

            # Apply damping factor
            for i in range(total_nodes):
                self.pagerank[i] = (1 - damping_factor) + damping_factor * self.pagerank[i]

            iteration_step += 1

        # Print final PageRank values
        for i in range(total_nodes):
            print(f"Page Rank of Node {i + 1}: {self.pagerank[i]:.6f}")


def main():
    # Read number of webpages
    nodes = int(sys.stdin.readline().strip())

    # Initialize Main object
    p = Main(nodes)

    # Read adjacency matrix
    for i in range(nodes):
        row = list(map(int, sys.stdin.readline().strip().split()))
        for j in range(nodes):
            p.path[i][j] = row[j]
            if i == j:
                p.path[i][j] = 0  # Remove self-loops

    # Calculate PageRank
    p.calc(nodes)


if __name__ == "__main__":
    main()

