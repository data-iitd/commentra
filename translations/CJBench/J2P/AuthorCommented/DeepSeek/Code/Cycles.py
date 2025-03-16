class Cycle:
    def __init__(self, nodes, edges, edges_input):
        self.nodes = nodes
        self.adjacency_matrix = [[0] * nodes for _ in range(nodes)]
        self.visited = [False] * nodes
        self.cycles = []

        # Fill adjacency matrix with edge data
        for edge in edges_input:
            start, end = edge
            self.adjacency_matrix[start][end] = 1

    def start(self):
        for i in range(self.nodes):
            temp = []
            self.dfs(i, i, temp)
            for j in range(self.nodes):
                self.adjacency_matrix[i][j] = 0
                self.adjacency_matrix[j][i] = 0

    def dfs(self, start, curr, temp):
        temp.append(curr)
        self.visited[curr] = True
        for i in range(self.nodes):
            if self.adjacency_matrix[curr][i] == 1:
                if i == start:
                    self.cycles.append(temp.copy())
                elif not self.visited[i]:
                    self.dfs(start, i, temp)
        if temp:
            temp.pop()
        self.visited[curr] = False

    def print_all(self):
        if not self.cycles:
            print("No cycles found.")
            return

        for cycle in self.cycles:
            for i in range(len(cycle)):
                print(cycle[i], end=" -> ")
            print(cycle[0])
            print()


def main():
    import sys
    input = sys.stdin.read
    data = input().split()

    index = 0
    nodes = int(data[index])
    edges = int(data[index + 1])
    index += 2

    edges_input = []
    for i in range(edges):
        start = int(data[index])
        end = int(data[index + 1])
        edges_input.append((start, end))
        index += 2

    cycle_finder = Cycle(nodes, edges, edges_input)
    cycle_finder.start()
    cycle_finder.print_all()


if __name__ == "__main__":
    main()
