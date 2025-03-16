class Main:
    def __init__(self):
        # Declare a 2D list 'path' to store the graph data and a 1D list 'pagerank' to store the pagerank values
        self.path = [[0] * 10 for _ in range(10)]
        self.pagerank = [0.0] * 10

    def calc(self, total_nodes):
        # Initialize the 'pagerank' list with the initial main value
        initial_main = 1.0 / total_nodes
        damping_factor = 0.85
        temp_main = [0.0] * 10  # Create a temporary list to store the updated pagerank values in each iteration

        # Initialize all the pagerank values with the initial main value
        for i in range(1, total_nodes + 1):
            self.pagerank[i] = initial_main

        iteration_step = 1  # Initialize the iteration counter

        # Perform the pagerank calculation for a maximum of 2 iterations
        while iteration_step <= 2:
            # Initialize the 'temp_main' list with the current pagerank values
            for i in range(1, total_nodes + 1):
                temp_main[i] = self.pagerank[i]

            # Update the pagerank values for each node based on the current pagerank values and the graph data
            for internal_node in range(1, total_nodes + 1):
                for external_node in range(1, total_nodes + 1):
                    if self.path[external_node][internal_node] == 1:  # If there is a link from external_node to internal_node
                        outgoing_links = 0  # Initialize the counter for the number of outgoing links from external_node

                        # Count the number of outgoing links from external_node
                        for k in range(1, total_nodes + 1):
                            if self.path[external_node][k] == 1:
                                outgoing_links += 1

                        # Update the pagerank value of internal_node based on the updated pagerank value of external_node and the number of outgoing links
                        self.pagerank[internal_node] += temp_main[external_node] / outgoing_links

            # Update the pagerank values by applying the damping factor
            for i in range(1, total_nodes + 1):
                self.pagerank[i] = (1 - damping_factor) + damping_factor * self.pagerank[i]

            iteration_step += 1  # Increment the iteration counter

        # Print the pagerank values for all the nodes
        for i in range(1, total_nodes + 1):
            print(f"Page Rank of Node {i}: {self.pagerank[i]:.6f}")

if __name__ == "__main__":
    import sys

    nodes = int(input())  # Read the number of nodes from the console
    p = Main()  # Create an instance of the Main class

    # Initialize the 'path' array with the given graph data
    for i in range(1, nodes + 1):
        for j in range(1, nodes + 1):
            p.path[i][j] = int(input())
            if i == j:
                p.path[i][j] = 0  # Set the diagonal elements to zero since there is no self-loop in the graph

    p.calc(nodes)  # Call the 'calc' method to calculate the pagerank values

# <END-OF-CODE>
