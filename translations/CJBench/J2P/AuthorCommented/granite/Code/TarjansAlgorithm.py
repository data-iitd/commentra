

import sys
from typing import List

class Main:
    def __init__(self):
        self.time = 0
        self.sccList = []

    def strongly_connected_components(self, v: int, graph: List[List[int]]) -> List[List[int]]:
        low_time = [0] * v
        insertion_time = [0] * v
        is_in_stack = [False] * v
        stack = []

        for i in range(v):
            if insertion_time[i] == 0:
                self.dfs(i, low_time, insertion_time, is_in_stack, stack, graph)

        return self.sccList

    def dfs(self, u: int, low_time: List[int], insertion_time: List[int], is_in_stack: List[bool], stack: List[int], graph: List[List[int]]):
        insertion_time[u] = self.time
        low_time[u] = self.time
        self.time += 1

        stack.append(u)
        is_in_stack[u] = True

        for v in graph[u]:
            if insertion_time[v] == 0:
                self.dfs(v, low_time, insertion_time, is_in_stack, stack, graph)
                low_time[u] = min(low_time[u], low_time[v])
            elif is_in_stack[v]:
                low_time[u] = min(low_time[u], insertion_time[v])

        if low_time[u] == insertion_time[u]:
            scc = []
            w = -1
            while w!= u:
                w = stack.pop()
                scc.append(w)
                is_in_stack[w] = False
            self.sccList.append(scc)

if __name__ == "__main__":
    # Read number of vertices and edges
    vertices, edges = map(int, input().split())

    # Build adjacency list
    graph = [[] for _ in range(vertices)]
    for _ in range(edges):
        from_vertex, to_vertex = map(int, input().split())
        graph[from_vertex].append(to_vertex)

    # Run Tarjan's Algorithm
    tarjans = Main()
    sccs = tarjans.strongly_connected_components(vertices, graph)

    # Print the results
    for scc in sccs:
        print(scc)

