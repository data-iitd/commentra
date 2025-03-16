# Define a 2D list 'e' to store the edges of the graph
e = []

# Define variables 'n' and 'm' to store the number of nodes and edges respectively
n, m = 0, 0

# Function 'print_edge' to print the edges of the graph
def print_edge(e):
    # Iterate through each node in the graph
    for i in range(1, n + 1):
        # Print the node number and its connected nodes
        print(f"{i}: ", end="")
        for v in e[i]:
            print(f"{v} ", end="")
        print()

# Function 'dfs' to perform Depth First Search traversal
def dfs(v, visited):
    # Initialize a list 'visited' to keep track of visited nodes
    # visited[v] = True
    # print(v, visited)

    # Check if all nodes are visited, if yes then it's a strongly connected component
    comp = all(visited[1:])

    # If all nodes are visited, return 1 for this strongly connected component
    if comp:
        return 1

    # Initialize a counter 'count' to store the size of the strongly connected component
    count = 0
    # Iterate through the neighbors of the current node 'v'
    for ne in e[v]:
        # If the neighbor is already visited, skip it
        if visited[ne]:
            continue
        # Mark the neighbor as visited
        visited[ne] = True
        # Recursively call 'dfs' on the neighbor and add its size to the counter
        rst = dfs(ne, visited)
        count += rst
        # Mark the neighbor as unvisited
        visited[ne] = False
    # Return the size of the strongly connected component
    return count

# Function 'main' to read input and call the 'print_edge' and 'dfs' functions
def main():
    global n, m, e
    # Read the number of nodes and edges from the standard input
    n, m = map(int, input().split())

    # Initialize a 2D list 'e' of size (n+1)x(n+1) to store the edges of the graph
    e = [[] for _ in range(n + 1)]

    # Read the edges of the graph from the standard input and add them to the 'e' list
    for _ in range(m):
        a, b = map(int, input().split())
        # Add the edge to the 'e' list for both nodes
        e[a].append(b)
        e[b].append(a)

    # Call the 'print_edge' function to print the edges of the graph
    # print_edge(e)

    # Initialize a list 'visited' of size (n+1) to keep track of visited nodes
    visited = [False] * (n + 1)
    # Mark the first node as visited
    visited[1] = True
    # Call the 'dfs' function on the first node and print the size of the strongly connected component
    count = dfs(1, visited)
    print(count)

# Call the 'main' function
main()
