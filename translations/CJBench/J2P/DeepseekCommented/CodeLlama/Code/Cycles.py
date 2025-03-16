
# Import modules
import sys

# Class to detect cycles in a directed graph using DFS
class Cycle:
    def __init__(self, nodes, edges, edgesInput):
        self.nodes = nodes
        self.adjacencyMatrix = [[0] * nodes for _ in range(nodes)]
        self.visited = [False] * nodes
        self.cycles = []
        for edge in edgesInput:
            start = edge[0]
            end = edge[1]
            self.adjacencyMatrix[start][end] = 1

    def start(self):
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
        if temp:
            temp.pop()
        self.visited[curr] = False

    def printAll(self):
        if not self.cycles:
            print("No cycles found.")
            return
        for cycle in self.cycles:
            for i in range(len(cycle)):
                print(cycle[i], end=" -> ")
            print(cycle[0])

# Main function
def main():
    nodes = int(sys.stdin.readline().strip())
    edges = int(sys.stdin.readline().strip())
    edgesInput = []
    for _ in range(edges):
        edgesInput.append(list(map(int, sys.stdin.readline().strip().split())))
    cycleFinder = Cycle(nodes, edges, edgesInput)
    cycleFinder.start()
    cycleFinder.printAll()

if __name__ == "__main__":
    main()
