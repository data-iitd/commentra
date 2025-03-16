import sys
from collections import defaultdict

def read_int():
    return int(sys.stdin.readline().strip())

def read_ints():
    return list(map(int, sys.stdin.readline().strip().split()))

def genid(a, b):
    return a * 100000 + b if a < b else b * 100000 + a

def main():
    N = read_int()
    edges = defaultdict(list)
    ab = []
    for _ in range(N - 1):
        a, b = read_ints()
        a -= 1
        b -= 1
        edges[a].append(b)
        edges[b].append(a)
        ab.append((a, b))

    colors = {}
    stack = [(0, -1, -1)]
    while stack:
        current_node, used_color, parent_node = stack[-1]
        stack.pop()
        color = 1
        for child_node in edges[current_node]:
            if child_node == parent_node:
                continue
            if color == used_color:
                color += 1
            colors[genid(current_node, child_node)] = color
            stack.append((child_node, color, current_node))
            color += 1

    K = max(len(neighbors) for neighbors in edges.values())
    print(K)

    for a, b in ab:
        print(colors[genid(a, b)])

if __name__ == "__main__":
    main()
