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
        for node in self.node_list:
            if start_node == node.name:
                start = node
            elif end_node == node.name:
                end = node
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
        for n in self.node_list:
            if n not in marked_nodes:
                marked_nodes.update(self.depth_first_search(n, set()))
                count += 1
        return count

    def depth_first_search(self, n, visited):
        visited.add(n)
        for e in self.edge_list:
            if e.start_node == n and e.end_node not in visited:
                self.depth_first_search(e.end_node, visited)
        return visited


def main():
    char_edges = int(input())
    graph_chars = Graph()
    for _ in range(char_edges):
        start, end = input().split()
        graph_chars.add_edge(start, end)

    int_edges = int(input())
    graph_ints = Graph()
    for _ in range(int_edges):
        start, end = map(int, input().split())
        graph_ints.add_edge(start, end)

    print("Amount of different char-graphs:", graph_chars.count_graphs())
    print("Amount of different int-graphs:", graph_ints.count_graphs())


if __name__ == "__main__":
    main()

# <END-OF-CODE>
