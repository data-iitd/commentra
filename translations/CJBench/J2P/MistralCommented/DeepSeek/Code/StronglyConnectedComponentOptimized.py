from collections import defaultdict, deque

class Graph:
    def __init__(self, vertices):
        self.V = vertices
        self.graph = defaultdict(list)
        self.rev_graph = defaultdict(list)

    def add_edge(self, u, v):
        self.graph[u].append(v)
        self.rev_graph[v].append(u)

    def dfs1(self, v, visited, stack):
        visited[v] = True
        for i in self.graph[v]:
            if not visited[i]:
                self.dfs1(i, visited, stack)
        stack.append(v)

    def dfs2(self, v, visited, component):
        visited[v] = True
        component.append(v)
        for i in self.rev_graph[v]:
            if not visited[i]:
                self.dfs2(i, visited, component)

    def get_scc_count(self):
        stack = []
        visited = [False] * self.V
        for i in range(self.V):
            if not visited[i]:
                self.dfs1(i, visited, stack)

        visited = [False] * self.V
        scc_count = 0
        while stack:
            v = stack.pop()
            if not visited[v]:
                component = []
                self.dfs2(v, visited, component)
                scc_count += 1
                print(f"Strongly Connected Component: {component}")
        return scc_count

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    index = 0
    n = int(data[index])
    e = int(data[index + 1])
    index += 2
    
    g = Graph(n)
    for i in range(e):
        src = int(data[index])
        dest = int(data[index + 1])
        g.add_edge(src, dest)
        index += 2
    
    scc_count = g.get_scc_count()
    print(f"Number of strongly connected components: {scc_count}")

if __name__ == "__main__":
    main()
