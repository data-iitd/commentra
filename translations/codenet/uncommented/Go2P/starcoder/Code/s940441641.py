import sys
from collections import deque

H, W, K = map(int, input().split())
x1, y1, x2, y2 = map(int, input().split())
x1, y1 = y1, x1
x2, y2 = y2, x2
c = [input() for _ in range(H)]

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

def toID(x, y, dir):
	return 4*(W*y+x) + dir

def splatID(id):
	return id // 4 % W, id // 4 // W, id % 4

dist = [float('inf')] * (W*H*4)

q = []
for i in range(4):
	q.append((0, toID(x1, y1, i)))

while len(q) > 0:
	cost, now = heapq.heappop(q)
	if dist[now] <= cost:
		continue
	dist[now] = cost
	if splatID(now)[0] == x2 and splatID(now)[1] == y2:
		break
	for i in range(4):
		nCost = (cost + K - 1) // K * K
		nID = toID(*splatID(now), i)
		if dist[nID] <= nCost:
			continue
		heapq.heappush(q, (nCost, nID))
	nx, ny = splatID(now)[0] + dx[splatID(now)[2]], splatID(now)[1] + dy[splatID(now)[2]]
	if 0 <= nx and nx < W and 0 <= ny and ny < H:
		nCost = cost + 1
		nID = toID(nx, ny, splatID(now)[2])
		if dist[nID] <= nCost:
			continue
		heapq.heappush(q, (nCost, nID))

ans = float('inf')
for i in range(4):
	id = toID(x2, y2, i)
	if dist[id] < ans:
		d2 = (dist[id] + K - 1) // K
		if d2 < ans:
			ans = d2

if ans < float('inf'):
	print(ans)
else:
	print(-1)

# 