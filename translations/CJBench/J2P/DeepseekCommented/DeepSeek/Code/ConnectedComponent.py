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
        for node in self.node_list:
            if node not in marked_nodes:
                marked_nodes.update(self.depth_first_search(node, []))
                count += 1
        return count

    def depth_first_search(self, n, visited):
        visited.append(n)
        for edge in self.edge_list:
            if edge.start_node.name == n.name and edge.end_node not in visited:
                self.depth_first_search(edge.end_node, visited)
        return visited


# Main class containing the main method
class Main:
    @staticmethod
    def main():
        import sys
        input = sys.stdin.read
        data = input().split()
        char_edges = int(data[0])
        graph_chars = Graph()
        index = 1
        for _ in range(char_edges):
            start = data[index]
            end = data[index + 1]
            graph_chars.add_edge(start, end)
            index += 2
        int_edges = int(data[index])
        graph_ints = Graph()
        index += 1
        for _ in range(int_edges):
            start = int(data[index])
            end = int(data[index + 1])
            graph_ints.add_edge(start, end)
            index += 2
        print("Amount of different char-graphs:", graph_chars.count_graphs())
        print("Amount of different int-graphs:", graph_ints.count_graphs())


Main.main()
