
# 深さ優先探索
import sys

# 辺のIDを生成する
def genid(a, b):
    if b < a:
        a, b = b, a
    return a * 100000 + b

# 辺の色を格納する辞書
colors = {}

# スタック
q = []

# 頂点数
N = int(sys.stdin.readline())

# 辺のリスト
edges = [[] for i in range(N)]

# 辺のリストを作成する
for i in range(N - 1):
    a, b = map(int, sys.stdin.readline().split())
    ab = [a - 1, b - 1]
    edges[a - 1].append(b - 1)
    edges[b - 1].append(a - 1)

# 深さ優先探索
q.append([0, -1, -1])
while q:
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

# 最大度を求める
K = -1
for i in range(N):
    t = len(edges[i])
    if t > K:
        K = t

# 最大度を出力
print(K)

# 辺の色を出力
for i in range(N - 1):
    print(colors[genid(ab[i][0], ab[i][1])])

