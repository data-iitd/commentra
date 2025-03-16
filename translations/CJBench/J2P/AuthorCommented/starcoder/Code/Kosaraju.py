
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.Stack;

class Main:
    # Stack to sort edges by the lowest finish time (used in the first DFS)
    stack = Stack()
    # Store each strongly connected component
    scc = []
    # List of all SCCs
    sccsList = []

    def kosaraju(self, v, list):
        self.sortEdgesByLowestFinishTime(v, list)
        transposeGraph = self.createTransposeMatrix(v, list)
        self.findStronglyConnectedComponents(v, transposeGraph)
        return self.sccsList

    def sortEdgesByLowestFinishTime(self, v, list):
        vis = [0] * v
        for i in range(v):
            if vis[i] == 0:
                self.dfs(i, vis, list)

    def createTransposeMatrix(self, v, list):
        transposeGraph = []
        for i in range(v):
            transposeGraph.append([])
        for i in range(v):
            for neigh in list[i]:
                transposeGraph[neigh].append(i)
        return transposeGraph

    def findStronglyConnectedComponents(self, v, transposeGraph):
        vis = [0] * v
        while not self.stack.isEmpty():
            node = self.stack.pop()
            if vis[node] == 0:
                self.dfs2(node, vis, transposeGraph)
                self.sccsList.append(self.scc)
                self.scc = []

    def dfs(self, node, vis, list):
        vis[node] = 1
        for neighbour in list[node]:
            if vis[neighbour] == 0:
                self.dfs(neighbour, vis, list)
        self.stack.push(node)

    def dfs2(self, node, vis, list):
        vis[node] = 1
        for neighbour in list[node]:
            if vis[neighbour] == 0:
                self.dfs2(neighbour, vis, list)
        self.scc.append(node)

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

