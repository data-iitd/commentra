import sys
import heapq

INF = 1 << 60

def main():
	H, W, K = map(int, sys.stdin.readline().split())
	c = [sys.stdin.readline().strip() for _ in range(H)]
	x1, y1, x2, y2 = map(int, sys.stdin.readline().split())
	x1, y1 = y1, x1
	x2, y2 = y2, x2
	dx = [1, 0, -1, 0]
	dy = [0, 1, 0, -1]

	def toID(x, y, dir):
		return 4*(W*y+x) + dir

	def splatID(id):
		return id / 4 % W, id / 4 / W, id % 4

	dist = [INF] * (W*H*4)
	for i in range(W*H*4):
		dist[i] = INF

	q = []
	for i in range(4):
		q.append((0, toID(x1, y1, i)))
	heapq.heapify(q)
	while len(q) > 0:
		now = heapq.heappop(q)
		x, y, dir = splatID(now[1])
		if c[y][x] == '@':
			continue
		if dist[now[1]] <= now[0]:
			continue
		dist[now[1]] = now[0]
		if x == x2 and y == y2:
			break
		for i in range(4):
			nCost = (now[0] + K - 1) / K * K
			nID = toID(x, y, i)
			if dist[nID] <= nCost:
				continue
			heapq.heappush(q, (nCost, nID))
		nx = x + dx[dir]
		ny = y + dy[dir]
		if 0 <= nx and nx < W and 0 <= ny and ny < H:
			nCost = now[0] + 1
			nID = toID(nx, ny, dir)
			if dist[nID] <= nCost:
				continue
			heapq.heappush(q, (nCost, nID))
	ans = INF
	for i in range(4):
		id = toID(x2, y2, i)
		if dist[id] < ans:
			d2 = (dist[id] + K - 1) / K
			if d2 < ans:
				ans = d2
	if ans < INF:
		print ans
	else:
		print -1

main()

