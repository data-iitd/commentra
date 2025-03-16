
import sys

# To find all possible paths from source to destination
# <a href="https://en.wikipedia.org/wiki/Shortest_path_problem">Wikipedia</a>

# Program description - To find all possible paths from source to destination
# <a href="https://en.wikipedia.org/wiki/Shortest_path_problem">Wikipedia</a>

# @author <a href="https://github.com/siddhant2002">Siddhant Swarup Mallick</a>

# No. of vertices in graph
v = int(sys.stdin.readline())

# To store the paths from source to destination
paths = []

# adjacency list
adjList = [[] for i in range(v)]

# Constructor
def initAdjList():
    global adjList
    adjList = [[] for i in range(v)]

# add edge from u to v
def addEdge(u, v):
    adjList[u].append(v)

# A recursive function to print all paths from 'u' to 'd'.
# isVisited[] keeps track of vertices in current path.
# localPathList<> stores actual vertices in the current path
def storeAllPathsUtil(u, d, isVisited, localPathList):
    if u == d:
        paths.append(localPathList)
        return

    # Mark the current node
    isVisited[u] = True

    # Recursion for all the vertices adjacent to current vertex
    for i in adjList[u]:
        if not isVisited[i]:
            # store current node in path[]
            localPathList.append(i)
            storeAllPathsUtil(i, d, isVisited, localPathList)
            # remove current node in path[]
            localPathList.remove(i)

    # Mark the current node
    isVisited[u] = False

# utility method to initialise adjacency list
def initAdjList():
    global adjList
    adjList = [[] for i in range(v)]

# add edge from u to v
def addEdge(u, v):
    adjList[u].append(v)

# store all paths from source to destination
def storeAllPaths(s, d):
    isVisited = [False] * v
    localPathList = []
    storeAllPathsUtil(s, d, isVisited, localPathList)

# main method
def main():
    global v, paths, adjList

    # No. of vertices in graph
    v = int(sys.stdin.readline())

    # To store the paths from source to destination
    paths = []

    # adjacency list
    adjList = [[] for i in range(v)]

    # Constructor
    initAdjList()

    # No. of edges in graph
    edges = int(sys.stdin.readline())

    # read edges
    for i in range(edges):
        u, v = map(int, sys.stdin.readline().split())
        addEdge(u, v)

    # source and destination
    s = int(sys.stdin.readline())
    d = int(sys.stdin.readline())

    # store all paths from source to destination
    storeAllPaths(s, d)

    # print all paths from source to destination
    print("All paths from source to destination: ")
    for path in paths:
        print(path)

if __name__ == "__main__":
    main()

# 