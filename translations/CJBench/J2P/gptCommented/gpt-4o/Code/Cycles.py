class Cycle:
    def __init__(self, nodes, edges, edges_input):
        self.nodes = nodes  # Number of nodes in the graph
        self.adjacency_matrix = [[0] * nodes for _ in range(nodes)]  # Initialize adjacency matrix
        self.visited = [False] * nodes  # Initialize visited array
        self.cycles = []  # List to store found cycles

        # Populate the adjacency matrix based on the input edges
        for edge in edges_input:
            start, end = edge
            self.adjacency_matrix[start][end] = 1  # Mark the edge in the adjacency matrix

    def start(self):
        # Iterate through each node to initiate DFS
        for i in range(self.nodes):
            temp = []  # Temporary list to store the current path
            self.dfs(i, i, temp)  # Start DFS from the current node
            # Reset the adjacency matrix for the current node to avoid duplicate cycles
            for j in range(self.nodes):
                self.adjacency_matrix[i][j] = 0
                self.adjacency_matrix[j][i] = 0

    def dfs(self, start, curr, temp):
        temp.append(curr)  # Add the current node to the path
        self.visited[curr] = True  # Mark the current node as visited
        # Explore all adjacent nodes
        for i in range(self.nodes):
            if self.adjacency_matrix[curr][i] == 1:  # Check if there is an edge
                if i == start:  # Check if we found a cycle
                    self.cycles.append(temp.copy())  # Store the found cycle
                else:
                    if not self.visited[i]:  # If the node is not visited, continue DFS
                        self.dfs(start, i, temp)

        # Backtrack: remove the current node from the path
        if temp:
            temp.pop()
        self.visited[curr] = False  # Mark the current node as unvisited for future searches

    def print_all(self):
        if not self.cycles:  # Check if no cycles were found
            print("No cycles found.")
            return
        # Print each cycle
        for cycle in self.cycles:
            for i in range(len(cycle)):
                print(cycle[i], end=" -> ")  # Print the cycle path
            print(cycle[0])  # Complete the cycle by returning to the start
            print()  # Print a new line for better readability


# Main function to execute the cycle detection program
if __name__ == "__main__":
    nodes = int(input())  # Read the number of nodes
    edges = int(input())  # Read the number of edges
    edges_input = [list(map(int, input().split())) for _ in range(edges)]  # Read the edges from input
    # Create a Cycle object to find cycles in the graph
    cycle_finder = Cycle(nodes, edges, edges_input)
    cycle_finder.start()  # Start the cycle detection process
    cycle_finder.print_all()  # Print all found cycles

# <END-OF-CODE>
