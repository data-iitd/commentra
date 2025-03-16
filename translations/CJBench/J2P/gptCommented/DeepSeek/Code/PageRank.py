import sys

class Main:
    def __init__(self):
        self.path = [[0] * 10 for _ in range(10)]
        self.pagerank = [0.0] * 10

    def calc(self, totalNodes):
        initial_pagerank = 1.0 / totalNodes
        damping_factor = 0.85
        temp_pagerank = [0.0] * 10

        for i in range(1, totalNodes + 1):
            self.pagerank[i] = initial_pagerank

        iteration_step = 1
        while iteration_step <= 2:
            for i in range(1, totalNodes + 1):
                temp_pagerank[i] = self.pagerank[i]
                self.pagerank[i] = 0.0

            for internal_node in range(1, totalNodes + 1):
                for external_node in range(1, totalNodes + 1):
                    if self.path[external_node][internal_node] == 1:
                        outgoing_links = sum(self.path[external_node][k] for k in range(1, totalNodes + 1))
                        self.pagerank[internal_node] += temp_pagerank[external_node] / outgoing_links

            for i in range(1, totalNodes + 1):
                self.pagerank[i] = (1 - damping_factor) + damping_factor * self.pagerank[i]

            iteration_step += 1

        for i in range(1, totalNodes + 1):
            print(f"Page Rank of Node {i}: {self.pagerank[i]:.6f}")


if __name__ == "__main__":
    inp = sys.stdin.readline
    nodes = int(inp())
    p = Main()

    for i in range(1, nodes + 1):
        row = list(map(int, inp().split()))
        for j in range(1, nodes + 1):
            p.path[i][j] = row[j - 1]
            if i == j:
                p.path[i][j] = 0

    p.calc(nodes)
