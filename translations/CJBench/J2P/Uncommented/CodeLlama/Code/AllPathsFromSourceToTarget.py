
import sys
from collections import defaultdict

class Graph:
    def __init__(self, vertices):
        self.v = vertices
        self.adjList = defaultdict(list)

    def addEdge(self, u, v):
        self.adjList[u].append(v)

    def storeAllPaths(self, s, d):
        isVisited = [False] * self.v
        pathList = [s]
        self.storeAllPathsUtil(s, d, isVisited, pathList)

    def storeAllPathsUtil(self, u, d, isVisited, localPathList):
        if u == d:
            self.paths.append(localPathList[:])
            return
        isVisited[u] = True
        for i in self.adjList[u]:
            if not isVisited[i]:
                localPathList.append(i)
                self.storeAllPathsUtil(i, d, isVisited, localPathList)
                localPathList.pop()
        isVisited[u] = False

    def getPaths(self):
        return self.paths

def main():
    vertices = int(sys.stdin.readline())
    edges = int(sys.stdin.readline())
    edgeList = []
    for i in range(edges):
        edgeList.append(list(map(int, sys.stdin.readline().split())))
    source = int(sys.stdin.readline())
    destination = int(sys.stdin.readline())
    graph = Graph(vertices)
    for edge in edgeList:
        graph.addEdge(edge[0], edge[1])
    graph.storeAllPaths(source, destination)
    print("All paths from source to destination: ")
    for path in graph.getPaths():
        print(path)

if __name__ == "__main__":
    main()

