import numpy as np

class Main:
    def __init__(self):
        self.vertex = 0
        self.path_count = 0
        self.cycle = []
        self.graph = []

    def find_main(self, graph):
        if len(graph) == 1:
            return [0, 0]

        self.vertex = len(graph)
        self.cycle = [-1] * (self.vertex + 1)
        self.graph = graph
        self.cycle[0] = 0
        self.path_count = 1

        if not self.is_path_found(0):
            self.cycle = [-1] * (self.vertex + 1)
            return self.cycle

        self.cycle[-1] = self.cycle[0]
        return self.cycle

    def is_path_found(self, vertex):
        if self.graph[vertex][0] == 1 and self.path_count == self.vertex:
            return True

        if self.path_count == self.vertex:
            return False

        for v in range(self.vertex):
            if self.graph[vertex][v] == 1:
                self.cycle[self.path_count] = v
                self.path_count += 1
                self.graph[vertex][v] = 0
                self.graph[v][vertex] = 0

                if self.is_path_found(v):
                    return True

                self.graph[vertex][v] = 1
                self.graph[v][vertex] = 1
                self.path_count -= 1
                self.cycle[self.path_count] = -1

        return False

    def is_present(self, vertex):
        for i in range(self.path_count - 1):
            if self.cycle[i] == vertex:
                return True
        return False

if __name__ == "__main__":
    n = int(input("Enter the number of vertices: "))
    graph = []

    print("Enter the adjacency matrix:")
    for i in range(n):
        row = list(map(int, input().split()))
        graph.append(row)

    hamiltonian_cycle = Main()
    result = hamiltonian_cycle.find_main(graph)

    print("Hamiltonian Cycle:")
    if result[0] == -1:
        print("No Hamiltonian Cycle exists.")
    else:
        print(" ".join(map(str, result)))

# <END-OF-CODE>
