
import sys
import collections

class Graph:
    def __init__(self, vertices):
        self.v = vertices
        self.adjList = [[] for i in range(vertices)]

    def addEdge(self, u, v):
        self.adjList[u].append(v)

    def storeAllPaths(self, s, d):
        isVisited = [False] * self.v
        pathList = []
        pathList.append(s)
        self.storeAllPathsUtil(s, d, isVisited, pathList)

    def storeAllPathsUtil(self, u, d, isVisited, pathList):
        if u == d:
            self.paths.append(pathList[:])
            return
        isVisited[u] = True
        for i in self.adjList[u]:
            if not isVisited[i]:
                pathList.append(i)
                self.storeAllPathsUtil(i, d, isVisited, pathList)
                pathList.remove(i)
        isVisited[u] = False

    def getPaths(self):
        return self.paths

def main():
    vertices = int(sys.stdin.readline().strip())
    edges = int(sys.stdin.readline().strip())
    edgeList = []
    for i in range(edges):
        edgeList.append([int(x) for x in sys.stdin.readline().strip().split()])
    source = int(sys.stdin.readline().strip())
    destination = int(sys.stdin.readline().strip())
    graph = Graph(vertices)
    for edge in edgeList:
        graph.addEdge(edge[0], edge[1])
    graph.storeAllPaths(source, destination)
    print("All paths from source to destination: ")
    for path in graph.getPaths():
        print(path)

if __name__ == "__main__":
    main()

