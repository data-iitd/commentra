from typing import List, Tuple

class Graph:
    def __init__(self, vertices: int):
        self.v = vertices
        self.paths = []
        self.adjList = [[] for _ in range(vertices)]

    def add_edge(self, u: int, v: int):
        self.adjList[u].append(v)

    def store_all_paths(self, s: int, d: int):
        is_visited = [False] * self.v
        path_list = []
        path_list.append(s)
        self.store_all_paths_util(s, d, is_visited, path_list)

    def store_all_paths_util(self, u: int, d: int, is_visited: List[bool], local_path_list: List[int]):
        if u == d:
            self.paths.append(local_path_list.copy())
            return
        is_visited[u] = True
        for i in self.adjList[u]:
            if not is_visited[i]:
                local_path_list.append(i)
                self.store_all_paths_util(i, d, is_visited, local_path_list)
                local_path_list.pop()
        is_visited[u] = False

    def get_paths(self) -> List[List[int]]:
        return self.paths

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    index = 0
    vertices = int(data[index])
    index += 1
    edges = int(data[index])
    index += 1
    
    edge_list = []
    for i in range(edges):
        u = int(data[index])
        v = int(data[index + 1])
        edge_list.append((u, v))
        index += 2
    
    source = int(data[index])
    index += 1
    destination = int(data[index])
    index += 1
    
    graph = Graph(vertices)
    for u, v in edge_list:
        graph.add_edge(u, v)
    
    graph.store_all_paths(source, destination)
    
    print("All paths from source to destination:")
    for path in graph.get_paths():
        print(path)

if __name__ == "__main__":
    main()
