import sys
import collections

def btrack(adjList, visited, dfsCallsNodes, currentNode):
    visited[currentNode] = 1
    neighbors = adjList.get(currentNode)
    if neighbors is not None:
        for neighbor in neighbors:
            if visited[neighbor] == -1:
                btrack(adjList, visited, dfsCallsNodes, neighbor)
    dfsCallsNodes.append(currentNode)

def btrack2(adjRevList, visited, currentNode, newScc):
    visited[currentNode] = 1
    newScc.append(currentNode)
    neighbors = adjRevList.get(currentNode)
    if neighbors is not None:
        for neighbor in neighbors:
            if visited[neighbor] == -1:
                btrack2(adjRevList, visited, neighbor, newScc)

def getOutput(adjList, n):
    visited = [-1] * n
    dfsCallsNodes = []
    for i in range(n):
        if visited[i] == -1:
            btrack(adjList, visited, dfsCallsNodes, i)
    adjRevList = collections.defaultdict(list)
    for i in range(n):
        adjRevList[i] = []
    for i in range(n):
        neighbors = adjList.get(i)
        if neighbors is not None:
            for neighbor in neighbors:
                adjRevList[neighbor].append(i)
    visited = [-1] * n
    stronglyConnectedComponents = 0
    while len(dfsCallsNodes) > 0:
        node = dfsCallsNodes.pop()
        if visited[node] == -1:
            newScc = []
            btrack2(adjRevList, visited, node, newScc)
            stronglyConnectedComponents += 1
    return stronglyConnectedComponents

if __name__ == "__main__":
    n = int(sys.stdin.readline().strip())
    e = int(sys.stdin.readline().strip())
    adjList = collections.defaultdict(list)
    for i in range(e):
        src, dest = map(int, sys.stdin.readline().strip().split())
        adjList[src].append(dest)
    result = getOutput(adjList, n)
    print("Number of strongly connected components: " + str(result))

