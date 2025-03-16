class TarjansAlgorithm:
    def __init__(self):
        self.time = 0
        self.scc_list = []

    def strongly_connected_components(self, v, graph):
        low_time = [-1] * v
        insertion_time = [-1] * v
        is_in_stack = [False] * v
        stack = []

        for i in range(v):
            if insertion_time[i] == -1:
                self.dfs(i, low_time, insertion_time, is_in_stack, stack, graph)

        return self.scc_list

    def dfs(self, u, low_time, insertion_time, is_in_stack, stack, graph):
        insertion_time[u] = self.time
        low_time[u] = self.time
        self.time += 1

        stack.append(u)
        is_in_stack[u] = True

        for v in graph[u]:
            if insertion_time[v] == -1:
                self.dfs(v, low_time, insertion_time, is_in_stack, stack, graph)
                low_time[u] = min(low_time[u], low_time[v])
            elif is_in_stack[v]:
                low_time[u] = min(low_time[u], insertion_time[v])

        if low_time[u] == insertion_time[u]:
            scc = []
            while stack:
                w = stack.pop()
                scc.append(w)
                if w == u:
                    break
            self.scc_list.append(scc)


def read_input():
    vertices, edges = map(int, input().split())
    graph = [[] for _ in range(vertices)]
    for _ in range(edges):
        from_vertex, to_vertex = map(int, input().split())
        graph[from_vertex].append(to_vertex)
    return vertices, graph


if __name__ == "__main__":
    vertices, graph = read_input()
    tarjans = TarjansAlgorithm()
    sccs = tarjans.strongly_connected_components(vertices, graph)

    for scc in sccs:
        print(scc)
