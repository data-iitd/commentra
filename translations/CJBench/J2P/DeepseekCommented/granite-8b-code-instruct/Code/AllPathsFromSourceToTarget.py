
import sys
sys.setrecursionlimit(10**6)

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
    vertices = int(input())
    edges = int(input())
    edgeList = []
    for _ in range(edges):
        edgeList.append(list(map(int, input().split())))
    source = int(input())
    destination = int(input())
    graph = Main(vertices)
    for edge in edgeList:
        graph.addEdge(edge[0], edge[1])
    graph.storeAllPaths(source, destination)
    print("All paths from source to destination: ")
    for path in graph.getPaths():
        print(path)

