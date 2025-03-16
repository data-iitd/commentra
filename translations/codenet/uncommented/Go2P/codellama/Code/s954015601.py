// 深さ優先探索
import sys

def genid(a, b):
    if b < a:
        a, b = b, a
    return a * 100000 + b

def main():
    N = int(sys.stdin.readline().rstrip())

    ab = []
    edges = [[] for _ in range(N)]
    for i in range(N - 1):
        a, b = map(int, sys.stdin.readline().split())
        ab.append([a - 1, b - 1])
        edges[a - 1].append(b - 1)
        edges[b - 1].append(a - 1)

    colors = {}
    q = []
    q.append([0, -1, -1])
    while len(q) > 0:
        currentNode, usedColor, parentNode = q.pop()
        color = 1
        for childNode in edges[currentNode]:
            if childNode == parentNode:
                continue
            if color == usedColor:
                color += 1
            colors[genid(currentNode, childNode)] = color
            q.append([childNode, color, currentNode])
            color += 1

    K = -1
    for i in range(N):
        t = len(edges[i])
        if t > K:
            K = t
    print(K)

    for i in range(N - 1):
        print(colors[genid(ab[i][0], ab[i][1])])

