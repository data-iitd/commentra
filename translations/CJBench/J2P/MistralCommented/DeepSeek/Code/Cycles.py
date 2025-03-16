class Cycle:
    def __init__(self, nodes, edges, edges_input):
        self.nodes = nodes
        self.adjacency_matrix = [[0] * nodes for _ in range(nodes)]
        self.visited = [False] * nodes
        self.cycles = []
        for edge in edges_input:
            start, end = edge
            self.adjacency_matrix[start][end] = 1
            self.adjacency_matrix[end][start] = 1  # Set bidirectional edge

    def start(self):
        for i in range(self.nodes):
            self.dfs(i, i, [])
            for j in range(self.nodes):
                self.adjacency_matrix[i][j] = 0
                self.adjacency_matrix[j][i] = 0  # Reset edge to zero

    def dfs(self, start, curr, temp):
        temp.append(curr)
        self.visited[curr] = True  # Mark the current node as visited
        for i in range(self.nodes):
            if self.adjacency_matrix[curr][i] == 1:
                if i == start:  # Check if the current node is the starting node
                    self.cycles.append(temp.copy())
                    return  # Add the cycle to the list and exit the method
                elif not self.visited[i]:  # Check if the neighboring node is not visited yet
                    self.dfs(start, i, temp)  # Recursively call the dfs method for the neighboring node
        if temp:  # If there are nodes in the temp list, remove the last one
            temp.pop()
        self.visited[curr] = False  # Mark the current node as not visited

    def print_all(self):
        if not self.cycles:  # Check if there are any cycles found
            print("No cycles found.")
            return
        for cycle in self.cycles:  # Iterate through each cycle found
            print("Cycle:", end=" ")
            for i in range(len(cycle)):  # Print each node in the cycle
                print(cycle[i], end=" -> ")
            print(cycle[0])  # Print the starting node of the cycle
            print()  # Print a new line after each cycle


def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    index = 0
    nodes = int(data[index])
    index += 1
    edges = int(data[index])
    index += 1
    edges_input = []
    for i in range(edges):
        start = int(data[index])
        index += 1
        end = int(data[index])
        index += 1
        edges_input.append((start, end))
    cycle_finder = Cycle(nodes, edges, edges_input)  # Initialize a Cycle object with the given input
    cycle_finder.start()  # Start the cycles detection process
    cycle_finder.print_all()  # Print all the cycles found in the graph


if __name__ == "__main__":
    main()
