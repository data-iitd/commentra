
# 幅優先探索
import sys
from collections import deque

# genidは2つの頂点間の辺を一意に識別するには便利な関数です。
def genid(a, b):
    if b < a:
        a, b = b, a
    return a * 100000 + b

def main():
    # 頂点数Nを標準入力からread
    N = int(input())

    # 辺の情報をreadし、隣接リストを初期化
    ab = [list(map(lambda x: int(x) - 1, input().split())) for _ in range(N - 1)]
    edges = [[] for _ in range(N)]
    for a, b in ab:
        edges[a].append(b)
        edges[b].append(a)

    # 各辺の色を格納するmapと、幅優先探索での訪問を管理するqueueを初期化
    colors = {}
    q = deque([(0, -1, -1)])
    while q:
        # 最後にpushした要素をpop
        currentNode, usedColor, parentNode = q.pop()
        color = 1
        for childNode in edges[currentNode]:
            if childNode == parentNode:
                continue
            if color == usedColor:
                color += 1
            colors[genid(currentNode, childNode)] = color
            q.appendleft((childNode, color, currentNode))
            color += 1

    # 各頂点の次数のうち、大きいほうをKとする
    K = max(len(edges[i]) for i in range(N))
    print(K)

    # 辺の色をprint
    for a, b in ab:
        print(colors[genid(a, b)])

if __name__ == '__main__':
    main()

