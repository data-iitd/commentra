from collections import defaultdict

class Graph:
    def __init__(self):
        self.edges = defaultdict(list)
        self.nodes = set()

    def add_edge(self, start_node, end_node):
        self.edges[start_node].append(end_node)
        self.edges[end_node].append(start_node)
        self.nodes.add(start_node)
        self.nodes.add(end_node)

    def depth_first_search(self, node, visited):
        visited.add(node)
        for neighbor in self.edges[node]:
            if neighbor not in visited:
                self.depth_first_search(neighbor, visited)
        return visited

    def count_graphs(self):
        count = 0
        visited_nodes = set()

        for node in self.nodes:
            if node not in visited_nodes:
                visited_nodes.update(self.depth_first_search(node, set()))
                count += 1
        return count

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
        start = data[index]
        end = data[index + 1]
        graph_ints.add_edge(start, end)
        index += 2

    print("Amount of different char-graphs:", graph_chars.count_graphs())
    print("Amount of different int-graphs:", graph_ints.count_graphs())

if __name__ == "__main__":
    main()
