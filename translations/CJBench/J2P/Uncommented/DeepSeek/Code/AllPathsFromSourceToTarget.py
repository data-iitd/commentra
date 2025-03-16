from collections import defaultdict

class Graph:
    def __init__(self, vertices):
        self.v = vertices
        self.paths = []
        self.adjList = defaultdict(list)

    def addEdge(self, u, v):
        self.adjList[u].append(v)

    def storeAllPathsUtil(self, u, d, isVisited, localPathList):
        if u == d:
            self.paths.append(localPathList.copy())
            return
        isVisited[u] = True
        for i in self.adjList[u]:
            if not isVisited[i]:
                localPathList.append(i)
                self.storeAllPathsUtil(i, d, isVisited, localPathList)
                localPathList.pop()
        isVisited[u] = False

    def storeAllPaths(self, s, d):
        isVisited = [False] * self.v
        localPathList = []
        localPathList.append(s)
        self.storeAllPathsUtil(s, d, isVisited, localPathList)

    def getPaths(self):
        return self.paths

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    vertices = int(data[0])
    edges = int(data[1])
    edgeList = []
    idx = 2
    for i in range(edges):
        edgeList.append([int(data[idx]), int(data[idx + 1])])
        idx += 2
    source = int(data[idx])
    destination = int(data[idx + 1])
    graph = Graph(vertices)
    for edge in edgeList:
        graph.addEdge(edge[0], edge[1])
    graph.storeAllPaths(source, destination)
    print("All paths from source to destination: ")
    for path in graph.getPaths():
        print(path)

if __name__ == "__main__":
    main()
