import sys

class Main:
    def __init__(self, vertices):
        self.v = vertices
        self.paths = []
        self.adjList = [[] for i in range(vertices)]

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
                localPathList.remove(i)
        isVisited[u] = False

    def getPaths(self):
        return self.paths

if __name__ == "__main__":
    vertices = int(sys.stdin.readline().strip())
    edges = int(sys.stdin.readline().strip())
    edgeList = []
    for i in range(edges):
        edgeList.append([int(x) for x in sys.stdin.readline().strip().split()])
    source = int(sys.stdin.readline().strip())
    destination = int(sys.stdin.readline().strip())
    graph = Main(vertices)
    for edge in edgeList:
        graph.addEdge(edge[0], edge[1])
    graph.storeAllPaths(source, destination)
    print("All paths from source to destination: ")
    for path in graph.getPaths():
        print(path)

