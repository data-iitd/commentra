
import heapq

# Graph class to represent the graph structure
class Graph:
    def __init__(self, size):
        self.graph = [[] for _ in range(size)]

    # Method to get the neighbors of a given node
    def get_neighbours(self, from):
        return self.graph[from]

    # Method to add an edge between two nodes with a specified weight
    def add_edge(self, from, to, weight):
        self.graph[from].append((from, to, weight))
        self.graph[to].append((to, from, weight)) # Add edge in both directions for undirected graph

# Edge class to represent an edge in the graph
class Edge:
    def __init__(self, from, to, weight):
        self.from = from
        self.to = to
        self.weight = weight

# Class to store the path and its total distance
class PathAndDistance:
    def __init__(self, distance, path):
        self.distance = distance
        self.path = path

# A* algorithm implementation to find the shortest path
def a_star(from, to, graph, heuristic):
    # Priority queue to store paths with their distances, sorted by estimated total cost
    queue = []
    heapq.heappush(queue, (0, [from]))

    # Loop until there are no more paths to explore
    while queue:
        # Get the current shortest path
        current_distance, current_path = heapq.heappop(queue)
        current_position = current_path[-1]

        # Check if the destination has been reached
        if current_position == to:
            return PathAndDistance(current_distance, current_path) # Return the found path

        # Explore the neighbors of the current node
        for edge in graph.get_neighbours(current_position):
            # Avoid cycles by checking if the neighbor is already in the path
            if edge[1] not in current_path:
                # Create a new path including the neighbor
                updated_path = current_path + [edge[1]]
                # Add the new path to the queue with updated distance
                heapq.heappush(queue, (current_distance + edge[2], updated_path))

    # Return an indication that no path was found
    return PathAndDistance(-1, None)

# Main method to execute the program
def main():
    # Read the number of nodes and edges from input
    nodes = int(input())
    edges = int(input())

    # Initialize the graph with the specified number of nodes
    graph = Graph(nodes)

    # Read edges and add them to the graph
    for i in range(edges):
        from, to, weight = map(int, input().split())
        graph.add_edge(from, to, weight)

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

if __name__ == "__main__":
    main()
