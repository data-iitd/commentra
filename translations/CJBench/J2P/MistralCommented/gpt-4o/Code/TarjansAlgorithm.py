from collections import defaultdict

class Main:
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
            while True:
                w = stack.pop()
                is_in_stack[w] = False
                scc.append(w)
                if w == u:
                    break
            self.scc_list.append(scc)

if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().splitlines()
    
    vertices, edges = map(int, data[0].split())
    graph = defaultdict(list)

    for i in range(1, edges + 1):
        from_vertex, to_vertex = map(int, data[i].split())
        graph[from_vertex].append(to_vertex)

    tarjans = Main()
    sccs = tarjans.strongly_connected_components(vertices, graph)

    for scc in sccs:
        print(scc)

# <END-OF-CODE>
