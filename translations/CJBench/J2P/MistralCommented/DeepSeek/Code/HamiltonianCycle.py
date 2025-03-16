import sys

class HamiltonianCycle:
    def __init__(self, graph):
        self.graph = graph
        self.vertex = len(graph)
        self.pathCount = 0
        self.cycle = [-1] * (self.vertex + 1)

    def find_main(self):
        if self.vertex == 1:
            return [0, 0]

        self.cycle[0] = 0
        self.pathCount = 1

        if not self.is_path_found(0):
            return [-1] * (self.vertex + 1)

        self.cycle[self.pathCount] = self.cycle[0]
        return self.cycle

    def is_path_found(self, vertex):
        if self.graph[vertex][0] == 1 and self.pathCount == self.vertex:
            return True

        if self.pathCount == self.vertex:
            return False

        for v in range(self.vertex):
            if self.graph[vertex][v] == 1:
                self.cycle[self.pathCount] = v
                self.pathCount += 1
                self.graph[vertex][v] = 0
                self.graph[v][vertex] = 0

                if self.is_path_found(v):
                    return True

                self.graph[vertex][v] = 1
                self.graph[v][vertex] = 1
                self.pathCount -= 1

        return False

    def is_present(self, vertex):
        for i in range(self.pathCount):
            if self.cycle[i] == vertex:
                return True
        return False

if __name__ == "__main__":
    input_data = sys.stdin.read().splitlines()
    n = int(input_data[0])
    graph = []
    index = 1

    for i in range(n):
        graph.append(list(map(int, input_data[index].split())))
        index += 1

    hamiltonian_cycle = HamiltonianCycle(graph)
    result = hamiltonian_cycle.find_main()

    print("Hamiltonian Cycle:")
    if result[0] == -1:
        print("No Hamiltonian Cycle exists.")
    else:
        for vertex in result:
            print(vertex, end=" ")
    print()
