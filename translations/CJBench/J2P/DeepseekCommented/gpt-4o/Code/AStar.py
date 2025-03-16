class Edge:
    def __init__(self, from_node, to_node, weight):
        self.from_node = from_node
        self.to_node = to_node
        self.weight = weight

class PathAndDistance:
    def __init__(self, distance, path):
        self.distance = distance
        self.path = path

    def get_distance(self):
        return self.distance

    def get_path(self):
        return self.path

class Graph:
    def __init__(self, size):
        self.graph = [[] for _ in range(size)]

    def get_neighbours(self, from_node):
        return self.graph[from_node]

    def add_edge(self, from_node, to_node, weight):
        self.graph[from_node].append(Edge(from_node, to_node, weight))
        self.graph[to_node].append(Edge(to_node, from_node, weight))

def a_star(from_node, to_node, graph, heuristic):
    import heapq
    queue = []
    heapq.heappush(queue, (0 + heuristic[from_node], PathAndDistance(0, [from_node])))
    while queue:
        current_distance, current = heapq.heappop(queue)
        current_position = current.path[-1]
        if current_position == to_node:
            return current
        for edge in graph.get_neighbours(current_position):
            if edge.to_node not in current.path:
                updated_path = PathAndDistance(current.distance + edge.weight, current.path + [edge.to_node])
                heapq.heappush(queue, (updated_path.distance + heuristic[updated_path.path[-1]], updated_path))
    return PathAndDistance(-1, None)

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    index = 0
    nodes = int(data[index])
    index += 1
    edges = int(data[index])
    index += 1
    graph = Graph(nodes)
    for i in range(edges):
        from_node = int(data[index])
        index += 1
        to_node = int(data[index])
        index += 1
        weight = int(data[index])
        index += 1
        graph.add_edge(from_node, to_node, weight)
    heuristic = [int(data[index]) for index in range(index, index + nodes)]
    index += nodes
    start = int(data[index])
    index += 1
    end = int(data[index])
    index += 1
    result = a_star(start, end, graph, heuristic)
    if result.path is not None:
        print("Shortest path: " + str(result.path))
        print("Total distance: " + str(result.distance))
    else:
        print("No path found")

if __name__ == "__main__":
    main()
