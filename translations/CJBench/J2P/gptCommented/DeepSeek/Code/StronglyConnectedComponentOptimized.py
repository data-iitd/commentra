import sys
from collections import defaultdict, deque

class SCCFinder:
    def __init__(self, n):
        self.n = n
        self.adjList = defaultdict(list)
        self.adjRevList = defaultdict(list)
        self.visited = [-1] * n
        self.dfsCallsNodes = deque()

    def add_edge(self, src, dest):
        self.adjList[src].append(dest)
        self.adjRevList[dest].append(src)

    def dfs(self, currentNode):
        self.visited[currentNode] = 1
        for neighbor in self.adjList[currentNode]:
            if self.visited[neighbor] == -1:
                self.dfs(neighbor)
        self.dfsCallsNodes.appendleft(currentNode)

    def reverse_dfs(self, currentNode, newScc):
        self.visited[currentNode] = 1
        newScc.append(currentNode)
        for neighbor in self.adjRevList[currentNode]:
            if self.visited[neighbor] == -1:
                self.reverse_dfs(neighbor, newScc)

    def get_output(self):
        for i in range(self.n):
            if self.visited[i] == -1:
                self.dfs(i)

        self.visited = [-1] * self.n
        stronglyConnectedComponents = 0

        while self.dfsCallsNodes:
            node = self.dfsCallsNodes.pop()
            if self.visited[node] == -1:
                newScc = []
                self.reverse_dfs(node, newScc)
                stronglyConnectedComponents += 1

        return stronglyConnectedComponents

def main():
    try:
        n, e = map(int, sys.stdin.readline().split())
        sccFinder = SCCFinder(n)
        for _ in range(e):
            src, dest = map(int, sys.stdin.readline().split())
            sccFinder.add_edge(src, dest)
        result = sccFinder.get_output()
        print("Number of strongly connected components:", result)
    except ValueError:
        print("Invalid input. Please provide integers as input.")

if __name__ == "__main__":
    main()
