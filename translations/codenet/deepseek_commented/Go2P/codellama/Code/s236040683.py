
import sys

def out(x):
    print(x)

def getInt():
    return int(sys.stdin.readline())

def getString():
    return sys.stdin.readline().strip()

class Node:
    def __init__(self):
        self.to = []

def main():
    # Read the number of nodes (N) and the number of edges (M)
    N, M = getInt(), getInt()

    # Initialize a list of Node with N elements
    n = [Node() for _ in range(N)]

    # Read M pairs of edges and populate the adjacency list for each node
    for i in range(M):
        from, to = getInt()-1, getInt()-1
        n[from].to.append(to)
        n[to].to.append(from)

    # Print the size of the adjacency list for each node
    for i in range(N):
        out(len(n[i].to))

if __name__ == "__main__":
    main()

