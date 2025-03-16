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
        start = next((node for node in self.node_list if node.name == start_node), None)
        end = next((node for node in self.node_list if node.name == end_node), None)

        if start is None:
            start = self.Node(start_node)
            self.node_list.append(start)

        if end is None:
            end = self.Node(end_node)
            self.node_list.append(end)

        self.edge_list.append(self.Edge(start, end))

    def count_graphs(self):
        count = 0
        marked_nodes = set()

        def depth_first_search(n, visited):
            visited.add(n)
            for edge in self.edge_list:
                if edge.start_node.name == n.name and edge.end_node not in visited:
                    depth_first_search(edge.end_node, visited)
            return visited

        for node in self.node_list:
            if node not in marked_nodes:
                marked_nodes.update(depth_first_search(node, set()))
                count += 1
        return count


# Main class to execute the program
if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().split()

    char_edges = int(data[0])
    graph_chars = Graph()

    for i in range(1, char_edges + 1):
        start = data[i]
        end = data[i + char_edges]
        graph_chars.add_edge(start, end)
        i += 1

    int_edges = int(data[char_edges + 1])
    graph_ints = Graph()

    for i in range(char_edges + 2, char_edges + int_edges + 2):
        start = int(data[i])
        end = int(data[i + int_edges])
        graph_ints.add_edge(start, end)
        i += 1

    print("Amount of different char-graphs:", graph_chars.count_graphs())
    print("Amount of different int-graphs:", graph_ints.count_graphs())
