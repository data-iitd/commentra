
import sys

# Single vertex graph
if len(graph) == 1:
    return [0, 0]

self.vertex = len(graph)
self.cycle = [-1] * (self.vertex + 1)
self.cycle[0] = 0
self.pathCount = 1
if not self.isPathFound(0):
    self.cycle = [-1] * (self.vertex + 1)
else:
    self.cycle[self.cycle.length - 1] = self.cycle[0]

return self.cycle

def isPathFound(self, vertex):
    if self.graph[vertex][0] == 1 and self.pathCount == self.vertex:
        return True

    # If all vertices are visited but the last vertex is not connected to the start
    if self.pathCount == self.vertex:
        return False

    for v in range(self.vertex):
        if self.graph[vertex][v] == 1:
            self.cycle[self.pathCount] = v
            self.graph[vertex][v] = 0
            self.graph[v][vertex] = 0

            # Recursively attempt to complete the cycle
            if not self.isPresent(v):
                return self.isPathFound(v)

            # Restore the edge if the path does not work
            self.graph[vertex][v] = 1
            self.graph[v][vertex] = 1
            self.cycle[self.pathCount - 1] = -1

    return False

def isPresent(self, vertex):
    for i in range(self.pathCount - 1):
        if self.cycle[i] == vertex:
            return True

    return False

def main():
    n = int(input())

    graph = []
    for i in range(n):
        graph.append([int(j) for j in input().split()])

    hamiltonianCycle = HamiltonianCycle()
    result = hamiltonianCycle.findMain(graph)

    print("Hamiltonian Cycle:")
    if result[0] == -1:
        print("No Hamiltonian Cycle exists.")
    else:
        for vertex in result:
            print(vertex, end=" ")

if __name__ == "__main__":
    main()

