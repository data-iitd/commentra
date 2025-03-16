
import sys

class Cycle:
    def __init__(self, nodes, edges, edgesInput):
        self.nodes = nodes
        self.edges = edges
        self.edgesInput = edgesInput
        self.adjacencyMatrix = [[0 for i in range(nodes)] for j in range(nodes)]
        self.visited = [False for i in range(nodes)]
        self.cycles = []
        for edge in edgesInput:
            start = edge[0]
            end = edge[1]
            self.adjacencyMatrix[start][end] = 1
            self.adjacencyMatrix[end][start] = 1

    def dfs(self, start, curr, temp):
        temp.append(curr)
        self.visited[curr] = True
        for i in range(self.nodes):
            if self.adjacencyMatrix[curr][i] == 1:
                if i == start:
                    self.cycles.append(temp)
                    return
                else:
                    if not self.visited[i]:
                        self.dfs(start, i, temp)
        if len(temp) > 0:
            temp.pop()
        self.visited[curr] = False

    def start(self):
        for i in range(self.nodes):
            temp = []
            self.dfs(i, i, temp)
            for j in range(self.nodes):
                self.adjacencyMatrix[i][j] = 0
                self.adjacencyMatrix[j][i] = 0

    def printAll(self):
        if len(self.cycles) == 0:
            print("No cycles found.")
            return
        for cycle in self.cycles:
            print("Cycle: ", end="")
            for i in range(len(cycle)):
                print(cycle[i], end=" -> ")
            print(cycle[0])
            print()

if __name__ == "__main__":
    nodes = int(sys.stdin.readline().strip())
    edges = int(sys.stdin.readline().strip())
    edgesInput = []
    for i in range(edges):
        edgesInput.append(list(map(int, sys.stdin.readline().strip().split())))
    cycleFinder = Cycle(nodes, edges, edgesInput)
    cycleFinder.start()
    cycleFinder.printAll()

