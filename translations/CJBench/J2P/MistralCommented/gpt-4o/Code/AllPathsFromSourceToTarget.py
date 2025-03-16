from collections import defaultdict

class Graph:
    def __init__(self, vertices):
        self.v = vertices  # number of vertices
        self.adj_list = defaultdict(list)  # adjacency list to represent graph
        self.paths = []  # list to store all paths from source to destination

    def add_edge(self, u, v):
        self.adj_list[u].append(v)  # add edge between two vertices

    def store_all_paths(self, s, d):
        is_visited = [False] * self.v  # boolean array to mark visited vertices
        path_list = []  # list to store current path
        path_list.append(s)  # add source vertex to the path list
        self.store_all_paths_util(s, d, is_visited, path_list)  # recursive call to find all paths

    def store_all_paths_util(self, u, d, is_visited, local_path_list):
        if u == d:  # base case: destination reached
            self.paths.append(list(local_path_list))  # add path to the list of paths
            return

        is_visited[u] = True  # mark current vertex as visited
        for i in self.adj_list[u]:  # iterate through neighbors of current vertex
            if not is_visited[i]:  # if neighbor not visited yet
                local_path_list.append(i)  # add neighbor to the current path list
                self.store_all_paths_util(i, d, is_visited, local_path_list)  # recursive call to find all paths from neighbor to destination
                local_path_list.pop()  # backtrack to previous vertex
        is_visited[u] = False  # mark current vertex as not visited

    def get_paths(self):
        return self.paths  # get all paths from source to destination


if __name__ == "__main__":
    vertices = int(input("Enter number of vertices: "))  # read number of vertices
    edges = int(input("Enter number of edges: "))  # read number of edges

    graph = Graph(vertices)  # create new instance of Graph class

    # read edges and add them to the graph
    for _ in range(edges):
        u, v = map(int, input("Enter edge (u v): ").split())
        graph.add_edge(u, v)  # add edge to the graph

    # read source and destination vertices
    source = int(input("Enter source vertex: "))
    destination = int(input("Enter destination vertex: "))

    # find all paths from source to destination
    graph.store_all_paths(source, destination)

    # print all paths from source to destination
    print("All paths from source to destination: ")
    for path in graph.get_paths():
        print(path)

# <END-OF-CODE>
