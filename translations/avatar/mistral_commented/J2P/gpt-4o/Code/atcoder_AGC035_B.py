# Importing the necessary module for reading input
import sys
from collections import defaultdict

# Main function where the program starts execution
def main():
    input = sys.stdin.read
    data = input().split()
    
    # Reading the number of nodes and edges from the input
    numNode = int(data[0])
    numEdge = int(data[1])
    
    # Initializing the connect dictionary to store the list of neighbors for each node
    connect = defaultdict(list)

    # Reading the edges and adding them to the connect dictionary
    index = 2
    for _ in range(numEdge):
        a = int(data[index]) - 1  # Reading the first node index
        b = int(data[index + 1]) - 1  # Reading the second node index
        connect[a].append(b)  # Adding the second node index to the first node's list of neighbors
        connect[b].append(a)  # Adding the first node index to the second node's list of neighbors
        index += 2

    # Checking if the number of edges is odd. If it is, then the graph is not bipartite
    if numEdge % 2 != 0:
        print(-1)
        return

    # Initializing the visited, odd, and print lists
    visited = [0] * numNode
    odd = [False] * numNode
    output = []

    # Calling the dfs function with the first node and -1 as the parent node
    dfs(0, -1, connect, visited, odd, output)

    # Printing the output
    print("\n".join(output))

# Recursive depth-first search function to perform bipartite traversal
def dfs(crt, parent, connect, visited, odd, output):
    # Marking the current node as visited
    visited[crt] = 1

    # Iterating through the neighbors of the current node
    for child in connect[crt]:
        # Skipping the neighbor if it is the parent node or already visited
        if child == parent or visited[child] == 1:
            continue

        # If the neighbor has already been assigned an odd component, then we add an edge
        # between the current and neighbor nodes. Otherwise, we swap the components and continue the traversal.
        if visited[child] == 2:
            output.append(f"{crt + 1} {child + 1}")
            odd[crt] = not odd[crt]
        else:
            dfs(child, crt, connect, visited, odd, output)
            if odd[child]:
                output.append(f"{child + 1} {crt + 1}")
                odd[child] = not odd[child]
            else:
                output.append(f"{crt + 1} {child + 1}")
                odd[crt] = not odd[crt]

    # Marking the current node as visited with component 2
    visited[crt] = 2

# Entry point of the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>
