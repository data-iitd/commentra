class Graph:
    class Node:
        def __init__(self, name):
            self.name = name

    class Edge:
        def __init__(self, start_node, end_node):
            self.start_node = start_node
            self.end_node = end_node

    def __init__(self):
        self.edge_list = []
        self.node_list = []

    def add_edge(self, start_node, end_node):
        start = None
        end = None

        # Iterate through node_list to find start and end nodes
        for node in self.node_list:
            if start_node == node.name:
                start = node
            elif end_node == node.name:
                end = node

        # If start node is not found, create a new Node and add it to node_list
        if start is None:
            start = self.Node(start_node)
            self.node_list.append(start)

        # If end node is not found, create a new Node and add it to node_list
        if end is None:
            end = self.Node(end_node)
            self.node_list.append(end)

        # Add the edge to edge_list
        self.edge_list.append(self.Edge(start, end))

    def count_graphs(self):
        count = 0
        marked_nodes = set()

        # Iterate through node_list and mark each unvisited node and its connected components
        for n in self.node_list:
            if n not in marked_nodes:
                # Recursively mark all nodes reachable from n
                marked_nodes.update(self.depth_first_search(n, set()))
                count += 1
        return count

    def depth_first_search(self, n, visited):
        visited.add(n)

        # Iterate through edge_list to mark all reachable nodes
        for e in self.edge_list:
            if e.start_node == n and e.end_node not in visited:
                # Recursively call depth_first_search for the reachable node
                self.depth_first_search(e.end_node, visited)

        # Return the set of visited nodes
        return visited


# Main function to read input and print output
if __name__ == "__main__":
    import sys

    input = sys.stdin.read
    data = input().splitlines()
    
    # Read the number of character edges
    char_edges = int(data[0])

    # Initialize a Graph object for characters
    graph_chars = Graph()

    # Read character edges and add them to the graph
    for i in range(1, char_edges + 1):
        start, end = data[i].split()
        graph_chars.add_edge(start, end)

    # Read the number of integer edges
    int_edges = int(data[char_edges + 1])

    # Initialize a Graph object for integers
    graph_ints = Graph()

    # Read integer edges and add them to the graph
    for i in range(char_edges + 2, char_edges + 2 + int_edges):
        start, end = map(int, data[i].split())
        graph_ints.add_edge(start, end)

    # Print the number of different connected components in the character and integer graphs
    print("Amount of different char-graphs:", graph_chars.count_graphs())
    print("Amount of different int-graphs:", graph_ints.count_graphs())

# <END-OF-CODE>
