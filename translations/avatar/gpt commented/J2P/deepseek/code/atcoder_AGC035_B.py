import sys

def main():
    # Read the number of nodes and edges from input
    num_node, num_edge = map(int, sys.stdin.readline().split())
    
    # Create an adjacency list to represent the graph
    connect = [[] for _ in range(num_node)]
    
    # Read edges and populate the adjacency list
    for _ in range(num_edge):
        a, b = map(int, sys.stdin.readline().split())
        a -= 1  # Convert to 0-indexed
        b -= 1  # Convert to 0-indexed
        connect[a].append(b)  # Add edge in both directions (undirected graph)
        connect[b].append(a)
    
    # Check if the number of edges is odd; if so, output -1 and exit
    if num_edge % 2 != 0:
        print(-1)
        return
    
    # Initialize arrays for tracking visited nodes and odd/even connections
    visited = [0] * num_node
    odd = [False] * num_node
    print_result = []  # List to accumulate output
    
    # Perform depth-first search starting from node 0
    dfs(0, -1, connect, visited, odd, print_result)
    
    # Output the result
    for line in print_result:
        print(line)

def dfs(crt, parent, connect, visited, odd, print_result):
    visited[crt] = 1  # Mark the current node as visited
    for child in connect[crt]:
        # Skip the parent node and already visited nodes
        if child == parent or visited[child] == 1:
            continue
        elif visited[child] == 2:
            # If the child has been fully processed, append the edge to output
            print_result.append(f"{crt + 1} {child + 1}")
            odd[crt] = not odd[crt]  # Toggle the odd/even state
        else:
            # Recursively call DFS on the child node
            dfs(child, crt, connect, visited, odd, print_result)
            
            # Check the odd/even state of the child node after DFS
            if odd[child]:
                print_result.append(f"{child + 1} {crt + 1}")
                odd[child] = not odd[child]  # Toggle the state
            else:
                print_result.append(f"{crt + 1} {child + 1}")
                odd[crt] = not odd[crt]  # Toggle the state
    visited[crt] = 2  # Mark the current node as fully processed

if __name__ == "__main__":
    main()
