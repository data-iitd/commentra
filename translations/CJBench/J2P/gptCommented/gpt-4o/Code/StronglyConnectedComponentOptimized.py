from collections import defaultdict

class Main:
    # Depth-first search (DFS) to explore the graph and track the order of nodes
    def btrack(self, adj_list, visited, dfs_calls_nodes, current_node):
        # Mark the current node as visited
        visited[current_node] = 1
        # Get the neighbors of the current node
        neighbors = adj_list.get(current_node, [])
        # Explore each neighbor that has not been visited
        for neighbor in neighbors:
            if visited[neighbor] == -1:
                self.btrack(adj_list, visited, dfs_calls_nodes, neighbor)
        # Add the current node to the stack after exploring all its neighbors
        dfs_calls_nodes.append(current_node)

    # DFS for the reverse graph to find strongly connected components (SCCs)
    def btrack2(self, adj_rev_list, visited, current_node, new_scc):
        # Mark the current node as visited
        visited[current_node] = 1
        # Add the current node to the current strongly connected component
        new_scc.append(current_node)
        # Get the neighbors of the current node in the reverse graph
        neighbors = adj_rev_list.get(current_node, [])
        # Explore each neighbor that has not been visited
        for neighbor in neighbors:
            if visited[neighbor] == -1:
                self.btrack2(adj_rev_list, visited, neighbor, new_scc)

    # Main function to compute the number of strongly connected components
    def get_output(self, adj_list, n):
        # Initialize visited array and stack for DFS
        visited = [-1] * n
        dfs_calls_nodes = []
        
        # Perform DFS on each node to fill the stack with the finishing order
        for i in range(n):
            if visited[i] == -1:
                self.btrack(adj_list, visited, dfs_calls_nodes, i)

        # Create the reverse graph
        adj_rev_list = defaultdict(list)
        # Populate the reverse graph
        for i in range(n):
            neighbors = adj_list.get(i, [])
            for neighbor in neighbors:
                adj_rev_list[neighbor].append(i)

        # Reset visited array for the second DFS
        visited = [-1] * n
        strongly_connected_components = 0

        # Process nodes in the order defined by the first DFS
        while dfs_calls_nodes:
            node = dfs_calls_nodes.pop()
            # If the node has not been visited, it starts a new SCC
            if visited[node] == -1:
                new_scc = []
                self.btrack2(adj_rev_list, visited, node, new_scc)
                strongly_connected_components += 1
        # Return the total number of strongly connected components found
        return strongly_connected_components

if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().splitlines()
    
    try:
        # Read number of nodes and edges from input
        n, e = map(int, data[0].split())
        adj_list = defaultdict(list)
        # Build the adjacency list from input edges
        for i in range(1, e + 1):
            src, dest = map(int, data[i].split())
            adj_list[src].append(dest)
        # Create an instance of the SCC finder and get the result
        scc_finder = Main()
        result = scc_finder.get_output(adj_list, n)
        # Output the number of strongly connected components
        print("Number of strongly connected components:", result)
    except ValueError:
        # Handle invalid input
        print("Invalid input. Please provide integers as input.")
    except IndexError:
        # Handle case where input is not as expected
        print("Invalid input format.")
        
# <END-OF-CODE>
