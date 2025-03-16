
import sys

# This class implements the Main Algorithm to find all the Strongly Connected Components (SCCs)
# of a directed graph. Main's algorithm runs in linear time and leverages the concept that
# the SCCs of a directed graph remain the same in its transpose (reverse) graph.
#
# <p>
# A strongly connected component (SCC) of a directed graph is a subgraph where every vertex
# is reachable from every other vertex in the subgraph. The Main algorithm is particularly
# efficient for finding SCCs because it performs two Depth First Search (DFS) passes on the
# graph and its transpose.
# </p>
#
# <p><strong>Algorithm:</strong></p>
# <ol>
#     <li>Perform DFS on the original graph and push nodes to a stack in the order of their finishing time.</li>
#     <li>Generate the transpose (reversed edges) of the original graph.</li>
#     <li>Perform DFS on the transpose graph, using the stack from the first DFS. Each DFS run on the transpose graph gives a SCC.</li>
# </ol>
#
# <p><strong>Example Graph:</strong></p>
# <pre>
# 0 <--- 2 -------> 3 -------- > 4 ---- > 7
# |     ^                      | ^       ^
# |    /                       |  \     /
# |   /                        |   \   /
# v  /                         v    \ /
# 1                            5 --> 6
# </pre>
#
# <p><strong>SCCs in the example:</strong></p>
# <ul>
#     <li>{0, 1, 2}</li>
#     <li>{3}</li>
#     <li>{4, 5, 6}</li>
#     <li>{7}</li>
# </ul>
#
# <p>The order of nodes in an SCC does not matter because every node in an SCC is reachable from every other node within the same SCC.</p>
#
# <p><strong>Graph Transpose Example:</strong></p>
# <pre>
# 0 ---> 2 <------- 3 <------- 4 <------ 7
# ^     /                      ^ \       /
# |    /                       |  \     /
# |   /                        |   \   /
# |  v                         |    v v
# 1                            5 <--- 6
# </pre>
#
# The SCCs of this transpose graph are the same as the original graph.

class Main:

    # Stack to sort edges by the lowest finish time (used in the first DFS)
    stack = []
    # Store each strongly connected component
    scc = []
    # List of all SCCs
    sccsList = []

    # Main function to perform Main's Algorithm.
    # Steps:
    # 1. Sort nodes by the lowest finishing time
    # 2. Create the transpose (reverse edges) of the original graph
    # 3. Find SCCs by performing DFS on the transpose graph
    # 4. Return the list of SCCs
    #
    # @param v the number of vertices in the graph
    # @param list the adjacency list representing the directed graph
    # @return a list of SCCs where each SCC is a list of vertices
    def kosaraju(self, v, list):
        self.sortEdgesByLowestFinishTime(v, list)
        transposeGraph = self.createTransposeMatrix(v, list)
        self.findStronglyConnectedComponents(v, transposeGraph)
        return self.sccsList

    # Performs DFS on the original graph to sort nodes by their finishing times.
    # @param v the number of vertices in the graph
    # @param list the adjacency list representing the original graph
    def sortEdgesByLowestFinishTime(self, v, list):
        vis = [0] * v
        for i in range(v):
            if vis[i] == 0:
                self.dfs(i, vis, list)

    # Creates the transpose (reverse) of the original graph.
    # @param v the number of vertices in the graph
    # @param list the adjacency list representing the original graph
    # @return the adjacency list representing the transposed graph
    def createTransposeMatrix(self, v, list):
        transposeGraph = [[] for i in range(v)]
        for i in range(v):
            for neighbour in list[i]:
                transposeGraph[neighbour].append(i)
        return transposeGraph

    # Finds the strongly connected components (SCCs) by performing DFS on the transposed graph.
    # @param v the number of vertices in the graph
    # @param transposeGraph the adjacency list representing the transposed graph
    def findStronglyConnectedComponents(self, v, transposeGraph):
        vis = [0] * v
        while len(self.stack) > 0:
            node = self.stack.pop()
            if vis[node] == 0:
                self.dfs2(node, vis, transposeGraph)
                self.sccsList.append(self.scc)
                self.scc = []

    # Performs DFS on the original graph and pushes nodes onto the stack in order of their finish time.
    # @param node the current node being visited
    # @param vis array to keep track of visited nodes
    # @param list the adjacency list of the graph
    def dfs(self, node, vis, list):
        vis[node] = 1
        for neighbour in list[node]:
            if vis[neighbour] == 0:
                self.dfs(neighbour, vis, list)
        self.stack.append(node)

    # Performs DFS on the transposed graph to find the strongly connected components.
    # @param node the current node being visited
    # @param vis array to keep track of visited nodes
    # @param list the adjacency list of the transposed graph
    def dfs2(self, node, vis, list):
        vis[node] = 1
        for neighbour in list[node]:
            if vis[neighbour] == 0:
                self.dfs2(neighbour, vis, list)
        self.scc.append(node)

if __name__ == "__main__":
    v = int(sys.stdin.readline())
    e = int(sys.stdin.readline())

    adjacencyList = [[] for i in range(v)]
    for i in range(e):
        u, v = map(int, sys.stdin.readline().split())
        adjacencyList[u].append(v)

    kosaraju = Main()
    sccs = kosaraju.kosaraju(v, adjacencyList)

    print("Strongly Connected Components:")
    for scc in sccs:
        print(scc)

