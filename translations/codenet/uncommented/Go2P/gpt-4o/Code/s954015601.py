# 深さ優先探索
import sys
from collections import defaultdict

def genid(a, b):
    if b < a:
        a, b = b, a
    return a * 100000 + b

def read_int():
    return int(sys.stdin.readline().strip())

def main():
    N = read_int()

    ab = [None] * (N - 1)
    edges = defaultdict(list)
    for i in range(N - 1):
        a = read_int() - 1
        b = read_int() - 1
        ab[i] = (a, b)
        edges[a].append(b)
        edges[b].append(a)

    colors = {}
    q = [(0, -1, -1)]  # (currentNode, usedColor, parentNode)
    while q:
        currentNode, usedColor, parentNode = q.pop()
        color = 1
        for childNode in edges[currentNode]:
            if childNode == parentNode:
                continue
            if color == usedColor:
                color += 1
            colors[genid(currentNode, childNode)] = color
            q.append((childNode, color, currentNode))
            color += 1

    K = -1
    for i in range(N):
        t = len(edges[i])
        if t > K:
            K = t
    print(K)

    for i in range(N - 1):
        print(colors[genid(ab[i][0], ab[i][1])])

if __name__ == "__main__":
    main()

# <END-OF-CODE>
