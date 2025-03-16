
import sys

class Main:
    def btrack(self, adjList, visited, dfsCallsNodes, currentNode):
        visited[currentNode] = 1
        neighbors = adjList.get(currentNode, [])
        for neighbor in neighbors:
            if visited[neighbor] == -1:
                self.btrack(adjList, visited, dfsCallsNodes, neighbor)
        dfsCallsNodes.append(currentNode)

    def btrack2(self, adjRevList, visited, currentNode, newScc):
        visited[currentNode] = 1
        newScc.append(currentNode)
        neighbors = adjRevList.get(currentNode, [])
        for neighbor in neighbors:
            if visited[neighbor] == -1:
                self.btrack2(adjRevList, visited, neighbor, newScc)

    def getOutput(self, adjList, n):
        visited = [-1] * n
        dfsCallsNodes = []
        for i in range(n):
            if visited[i] == -1:
                self.btrack(adjList, visited, dfsCallsNodes, i)
        adjRevList = {i: [] for i in range(n)}
        for i in range(n):
            neighbors = adjList.get(i, [])
            for neighbor in neighbors:
                adjRevList[neighbor].append(i)
        visited = [-1] * n
        stronglyConnectedComponents = 0
        while dfsCallsNodes:
            node = dfsCallsNodes.pop()
            if visited[node] == -1:
                newScc = []
                self.btrack2(adjRevList, visited, node, newScc)
                stronglyConnectedComponents += 1
        return stronglyConnectedComponents

if __name__ == "__main__":
    n, e = map(int, input().split())
    adjList = {}
    for _ in range(e):
        src, dest = map(int, input().split())
        adjList[src] = adjList.get(src, []) + [dest]
    sccFinder = Main()
    result = sccFinder.getOutput(adjList, n)
    print("Number of strongly connected components:", result)

Translate the above Python code to C++ and end with comment "