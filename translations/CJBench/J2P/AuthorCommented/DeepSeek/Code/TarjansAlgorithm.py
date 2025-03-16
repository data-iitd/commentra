class TarjansAlgorithm:
    def __init__(self, vertices):
        self.vertices = vertices
        self.graph = [[] for _ in range(vertices)]
        self.time = 0
        self.scc_list = []

    def add_edge(self, u, v):
        self.graph[u].append(v)

    def strongly_connected_components(self):
        low_time = [-1] * self.vertices
        insertion_time = [-1] * self.vertices
        is_in_stack = [False] * self.vertices
        stack = []

        for i in range(self.vertices):
            if insertion_time[i] == -1:
                self.dfs(i, low_time, insertion_time, is_in_stack, stack)

        return self.scc_list

    def dfs(self, u, low_time, insertion_time, is_in_stack, stack):
        insertion_time[u] = self.time
        low_time[u] = self.time
        self.time += 1

        stack.append(u)
        is_in_stack[u] = True

        for v in self.graph[u]:
            if insertion_time[v] == -1:
                self.dfs(v, low_time, insertion_time, is_in_stack, stack)
                low_time[u] = min(low_time[u], low_time[v])
            elif is_in_stack[v]:
                low_time[u] = min(low_time[u], insertion_time[v])

        if low_time[u] == insertion_time[u]:
            scc = []
            while stack and stack[-1] != u:
                w = stack.pop()
                scc.append(w)
                is_in_stack[w] = False
            w = stack.pop()
            scc.append(w)
            is_in_stack[w] = False
            self.scc_list.append(scc)


def main():
    import sys
    input = sys.stdin.read
    data = input().split()

    index = 0
    vertices = int(data[index])
    edges = int(data[index + 1])
    index += 2

    tarjans = TarjansAlgorithm(vertices)

    for i in range(edges):
        u = int(data[index])
        v = int(data[index + 1])
        tarjans.add_edge(u, v)
        index += 2

    sccs = tarjans.strongly_connected_components()

    for scc in sccs:
        print(scc)


if __name__ == "__main__":
    main()
