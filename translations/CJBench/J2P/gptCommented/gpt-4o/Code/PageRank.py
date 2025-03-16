class Main:
    def __init__(self):
        # 2D array to represent the path (adjacency matrix) between nodes
        self.path = [[0] * 10 for _ in range(10)]
        # Array to store the PageRank values of each node
        self.pagerank = [0.0] * 10

    def calc(self, total_nodes):
        # Initialize the PageRank value for each node
        initial_main = 1.0 / total_nodes
        # Damping factor for PageRank calculation
        damping_factor = 0.85
        # Temporary array to hold the previous PageRank values
        temp_main = [0.0] * 10
        
        # Set initial PageRank values for all nodes
        for i in range(1, total_nodes + 1):
            self.pagerank[i] = initial_main
        
        # Perform the PageRank calculation for a fixed number of iterations
        iteration_step = 1
        while iteration_step <= 2:
            # Store the current PageRank values in a temporary array
            for i in range(1, total_nodes + 1):
                temp_main[i] = self.pagerank[i]
                self.pagerank[i] = 0  # Reset the pagerank for the next iteration
            
            # Update the PageRank values based on the adjacency matrix
            for internal_node in range(1, total_nodes + 1):
                for external_node in range(1, total_nodes + 1):
                    # Check if there is a link from external_node to internal_node
                    if self.path[external_node][internal_node] == 1:
                        outgoing_links = 0
                        # Count the number of outgoing links from external_node
                        for k in range(1, total_nodes + 1):
                            if self.path[external_node][k] == 1:
                                outgoing_links += 1
                        # Update the PageRank of the internal_node based on the contribution from external_node
                        self.pagerank[internal_node] += temp_main[external_node] / outgoing_links
            
            # Apply the damping factor to the PageRank values
            for i in range(1, total_nodes + 1):
                self.pagerank[i] = (1 - damping_factor) + damping_factor * self.pagerank[i]
            # Move to the next iteration
            iteration_step += 1
        
        # Print the final PageRank values for each node
        for i in range(1, total_nodes + 1):
            print(f"Page Rank of Node {i}: {self.pagerank[i]:.6f}")

if __name__ == "__main__":
    # Create an instance of the Main class to access its methods
    p = Main()
    
    # Read the number of nodes from user input
    nodes = int(input("Enter the number of nodes: "))
    
    # Read the adjacency matrix from user input
    for i in range(1, nodes + 1):
        row = list(map(int, input().split()))
        for j in range(1, nodes + 1):
            p.path[i][j] = row[j - 1]
            # Set the diagonal to 0 since a node does not link to itself
            if i == j:
                p.path[i][j] = 0
    
    # Calculate the PageRank values based on the input graph
    p.calc(nodes)

# <END-OF-CODE>
