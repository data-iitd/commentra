import sys
from collections import defaultdict

# Importing the utility class Scanner for reading input from the standard input stream.

def main():
    # Reading the number of nodes and edges from the input.
    num_node = int(input())
    num_edge = int(input())

    # Initializing the connect dictionary to store the list of neighbors for each node.
    connect = defaultdict(list)

    # Reading the edges and adding them to the connect dictionary.
    for _ in range(num_edge):
        a, b = map(int, input().split())
        connect[a].append(b)  # Adding the second node index to the first node's list of neighbors.
        connect[b].append(a)  # Adding the first node index to the second node's list of neighbors.

    # Checking if the number of edges is odd. If it is, then the graph is not bipartite, and we print -1 and exit.
    if num_edge % 2 != 0:
        print(-1)
        return

    # Initializing the visited, odd, and print arrays and objects.
    visited = [0] * (num_node + 1)
    odd = [False] * (num_node + 1)
    print_ = []

    # Calling the dfs method with the first node and -1 as the parent node.
    dfs(1, -1, connect, visited, odd, print_)

    # Printing the output.
    for edge in print_:
        print(edge)

def dfs(crt, parent, connect, visited, odd, print_):
    # Marking the current node as visited.
    visited[crt] = 1

    # Iterating through the neighbors of the current node.
    for child in connect[crt]:
        # Skipping the neighbor if it is the parent node or already visited.
        if child == parent or visited[child] == 1:
            continue

        # If the neighbor has already been assigned an odd component, then we add an edge between the current and neighbor nodes.
        # Otherwise, we swap the components and continue the traversal.
        if visited[child] == 2:
            print_.append(f"{crt} {child}")
            odd[crt] = not odd[crt]
        else:
            dfs(child, crt, connect, visited, odd, print_)
            if odd[child]:
                print_.append(f"{child} {crt}")
                odd[child] = not odd[child]
            else:
                print_.append(f"{crt} {child}")
                odd[crt] = not odd[crt]

    # Marking the current node as visited with component 2.
    visited[crt] = 2

if __name__ == "__main__":
    main()
