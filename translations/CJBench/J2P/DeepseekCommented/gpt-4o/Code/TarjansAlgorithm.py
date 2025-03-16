import sys
from collections import defaultdict

class Graph:
    def __init__(self, vertices):
        self.V = vertices
        self.graph = defaultdict(list)
    
    def add_edge(self, u, v):
        self.graph[u].append(v)
    
    def SCCUtil(self, u, low, disc, stack_member, st):
        disc[u] = self.time
        low[u] = self.time
        self.time += 1
        stack_member[u] = True
        st.append(u)
        
        for v in self.graph[u]:
            if disc[v] == -1:
                self.SCCUtil(v, low, disc, stack_member, st)
                low[u] = min(low[u], low[v])
            elif stack_member[v]:
                low[u] = min(low[u], disc[v])
        
        w = -1
        if low[u] == disc[u]:
            while w != u:
                w = st.pop()
                print(w, end=' ')
                stack_member[w] = False
            print()
    
    def SCC(self):
        disc = [-1] * self.V
        low = [-1] * self.V
        stack_member = [False] * self.V
        st = []
        
        for i in range(self.V):
            if disc[i] == -1:
                self.SCCUtil(i, low, disc, stack_member, st)

# Read input
vertices, edges = map(int, input().split())
g = Graph(vertices)
for _ in range(edges):
    u, v = map(int, input().split())
    g.add_edge(u, v)

# Find and print SCCs
g.SCC()
