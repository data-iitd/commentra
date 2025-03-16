class Graph:
    class Node:
        def __init__(self, name):
            self.name = name

    class Edge:
        def __init__(self, start_node, end_node):
            self.start_node = start_node
            self.end_node = end_node

    def __init__(self):
        self.edge_list = []  # List to hold edges
        self.node_list = []  # List to hold nodes

    def add_edge(self, start_node, end_node):
        start = None  # Variable to hold the starting node
        end = None    # Variable to hold the ending node

        # Search for existing nodes in the node list
        for node in self.node_list:
            if start_node == node.name:
                start = node  # Found the starting node
            elif end_node == node.name:
                end = node  # Found the ending node

        # If the starting node does not exist, create and add it to the node list
        if start is None:
            start = self.Node(start_node)
            self.node_list.append(start)
        # If the ending node does not exist, create and add it to the node list
        if end is None:
            end = self.Node(end_node)
            self.node_list.append(end)

        # Add a new edge connecting the start and end nodes
        self.edge_list.append(self.Edge(start, end))

    def count_graphs(self):
        count = 0  # Counter for distinct graphs
        marked_nodes = set()  # Set to keep track of visited nodes

        # Iterate through all nodes in the node list
        for n in self.node_list:
            # If the node has not been visited, perform DFS
            if n not in marked_nodes:
                marked_nodes.update(self.depth_first_search(n, set()))  # Mark all reachable nodes
                count += 1  # Increment the graph count
        return count  # Return the total count of distinct graphs

    def depth_first_search(self, n, visited):
        visited.add(n)  # Mark the current node as visited

        # Explore all edges starting from the current node
        for e in self.edge_list:
            # If the edge starts from the current node and the end node is not visited
            if e.start_node == n and e.end_node not in visited:
                self.depth_first_search(e.end_node, visited)  # Recursively visit the end node
        return visited  # Return the set of visited nodes


# Main execution
if __name__ == "__main__":
    char_edges = int(input("Enter number of edges for character graph: "))  # Read the number of edges for character graph
    graph_chars = Graph()  # Create a graph for characters

    # Read edges for the character graph
    for _ in range(char_edges):
        start = input("Enter starting character: ")  # Read starting character
        end = input("Enter ending character: ")      # Read ending character
        graph_chars.add_edge(start, end)  # Add the edge to the graph

    int_edges = int(input("Enter number of edges for integer graph: "))  # Read the number of edges for integer graph
    graph_ints = Graph()  # Create a graph for integers

    # Read edges for the integer graph
    for _ in range(int_edges):
        start = int(input("Enter starting integer: "))  # Read starting integer
        end = int(input("Enter ending integer: "))      # Read ending integer
        graph_ints.add_edge(start, end)  # Add the edge to the graph

    # Output the number of distinct character graphs
    print("Amount of different char-graphs:", graph_chars.count_graphs())
    # Output the number of distinct integer graphs
    print("Amount of different int-graphs:", graph_ints.count_graphs())

# <END-OF-CODE>
