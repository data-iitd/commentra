
import heapq

class Graph:
    def __init__(self, size):
        self.graph = [[] for _ in range(size)]

    def get_neighbours(self, from_node):
        return self.graph[from_node]

    def add_edge(self, from_node, to_node, weight):
        self.graph[from_node].append((to_node, weight))
        self.graph[to_node].append((from_node, weight))  # Add edge in both directions for undirected graph

class PathAndDistance:
    def __init__(self, distance, path):
        self.distance = distance
        self.path = path

def a_star(from_node, to_node, graph, heuristic):
    # Priority queue to store paths with their distances, sorted by estimated total cost
    queue = []
    heapq.heappush(queue, (0, [from_node]))

    # Loop until there are no more paths to explore
    while queue:
        # Get the current shortest path
        current_distance, current_path = heapq.heappop(queue)
        current_position = current_path[-1]

        # Check if the destination has been reached
        if current_position == to_node:
            return PathAndDistance(current_distance, current_path)

        # Explore the neighbors of the current node
        for neighbor, weight in graph.get_neighbours(current_position):
            # Avoid cycles by checking if the neighbor is already in the path
            if neighbor not in current_path:
                # Create a new path including the neighbor
                updated_path = current_path + [neighbor]
                # Add the new path to the queue with updated distance
                heapq.heappush(queue, (current_distance + weight, updated_path))

    # Return an indication that no path was found
    return PathAndDistance(-1, None)

if __name__ == "__main__":
    import sys

    # Read the number of nodes and edges from input
    nodes, edges = map(int, input().split())

    # Initialize the graph with the specified number of nodes
    graph = Graph(nodes)

    # Read edges and add them to the graph
    for _ in range(edges):
        from_node, to_node, weight = map(int, input().split())
        graph.add_edge(from_node, to_node, weight)

    # Read heuristic values for each node
    heuristic = list(map(int, input().split()))

    # Read the start and end nodes for the path search
    start, end = map(int, input().split())

    # Execute the A* algorithm to find the shortest path
    result = a_star(start, end, graph, heuristic)

    # Output the result
    if result.path is not None:
        print("Shortest path:", result.path)
        print("Total distance:", result.distance)
    else:
        print("No path found")

