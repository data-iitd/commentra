import heapq

# Represents a graph using an adjacency list
class Graph:
    def __init__(self, size):
        self.graph = [[] for _ in range(size)]

    def get_neighbours(self, from_):
        return self.graph[from_]

    def add_edge(self, from_, to_, weight):
        self.graph[from_].append((to_, weight))
        self.graph[to_].append((from_, weight))

# Represents an edge in the graph
class Edge:
    def __init__(self, from_, to_, weight):
        self.from_ = from_
        self.to = to_
        self.weight = weight

# Holds the path and the total distance of a path
class PathAndDistance:
    def __init__(self, distance, path):
        self.distance = distance
        self.path = path

    def get_distance(self):
        return self.distance

    def get_path(self):
        return self.path

# Implements the A* search algorithm to find the shortest path
def a_star(from_, to, graph, heuristic):
    # Priority queue to explore the shortest paths
    queue = []
    heapq.heappush(queue, PathAndDistance(0, [from_]))
    while queue:
        current = heapq.heappop(queue)
        current_position = current.get_path()[-1]
        if current_position == to:
            return current
        for edge in graph.get_neighbours(current_position):
            if edge.to not in current.get_path():
                updated_path = current.get_path() + [edge.to]
                heapq.heappush(queue, PathAndDistance(current.get_distance() + edge.weight, updated_path))
    return PathAndDistance(-1, None)

# Reads input for the graph, heuristics, and start/end nodes, then finds the shortest path and prints the result
def main():
    scanner = Scanner(System.in)
    nodes = scanner.nextInt()
    edges = scanner.nextInt()
    graph = Graph(nodes)
    for i in range(edges):
        from_ = scanner.nextInt()
        to = scanner.nextInt()
        weight = scanner.nextInt()
        graph.add_edge(from_, to, weight)
    heuristic = [0] * nodes
    for i in range(nodes):
        heuristic[i] = scanner.nextInt()
    start = scanner.nextInt()
    end = scanner.nextInt()
    result = a_star(start, end, graph, heuristic)
    if result.get_path() is not None:
        print("Shortest path: " + result.get_path())
        print("Total distance: " + result.get_distance())
    else:
        print("No path found")

if __name__ == "__main__":
    main()

