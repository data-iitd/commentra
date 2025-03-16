class Main:
    def __init__(self, vertices):
        self.v = vertices
        self.init_adj_list()

    def init_adj_list(self):
        self.adj_list = [[] for _ in range(self.v)]

    def add_edge(self, u, v):
        self.adj_list[u].append(v)

    def store_all_paths(self, s, d):
        is_visited = [False] * self.v
        path_list = [s]
        self.store_all_paths_util(s, d, is_visited, path_list)

    def store_all_paths_util(self, u, d, is_visited, local_path_list):
        if u == d:
            self.paths.append(local_path_list.copy())
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

    @staticmethod
    def main(args):
        import sys
        input = sys.stdin.read
        data = input().split()

        vertices = int(data[0])
        edges = int(data[1])

        edge_list = []
        idx = 2
        for i in range(edges):
            u = int(data[idx])
            v = int(data[idx + 1])
            idx += 2
            graph = Main(vertices)
            graph.add_edge(u, v)
            edge_list.append((u, v))

        source = int(data[idx])
        destination = int(data[idx + 1])
        idx += 2

        graph = Main(vertices)
        for u, v in edge_list:
            graph.add_edge(u, v)
        graph.store_all_paths(source, destination)

        print("All paths from source to destination:")
        for path in graph.get_paths():
            print(path)

