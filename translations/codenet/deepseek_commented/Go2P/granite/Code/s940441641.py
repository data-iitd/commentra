

import heapq

H, W, K = map(int, input().split())
x1, y1, x2, y2 = map(lambda x: int(x) - 1, input().split())
c = [input() for _ in range(H)]

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

def to_id(x, y, dir):
    return 4 * (W * y + x) + dir

def splat_id(id):
    return id // 4 % W, id // 4 // W, id % 4

dist = [[float('inf')] * 4 for _ in range(H * W)]

q = []
for i in range(4):
    heapq.heappush(q, (0, to_id(x1, y1, i)))

while q:
    cost, id = heapq.heappop(q)
    if dist[id] <= cost:
        continue
    x, y, dir = splat_id(id)
    if c[y][x] == '@':
        continue
    dist[id] = cost
    if x == x2 and y == y2:
        break
    for i in range(4):
        n_cost = (cost + K - 1) // K * K
        n_id = to_id(x, y, i)
        if dist[n_id] <= n_cost:
            continue
        heapq.heappush(q, (n_cost, n_id))
    nx = x + dx[dir]
    ny = y + dy[dir]
    if 0 <= nx < W and 0 <= ny < H:
        n_cost = cost + 1
        n_id = to_id(nx, ny, dir)
        if dist[n_id] <= n_cost:
            continue
        heapq.heappush(q, (n_cost, n_id))

ans = float('inf')
for i in range(4):
    id = to_id(x2, y2, i)
    if dist[id] < ans:
        d2 = (dist[id] + K - 1) // K
        ans = min(ans, d2)

if ans < float('inf'):
    print(ans)
else:
    print(-1)

