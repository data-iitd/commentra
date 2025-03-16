import heapq

class Graph:
    def __init__(self, size):
        self.graph = {i: [] for i in range(size)}

    def add_edge(self, from_node, to_node, weight):
        self.graph[from_node].append((to_node, weight))
        self.graph[to_node].append((from_node, weight))

    def get_neighbors(self, node):
        return self.graph[node]

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

def a_star(from_node, to_node, graph, heuristic):
    queue = []
    heapq.heappush(queue, (0, [from_node]))

    while queue:
        current_path = heapq.heappop(queue)
        current_distance = current_path[0]
        current_path = current_path[1]
        current_node = current_path[-1]

        if current_node == to_node:
            return PathAndDistance(current_distance, current_path)

        for neighbor, weight in graph.get_neighbors(current_node):
            if neighbor not in current_path:
                new_path = current_path + [neighbor]
                new_distance = current_distance + weight
                heapq.heappush(queue, (new_distance + heuristic[neighbor], new_path))

    return PathAndDistance(-1, None)

def main():
    import sys
    input = sys.stdin.read
    data = input().split()

    index = 0
    nodes = int(data[index])
    edges = int(data[index + 1])
    index += 2

    graph = Graph(nodes)

    for _ in range(edges):
        from_node = int(data[index])
        to_node = int(data[index + 1])
        weight = int(data[index + 2])
        graph.add_edge(from_node, to_node, weight)
        index += 3

    heuristic = [int(data[index + i]) for i in range(nodes)]
    index += nodes

    start = int(data[index])
    end = int(data[index + 1])
    index += 2

    result = a_star(start, end, graph, heuristic)

    if result.get_path() is not None:
        print(f"Shortest path: {result.get_path()}")
        print(f"Total distance: {result.get_distance()}")
    else:
        print("No path found")

if __name__ == "__main__":
    main()
