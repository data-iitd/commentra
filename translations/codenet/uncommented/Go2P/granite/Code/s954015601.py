
# 幅優先探索
import sys

def genid(a, b):
    if b < a:
        a, b = b, a
    return a*100000 + b

def main():
    N = int(input())

    ab = []
    for i in range(N-1):
        a = int(input()) - 1
        b = int(input()) - 1
        ab.append((a, b))

    edges = [[] for _ in range(N)]
    for a, b in ab:
        edges[a].append(b)
        edges[b].append(a)

    colors = {}
    q = [(0, -1, -1)]
    while len(q)!= 0:
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

    K = max(len(edges[i]) for i in range(N))
    print(K)

    for a, b in ab:
        print(colors[genid(a, b)])

if __name__ == "__main__":
    main()
