

import sys

class Main:
    def __init__(self):
        self.path = [[0 for _ in range(10)] for _ in range(10)]
        self.pagerank = [0.1 for _ in range(10)]

    def calc(self, total_nodes):
        initial_main = 1.0 / total_nodes
        damping_factor = 0.85
        temp_main = [0.1 for _ in range(10)]
        iteration_step = 1

        while iteration_step <= 2:
            for i in range(total_nodes):
                temp_main[i] = self.pagerank[i]

            for internal_node in range(total_nodes):
                for external_node in range(total_nodes):
                    if self.path[external_node][internal_node] == 1:
                        outgoing_links = 0
                        for k in range(total_nodes):
                            if self.path[external_node][k] == 1:
                                outgoing_links += 1
                        self.pagerank[internal_node] += temp_main[external_node] / outgoing_links

            for i in range(total_nodes):
                self.pagerank[i] = (1 - damping_factor) + damping_factor * self.pagerank[i]

            iteration_step += 1

        for i in range(total_nodes):
            print(f"Page Rank of Node {i+1}: {self.pagerank[i]:.6f}")

if __name__ == "__main__":
    total_nodes = int(input())
    main = Main()

    for i in range(total_nodes):
        for j in range(total_nodes):
            main.path[i][j] = int(input())

    main.calc(total_nodes)

