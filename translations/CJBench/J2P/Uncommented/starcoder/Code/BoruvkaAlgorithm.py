
import sys
import heapq

class Edge:
    def __init__(self, src, dest, weight):
        self.src = src
        self.dest = dest
        self.weight = weight

class Graph:
    def __init__(self, vertex):
        self.vertex = vertex
        self.edges = []

def find(components, i):
    if components[i].parent!= i:
        components[i].parent = find(components, components[i].parent)
    return components[i].parent

def union(components, x, y):
    xroot = find(components, x)
    yroot = find(components, y)
    if components[xroot].rank < components[yroot].rank:
        components[xroot].parent = yroot
    elif components[xroot].rank > components[yroot].rank:
        components[yroot].parent = xroot
    else:
        components[yroot].parent = xroot
        components[xroot].rank += 1

def boruvkaMST(graph):
    components = initializeComponents(graph)
    result = []
    while hasMoreEdgesToAdd(graph, components, result):
        cheapest = computeCheapestEdges(graph, components)
        merge(graph, components, result, cheapest)
    return result

def hasMoreEdgesToAdd(graph, components, result):
    return len(result) < graph.vertex - 1

def computeCheapestEdges(graph, components):
    cheapest = [None] * graph.vertex
    for edge in graph.edges:
        set1 = find(components, edge.src)
        set2 = find(components, edge.dest)
        if set1!= set2:
            if cheapest[set1] == None or edge.weight < cheapest[set1].weight:
                cheapest[set1] = edge
            if cheapest[set2] == None or edge.weight < cheapest[set2].weight:
                cheapest[set2] = edge
    return cheapest

def initializeComponents(graph):
    components = [None] * graph.vertex
    for v in range(graph.vertex):
        components[v] = Component(v, 0)
    return components

def merge(graph, components, result, cheapest):
    for i in range(graph.vertex):
        if cheapest[i]!= None:
            set1 = find(components, cheapest[i].src)
            set2 = find(components, cheapest[i].dest)
            if set1!= set2:
                result.append(cheapest[i])
                union(components, set1, set2)

class Component:
    def __init__(self, parent, rank):
        self.parent = parent
        self.rank = rank

def main():
    graph = Graph(int(sys.stdin.readline()))
    for i in range(graph.vertex):
        graph.edges.append(Edge(int(sys.stdin.readline()), int(sys.stdin.readline()), int(sys.stdin.readline())))
    mst = boruvkaMST(graph)
    totalWeight = 0
    print("Edges in MST:")
    for edge in mst:
        print(edge.src, " - ", edge.dest, " : ", edge.weight)
        totalWeight += edge.weight
    print("Total Weight: ", totalWeight)

if __name__ == "__main__":
    main()

