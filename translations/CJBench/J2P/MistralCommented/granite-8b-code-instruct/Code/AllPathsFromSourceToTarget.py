
import sys

class Main:
    def __init__(self, vertices):
        self.v = vertices
        self.paths = []
        self.adjList = [[] for _ in range(vertices)]

    def addEdge(self, u, v):
        self.adjList[u].append(v)

    def storeAllPaths(self, s, d):
        isVisited = [False] * self.v
        pathList = [s]
        self.storeAllPathsUtil(s, d, isVisited, pathList)

    def storeAllPathsUtil(self, u, d, isVisited, localPathList):
        if u == d:
            self.paths.append(list(localPathList))
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

if __name__ == "__main__":
    vertices, edges = map(int, input().split())
    edgeList = []
    for _ in range(edges):
        u, v = map(int, input().split())
        edgeList.append((u, v))
    source, destination = map(int, input().split())
    graph = Main(vertices)
    for u, v in edgeList:
        graph.addEdge(u, v)
    graph.storeAllPaths(source, destination)
    print("All paths from source to destination: ")
    for path in graph.getPaths():
        print(path)

