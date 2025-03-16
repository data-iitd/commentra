from collections import defaultdict  # Importing defaultdict for creating a graph.
import sys  # Importing sys for handling input.

class Main:
    def __init__(self):
        self.count = 0  # Declaring and initializing the count variable to 0.
        self.seen = []  # Declaring the seen list to keep track of visited nodes.
        self.path = 0
        self.cycle = 1
        self.graph = defaultdict(list)  # Declaring the graph as a defaultdict of lists.

    def dfs(self, child, par):
        if self.seen[child]:  # Checking if the current node has already been visited.
            return self.cycle  # If it has, then there is a cycle in the graph and we return 1.
        self.seen[child] = True  # Marking the current node as visited.

        for i in self.graph[child]:  # Iterating through the neighbors of the current node.
            if i != par:  # Checking if the neighbor is not the parent node.
                self.count += 1  # Incrementing the count of edges traversed.
                if self.dfs(i, child) == self.cycle:  # Recursively calling the dfs function on the neighbor.
                    return self.cycle  # If there is a cycle, then we return 1.
        return self.path  # If there is no cycle, then we return 0.

if __name__ == "__main__":
    input = sys.stdin.read
    data = input().splitlines()
    m, n = map(int, data[0].split())  # Reading the number of nodes and edges in the graph.
    ft = Main()  # Creating a new instance of the Main class.
    ft.seen = [False] * (m + 1)  # Initializing the seen list as a boolean list of size (m+1).

    for i in range(1, n + 1):  # Reading the edges from the input and adding them to the graph.
        x, y = map(int, data[i].split())
        ft.graph[x].append(y)  # Adding an edge from x to y.
        ft.graph[y].append(x)  # Adding an edge from y to x.

    toremove = 0  # Initializing the toremove variable to 0.
    for i in range(1, m + 1):  # Iterating through all the nodes in the graph.
        if not ft.seen[i]:  # If the current node has not been visited.
            ft.count = 0  # Resetting the count of edges traversed to 0.
            if ft.dfs(i, 0) == ft.cycle:  # If there is a cycle in the subgraph rooted at the current node.
                if ft.count % 2 == 1:  # If the number of edges traversed is odd.
                    toremove += 1  # Increment the toremove variable.

    if (m - toremove) % 2 == 1:  # Checking if the number of nodes is odd.
        toremove += 1  # If it is, then increment the toremove variable.

    print(toremove)  # Printing the result.

# <END-OF-CODE>
