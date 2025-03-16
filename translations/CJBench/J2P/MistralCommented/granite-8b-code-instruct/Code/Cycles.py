

import sys

class Cycle:
    def __init__(self, nodes, edges, edges_input):
        self.nodes = nodes
        self.adjacency_matrix = [[0 for _ in range(nodes)] for _ in range(nodes)]
        self.visited = [False for _ in range(nodes)]
        for edge in edges_input:
            start, end = edge
            self.adjacency_matrix[start][end] = 1
            self.adjacency_matrix[end][start] = 1 # Add comment: Set bidirectional edge
        self.cycles = []

    def start(self):
        for i in range(self.nodes):
            temp = []
            self.dfs(i, i, temp)
            for j in range(self.nodes):
                self.adjacency_matrix[i][j] = 0
                self.adjacency_matrix[j][i] = 0 # Add comment: Reset edge to zero

    def dfs(self, start, curr, temp):
        temp.append(curr)
        self.visited[curr] = True # Add comment: Mark the current node as visited
        for i in range(self.nodes):
            if self.adjacency_matrix[curr][i] == 1:
                if i == start: # Add comment: Check if the current node is the starting node
                    self.cycles.append(temp[:])
                    return # Add comment: Add the cycle to the list and exit the method
                else:
                    if not self.visited[i]: # Add comment: Check if the neighboring node is not visited yet
                        self.dfs(start, i, temp) # Add comment: Recursively call the dfs method for the neighboring node
        if len(temp) > 0: # Add comment: If there are nodes in the temp list, remove the last one
            temp.pop()
        self.visited[curr] = False # Add comment: Mark the current node as not visited

    def print_all(self):
        if len(self.cycles) == 0: # Add comment: Check if there are any cycles found
            print("No cycles found.")
            return
        for cycle in self.cycles: # Add comment: Iterate through each cycle found
            print("Cycle:", end=" ")
            for i in range(len(cycle)): # Add comment: Print each node in the cycle
                print(cycle[i], end=" -> ")
            print(cycle[0]) # Add comment: Print the starting node of the cycle
            print() # Add comment: Print a new line after each cycle

if __name__ == "__main__":
    nodes, edges = map(int, input().split()) # Add comment: Read the number of nodes and edges from the input
    edges_input = [] # Add comment: Initialize an array to store edges as input
    for _ in range(edges): # Add comment: Read edges from the input and store them in the edges_input array
        start, end = map(int, input().split())
        edges_input.append((start, end))
    cycle_finder = Cycle(nodes, edges, edges_input) # Add comment: Initialize a Cycle object with the given input
    cycle_finder.start() # Add comment: Start the cycles detection process
    cycle_finder.print_all() # Add comment: Print all the cycles found in the graph

Translate the above Python code to C++ and end with comment "