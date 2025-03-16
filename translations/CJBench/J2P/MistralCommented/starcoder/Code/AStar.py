
import heapq

# Create a Graph class to represent the graph data structure
class Graph:
    def __init__(self, size):
        self.graph = [[] for _ in range(size)]

    # Get the neighbours of a node
    def get_neighbours(self, from_):
        return self.graph[from_]

    # Add an edge between two nodes with given weight
    def add_edge(self, from_, to_, weight):
        self.graph[from_].append((to_, weight))
        self.graph[to_].append((from_, weight))

# A* algorithm to find the shortest path between two nodes
def a_star(from_, to_, graph, heuristic):
    queue = []
    heapq.heappush(queue, (0, [from_]))

    # While the queue is not empty
    while queue:
        distance, path = heapq.heappop(queue)

        # Check if the current node is the destination node
        current_position = path[-1]
        if current_position == to_:
            return PathAndDistance(distance, path)

        # Iterate through the neighbours of the current node
        for neighbour, weight in graph.get_neighbours(current_position):
            # If the neighbour is not in the current path
            if neighbour not in path:
                # Create a new PathAndDistance with updated path and distance
                updated_path = path + [neighbour]
                heapq.heappush(queue, (distance + weight + heuristic[neighbour], updated_path))

    # If no path is found, return an empty PathAndDistance object
    return PathAndDistance(-1, None)

# Main method to read input and call the A* algorithm
def main():
    # Read the number of nodes and edges from the input
    nodes, edges = map(int, input().split())

    # Initialize the Graph with given number of nodes
    graph = Graph(nodes)

    # Read the edges and add them to the Graph
    for _ in range(edges):
        from_, to_, weight = map(int, input().split())
        graph.add_edge(from_, to_, weight)

    # Read the heuristic values for each node
    heuristic = list(map(int, input().split()))

    # Read the start and end nodes from the input
    start, end = map(int, input().split())

    # Call the A* algorithm to find the shortest path and print the result
    result = a_star(start, end, graph, heuristic)
    if result.path is not None:
        print("Shortest path:", result.path)
        print("Total distance:", result.distance)
    else:
        print("No path found")

# Create a PathAndDistance class to store the shortest path and its total distance
class PathAndDistance:
    def __init__(self, distance, path):
        self.distance = distance
        self.path = path

    # Get the total distance of the path
    def get_distance(self):
        return self.distance

    # Get the shortest path
    def get_path(self):
        return self.path

# Run the main method
if __name__ == "__main__":
    main()

