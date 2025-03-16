
import sys

# read input from standard input
v, e = map(int, sys.stdin.readline().split())

# read edges and add them to the graph
edgeList = []
for i in range(e):
    edgeList.append(list(map(int, sys.stdin.readline().split())))

# read source and destination vertices
s, d = map(int, sys.stdin.readline().split())

# find all paths from source to destination
paths = []
def storeAllPathsUtil(u, d, isVisited, localPathList):
    if u == d:
        paths.append(localPathList[:])
        return

    isVisited[u] = True
    for i in adjList[u]:
        if not isVisited[i]:
            localPathList.append(i)
            storeAllPathsUtil(i, d, isVisited, localPathList)
            localPathList.pop()
    isVisited[u] = False

adjList = [[] for i in range(v)]
for edge in edgeList:
    adjList[edge[0]].append(edge[1])

storeAllPathsUtil(s, d, [False] * v, [s])

# print all paths from source to destination
print("All paths from source to destination: ")
for path in paths:
    print(path)

