import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.Stack;

class Main:
    # Stack to store nodes according to their finishing times
    stack = Stack()
    # List to store the current strongly connected component
    scc = []
    # List to store all strongly connected components
    sccsList = []

    # Main method to execute Main's algorithm
    def kosaraju(self, v, list):
        # Sort edges by lowest finish time
        self.sortEdgesByLowestFinishTime(v, list)
        # Create transpose of the graph
        transposeGraph = self.createTransposeMatrix(v, list)
        # Find strongly connected components using the transpose graph
        self.findStronglyConnectedComponents(v, transposeGraph)
        # Return the list of strongly connected components
        return self.sccsList

    # Method to sort edges by lowest finish time using DFS
    def sortEdgesByLowestFinishTime(self, v, list):
        vis = [0] * v
        for i in range(v):
            if vis[i] == 0:
                self.dfs(i, vis, list)

    # Method to create transpose of the graph
    def createTransposeMatrix(self, v, list):
        transposeGraph = []
        for i in range(v):
            transposeGraph.append([])
        for i in range(v):
            for neigh in list[i]:
                transposeGraph[neigh].append(i)
        return transposeGraph

    # Method to find strongly connected components using DFS on transpose graph
    def findStronglyConnectedComponents(self, v, transposeGraph):
        vis = [0] * v
        while not self.stack.isEmpty():
            node = self.stack.pop()
            if vis[node] == 0:
                self.dfs2(node, vis, transposeGraph)
                self.sccsList.append(self.scc)
                self.scc = []

    # First DFS to sort nodes by finishing times
    def dfs(self, node, vis, list):
        vis[node] = 1
        for neighbour in list[node]:
            if vis[neighbour] == 0:
                self.dfs(neighbour, vis, list)
        self.stack.push(node)

    # Second DFS to find strongly connected components
    def dfs2(self, node, vis, list):
        vis[node] = 1
        for neighbour in list[node]:
            if vis[neighbour] == 0:
                self.dfs2(neighbour, vis, list)
        self.scc.append(node)

# Main method to read input and execute Main's algorithm
if __name__ == '__main__':
    sc = Scanner(System.in)
    vertices = sc.nextInt()
    edges = sc.nextInt()
    list = []
    for i in range(vertices):
        list.append([])
    for i in range(edges):
        u = sc.nextInt()
        v = sc.nextInt()
        list[u].append(v)
    kosaraju = Main()
    sccs = kosaraju.kosaraju(vertices, list)
    print("Strongly Connected Components:")
    for scc in sccs:
        print(scc)
    sc.close()

