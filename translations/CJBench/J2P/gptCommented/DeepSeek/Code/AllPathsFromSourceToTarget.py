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
    index = 0
    vertices = int(data[index])
    index += 1
    edges = int(data[index])
    index += 1
    edgeList = []
    for i in range(edges):
        u = int(data[index])
        v = int(data[index + 1])
        edgeList.append([u, v])
        index += 2
    source = int(data[index])
    index += 1
    destination = int(data[index])
    index += 1
    graph = Graph(vertices)
    for u, v in edgeList:
        graph.addEdge(u, v)
    graph.storeAllPaths(source, destination)
    print("All paths from source to destination: ")
    for path in graph.getPaths():
        print(path)

if __name__ == "__main__":
    main()
