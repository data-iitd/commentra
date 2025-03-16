class Graph:
    def __init__(self, vertices):
        self.v = vertices
        self.adj_list = [[] for _ in range(vertices)]
        self.paths = []

    def add_edge(self, u, v):
        self.adj_list[u].append(v)

    def store_all_paths(self, s, d):
        is_visited = [False] * self.v
        path_list = [s]
        self.store_all_paths_util(s, d, is_visited, path_list)

    def store_all_paths_util(self, u, d, is_visited, local_path_list):
        if u == d:
            self.paths.append(list(local_path_list))
            return
        is_visited[u] = True
        for i in self.adj_list[u]:
            if not is_visited[i]:
                local_path_list.append(i)
                self.store_all_paths_util(i, d, is_visited, local_path_list)
                local_path_list.pop()
        is_visited[u] = False

    def get_paths(self):
        return self.paths


if __name__ == "__main__":
    vertices = int(input())
    edges = int(input())
    edge_list = [list(map(int, input().split())) for _ in range(edges)]
    source = int(input())
    destination = int(input())
    
    graph = Graph(vertices)
    for edge in edge_list:
        graph.add_edge(edge[0], edge[1])
    
    graph.store_all_paths(source, destination)
    print("All paths from source to destination: ")
    for path in graph.get_paths():
        print(path)

# <END-OF-CODE>
