import java.util.ArrayList;
import java.util.Scanner;

# Class to detect cycles in a directed graph using DFS
class Cycle:
    def __init__(self, nodes, edges, edgesInput):
        self.nodes = nodes
        self.adjacencyMatrix = [[0 for i in range(nodes)] for j in range(nodes)]
        self.visited = [False for i in range(nodes)]
        for edge in edgesInput:
            start = edge[0]
            end = edge[1]
            self.adjacencyMatrix[start][end] = 1

    # Method to start the cycle detection process
    def start(self):
        for i in range(self.nodes):
            temp = []
            self.dfs(i, i, temp)

    # Private method to perform DFS and detect cycles
    def dfs(self, start, curr, temp):
        temp.append(curr)
        self.visited[curr] = True
        for i in range(self.nodes):
            if self.adjacencyMatrix[curr][i] == 1:
                if i == start:
                    self.cycles.append(temp)
                else:
                    if not self.visited[i]:
                        self.dfs(start, i, temp)
        if temp:
            temp.pop()
        self.visited[curr] = False

    # Method to print all detected cycles
    def printAll(self):
        if not self.cycles:
            print("No cycles found.")
            return
        for cycle in self.cycles:
            for i in range(len(cycle)):
                print(cycle[i], end=" -> ")
            print(cycle[0])
            print()


# Main class to run the cycle detection program
if __name__ == "__main__":
    scanner = Scanner(System.in)
    nodes = scanner.nextInt()
    edges = scanner.nextInt()
    edgesInput = [[0 for i in range(2)] for j in range(edges)]
    for i in range(edges):
        edgesInput[i][0] = scanner.nextInt()
        edgesInput[i][1] = scanner.nextInt()
    cycleFinder = Cycle(nodes, edges, edgesInput)
    cycleFinder.start()
    cycleFinder.printAll()

