from collections import defaultdict

class Main:
    # Method to perform Depth First Search (DFS) and find strongly connected components
    def btrack(self, adj_list, visited, dfs_calls_nodes, current_node):
        # Mark the current node as visited
        visited[current_node] = 1

        # Get the list of neighbors for the current node
        neighbors = adj_list.get(current_node, [])

        # If the current node has neighbors, iterate through them and call recursively
        for neighbor in neighbors:
            # If the neighbor is not visited, call btrack recursively
            if visited[neighbor] == -1:
                self.btrack(adj_list, visited, dfs_calls_nodes, neighbor)

        # Add the current node to the stack of DFS call nodes
        dfs_calls_nodes.append(current_node)

    # Method to find strongly connected components using Depth First Search (DFS) and recursion
    def btrack2(self, adj_rev_list, visited, current_node, new_scc):
        # Mark the current node as visited
        visited[current_node] = 1

        # Add the current node to the list of nodes in the current strongly connected component
        new_scc.append(current_node)

        # Get the list of neighbors for the current node
        neighbors = adj_rev_list.get(current_node, [])

        # If the current node has neighbors, iterate through them and call recursively
        for neighbor in neighbors:
            # If the neighbor is not visited, call btrack2 recursively
            if visited[neighbor] == -1:
                self.btrack2(adj_rev_list, visited, neighbor, new_scc)

    # Method to find the number of strongly connected components in the given graph
    def get_output(self, adj_list, n):
        # Initialize the visited array and fill it with -1
        visited = [-1] * n

        # Initialize the stack for DFS call nodes
        dfs_calls_nodes = []

        # Iterate through all nodes in the graph and call btrack for each unvisited node
        for i in range(n):
            if visited[i] == -1:
                self.btrack(adj_list, visited, dfs_calls_nodes, i)

        # Initialize an empty dictionary for the reversed adjacency list
        adj_rev_list = defaultdict(list)

        # Create the reversed adjacency list
        for src in adj_list:
            for dest in adj_list[src]:
                adj_rev_list[dest].append(src)

        # Initialize the visited array and fill it with -1
        visited = [-1] * n

        # Initialize the counter for the number of strongly connected components
        strongly_connected_components = 0

        # While there are still nodes in the stack of DFS call nodes
        while dfs_calls_nodes:
            # Get the next node from the stack
            node = dfs_calls_nodes.pop()

            # If the node is not visited, call btrack2 recursively and increment the counter
            if visited[node] == -1:
                new_scc = []
                self.btrack2(adj_rev_list, visited, node, new_scc)
                strongly_connected_components += 1

        # Return the number of strongly connected components
        return strongly_connected_components

# Main method to read input and call get_output method
if __name__ == "__main__":
    import sys

    # Initialize the input reading
    input_data = sys.stdin.read().strip().splitlines()
    n, e = map(int, input_data[0].split())

    # Initialize the adjacency list for the graph
    adj_list = defaultdict(list)

    # Read the edges and add them to the adjacency list
    for i in range(1, e + 1):
        src, dest = map(int, input_data[i].split())
        adj_list[src].append(dest)

    # Create an instance of the Main class and call the get_output method
    scc_finder = Main()
    result = scc_finder.get_output(adj_list, n)

    # Print the result to the console
    print("Number of strongly connected components:", result)

# <END-OF-CODE>
