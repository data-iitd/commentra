
import sys

N, M = map(int, sys.stdin.readline().split())

INF = 1 << 62

# ここにコストをいれる　その地点にいくまでのこすとを考える
dist = [INF] * N

dist[0] = 0  # 最初は0にいるので

for loop in range(N):
    for i in range(M):
        if dist[a[i] - 1] == INF:
            continue
        if dist[b[i] - 1] > dist[a[i] - 1] + c[i]:
            # dist[b[i]-1]の行くまでがdist[a[i]-1] + cos　よりもかかるなら最小のほうにする
            dist[b[i] - 1] = dist[a[i] - 1] + c[i]

ans = dist[N - 1]  # 最小値が存在する場合はansが答え
navigate = [False] * N

for loop in range(N):
    for i in range(M):
        if dist[a[i] - 1] == INF:
            continue
        if dist[b[i] - 1] > dist[a[i] - 1] + c[i]:
            dist[b[i] - 1] = dist[a[i] - 1] + c[i]
            navigate[b[i] - 1] = True
        if navigate[a[i] - 1]:
            navigate[b[i] - 1] = True

if navigate[N - 1]:
    print("inf")
else:
    print(-ans)

