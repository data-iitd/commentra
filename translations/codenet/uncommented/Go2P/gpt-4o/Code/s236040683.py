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
    N, M = map(int, sys.stdin.readline().strip().split())
    nodes = [Node() for _ in range(N)]
    
    for _ in range(M):
        from_node, to_node = map(int, sys.stdin.readline().strip().split())
        nodes[from_node - 1].to.append(to_node - 1)
        nodes[to_node - 1].to.append(from_node - 1)

    for i in range(N):
        out(len(nodes[i].to))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
