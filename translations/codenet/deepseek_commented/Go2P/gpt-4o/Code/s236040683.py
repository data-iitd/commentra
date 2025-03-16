import sys

def out(*args):
    print(*args)

def get_int():
    return int(sys.stdin.readline().strip())

def get_string():
    return sys.stdin.readline().strip()

class Node:
    def __init__(self):
        self.to = []

def main():
    # Read the number of nodes (N) and the number of edges (M)
    N, M = map(int, sys.stdin.readline().strip().split())

    # Initialize a list of Node with N elements
    n = [Node() for _ in range(N)]

    # Read M pairs of edges and populate the adjacency list for each node
    for _ in range(M):
        from_node, to_node = map(int, sys.stdin.readline().strip().split())
        n[from_node - 1].to.append(to_node - 1)
        n[to_node - 1].to.append(from_node - 1)

    # Print the size of the adjacency list for each node
    for i in range(N):
        out(len(n[i].to))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
