import sys
import collections

class Main:
    def btrack(self, adjList, visited, dfsCallsNodes, currentNode):
        visited[currentNode] = 1
        neighbors = adjList.get(currentNode)
        # Check for null before iterating
        if neighbors!= None:
            for neighbor in neighbors:
                if visited[neighbor] == -1:
                    self.btrack(adjList, visited, dfsCallsNodes, neighbor)
        dfsCallsNodes.append(currentNode)

    def btrack2(self, adjRevList, visited, currentNode, newScc):
        visited[currentNode] = 1
        newScc.append(currentNode)
        neighbors = adjRevList.get(currentNode)
        if neighbors!= None:
            for neighbor in neighbors:
                if visited[neighbor] == -1:
                    self.btrack2(adjRevList, visited, neighbor, newScc)

    def getOutput(self, adjList, n):
        visited = [-1] * n
        dfsCallsNodes = []

        # Perform DFS and populate the stack
        for i in range(n):
            if visited[i] == -1:
                self.btrack(adjList, visited, dfsCallsNodes, i)

        # Create the reversed graph
        adjRevList = collections.defaultdict(list)
        for i in range(n):
            for neighbor in adjList[i]:
                adjRevList[neighbor].append(i)

        # Find strongly connected components
        stronglyConnectedComponents = 0
        visited = [-1] * n
        while dfsCallsNodes:
            node = dfsCallsNodes.pop()
            if visited[node] == -1:
                newScc = []
                self.btrack2(adjRevList, visited, node, newScc)
                stronglyConnectedComponents += 1

        return stronglyConnectedComponents

if __name__ == "__main__":
    try:
        n = int(input())
        e = int(input())
        adjList = collections.defaultdict(list)
        for i in range(e):
            src, dest = map(int, input().split())
            adjList[src].append(dest)

        sccFinder = Main()
        result = sccFinder.getOutput(adjList, n)
        print("Number of strongly connected components: " + str(result))
    except Exception as e:
        print("Invalid input. Please provide integers as input.")

