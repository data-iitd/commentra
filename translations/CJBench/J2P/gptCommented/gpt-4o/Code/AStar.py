import heapq

class Graph:
    def __init__(self, size):
        self.graph = [[] for _ in range(size)]

    def get_neighbours(self, from_node):
        return self.graph[from_node]

    def add_edge(self, from_node, to_node, weight):
        self.graph[from_node].append(Edge(from_node, to_node, weight))
        self.graph[to_node].append(Edge(to_node, from_node, weight))  # Undirected graph

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
    heapq.heappush(queue, (0, PathAndDistance(0, [from_node])))

    while queue:
        current_distance, current = heapq.heappop(queue)
        current_position = current.get_path()[-1]

        if current_position == to_node:
            return current

        for edge in graph.get_neighbours(current_position):
            if edge.to_node not in current.get_path():
                updated_path = current.get_path() + [edge.to_node]
                new_distance = current.get_distance() + edge.weight
                estimated_total_cost = new_distance + heuristic[edge.to_node]
                heapq.heappush(queue, (estimated_total_cost, PathAndDistance(new_distance, updated_path)))

    return PathAndDistance(-1, None)

def main():
    nodes = int(input())
    edges = int(input())
    
    graph = Graph(nodes)

    for _ in range(edges):
        from_node, to_node, weight = map(int, input().split())
        graph.add_edge(from_node, to_node, weight)

    heuristic = list(map(int, input().split()))
    start, end = map(int, input().split())

    result = a_star(start, end, graph, heuristic)

    if result.get_path() is not None:
        print("Shortest path:", result.get_path())
        print("Total distance:", result.get_distance())
    else:
        print("No path found")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
