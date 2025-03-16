class Main:
    def __init__(self):
        self.path = [[0] * 10 for _ in range(10)]
        self.pagerank = [0.0] * 10

    def calc(self, total_nodes):
        initial_main = 1.0 / total_nodes
        damping_factor = 0.85
        temp_main = [0.0] * 10
        
        for i in range(1, total_nodes + 1):
            self.pagerank[i] = initial_main
        
        iteration_step = 1
        while iteration_step <= 2:
            for i in range(1, total_nodes + 1):
                temp_main[i] = self.pagerank[i]
                self.pagerank[i] = 0
            
            for internal_node in range(1, total_nodes + 1):
                for external_node in range(1, total_nodes + 1):
                    if self.path[external_node][internal_node] == 1:
                        outgoing_links = sum(1 for k in range(1, total_nodes + 1) if self.path[external_node][k] == 1)
                        self.pagerank[internal_node] += temp_main[external_node] / outgoing_links
            
            for i in range(1, total_nodes + 1):
                self.pagerank[i] = (1 - damping_factor) + damping_factor * self.pagerank[i]
            
            iteration_step += 1
        
        for i in range(1, total_nodes + 1):
            print(f"Page Rank of Node {i}: {self.pagerank[i]:.6f}")

if __name__ == "__main__":
    nodes = int(input())
    p = Main()
    for i in range(1, nodes + 1):
        for j in range(1, nodes + 1):
            p.path[i][j] = int(input())
            if i == j:
                p.path[i][j] = 0
    
    p.calc(nodes)

# <END-OF-CODE>
