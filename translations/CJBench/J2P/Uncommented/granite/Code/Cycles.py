

import sys
sys.setrecursionlimit(10000)

class Cycle:
    def __init__(self, nodes, edges, edgesInput):
        self.nodes = nodes
        self.adjacencyMatrix = [[0 for _ in range(nodes)] for _ in range(nodes)]
        self.visited = [False for _ in range(nodes)]
        for edge in edgesInput:
            start = edge[0]
            end = edge[1]
            self.adjacencyMatrix[start][end] = 1

    def start(self):
        self.cycles = []
        for i in range(self.nodes):
            temp = []
            self.dfs(i, i, temp)
            for j in range(self.nodes):
                self.adjacencyMatrix[i][j] = 0
                self.adjacencyMatrix[j][i] = 0

    def dfs(self, start, curr, temp):
        temp.append(curr)
        self.visited[curr] = True
        for i in range(self.nodes):
            if self.adjacencyMatrix[curr][i] == 1:
                if i == start:
                    self.cycles.append(temp[:])
                else:
                    if not self.visited[i]:
                        self.dfs(start, i, temp)
        if len(temp) > 0:
            temp.pop()
        self.visited[curr] = False

    def printAll(self):
        if len(self.cycles) == 0:
            print("No cycles found.")
            return
        for cycle in self.cycles:
            for i in range(len(cycle)):
                print(cycle[i], end=" -> ")
            print(cycle[0])
            print()

if __name__ == "__main__":
    scanner = iter(map(int, input().split()))
    nodes = next(scanner)
    edges = next(scanner)
    edgesInput = []
    for _ in range(edges):
        edgesInput.append([next(scanner), next(scanner)])
    cycleFinder = Cycle(nodes, edges, edgesInput)
    cycleFinder.start()
    cycleFinder.printAll()

