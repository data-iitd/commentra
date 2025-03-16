from collections import defaultdict

class Graph:
    def __init__(self, vertices):
        self.v = vertices  # Number of vertices in the graph
        self.adj_list = defaultdict(list)  # Adjacency list representation of the graph
        self.paths = []  # List to store all paths from source to destination

    def add_edge(self, u, v):
        self.adj_list[u].append(v)  # Add vertex v to the adjacency list of vertex u

    def store_all_paths(self, s, d):
        is_visited = [False] * self.v  # Track visited vertices
        path_list = []  # List to store the current path
        path_list.append(s)  # Add the source to the path
        self.store_all_paths_util(s, d, is_visited, path_list)  # Call the utility method to find paths

    def store_all_paths_util(self, u, d, is_visited, local_path_list):
        # If the current vertex is the destination, add the current path to the list of paths
        if u == d:
            self.paths.append(list(local_path_list))  # Store a copy of the current path
            return
        
        is_visited[u] = True  # Mark the current vertex as visited

        # Explore all adjacent vertices of the current vertex
        for i in self.adj_list[u]:
            # If the adjacent vertex has not been visited, continue the path
            if not is_visited[i]:
                local_path_list.append(i)  # Add the adjacent vertex to the current path
                self.store_all_paths_util(i, d, is_visited, local_path_list)  # Recur for the adjacent vertex
                local_path_list.remove(i)  # Backtrack: remove the vertex from the current path

        is_visited[u] = False  # Unmark the current vertex for other paths

    def get_paths(self):
        return self.paths  # Return the list of all paths found

# Main execution
if __name__ == "__main__":
    vertices = int(input())  # Read the number of vertices
    edges = int(input())  # Read the number of edges
    edge_list = []  # List to store edges

    # Read the edges from input
    for _ in range(edges):
        u, v = map(int, input().split())  # Start and end vertex of the edge
        edge_list.append((u, v))

    source = int(input())  # Read the source vertex
    destination = int(input())  # Read the destination vertex

    # Create a graph instance
    graph = Graph(vertices)

    # Add edges to the graph
    for u, v in edge_list:
        graph.add_edge(u, v)

    # Find all paths from source to destination
    graph.store_all_paths(source, destination)

    # Print all paths found
    print("All paths from source to destination: ")
    for path in graph.get_paths():
        print(path)  # Print each path

# <END-OF-CODE>
