import sys

# Main method to execute Main's algorithm
def kosaraju(v, list):
    # Sort edges by lowest finish time
    sort_edges_by_lowest_finish_time(v, list)
    # Create transpose of the graph
    transpose_graph = create_transpose_matrix(v, list)
    # Find strongly connected components using the transpose graph
    find_strongly_connected_components(v, transpose_graph)
    # Return the list of strongly connected components
    return sccs_list

# Method to sort edges by lowest finish time using DFS
def sort_edges_by_lowest_finish_time(v, list):
    vis = [0] * v
    for i in range(v):
        if vis[i] == 0:
            dfs(i, vis, list)

# Method to create transpose of the graph
def create_transpose_matrix(v, list):
    transpose_graph = [[] for i in range(v)]
    for i in range(v):
        for neigh in list[i]:
            transpose_graph[neigh].append(i)
    return transpose_graph

# Method to find strongly connected components using DFS on transpose graph
def find_strongly_connected_components(v, transpose_graph):
    vis = [0] * v
    while stack:
        node = stack.pop()
        if vis[node] == 0:
            dfs2(node, vis, transpose_graph)
            sccs_list.append(scc)
            scc = []

# First DFS to sort nodes by finishing times
def dfs(node, vis, list):
    vis[node] = 1
    for neighbour in list[node]:
        if vis[neighbour] == 0:
            dfs(neighbour, vis, list)
    stack.append(node)

# Second DFS to find strongly connected components
def dfs2(node, vis, list):
    vis[node] = 1
    for neighbour in list[node]:
        if vis[neighbour] == 0:
            dfs2(neighbour, vis, list)
    scc.append(node)

# Main method to read input and execute Main's algorithm
def main():
    v = int(sys.stdin.readline())
    e = int(sys.stdin.readline())
    adjacency_list = [[] for i in range(v)]
    for i in range(e):
        u, v = map(int, sys.stdin.readline().split())
        adjacency_list[u].append(v)
    kosaraju = kosaraju(v, adjacency_list)
    print("Strongly Connected Components:")
    for scc in kosaraju:
        print(scc)

# Main method to read input and execute Main's algorithm
if __name__ == "__main__":
    main()


