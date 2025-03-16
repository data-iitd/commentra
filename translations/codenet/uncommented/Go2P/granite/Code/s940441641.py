
import heapq

H, W, K = map(int, input().split())
x1, y1, x2, y2 = map(int, input().split())
x1, y1 = y1, x1
x2, y2 = y2, x2
c = [input() for _ in range(H)]

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

def to_id(x, y, dir):
    return 4 * (W * y + x) + dir

def splat_id(id):
    return id // 4 % W, id // 4 // W, id % 4

dist = [[float('inf')] * 4 for _ in range(H * W)]
for i in range(4):
    dist[to_id(x1, y1, i)][i] = 0

q = []
for i in range(4):
    heapq.heappush(q, (0, to_id(x1, y1, i)))

while q:
    cost, id = heapq.heappop(q)
    if cost > dist[id]:
        continue
    x, y, dir = splat_id(id)
    if c[y][x] == '@':
        continue
    for i in range(4):
        n_cost = (cost + K - 1) // K * K
        n_id = to_id(x, y, i)
        if n_cost < dist[n_id][i]:
            dist[n_id][i] = n_cost
            heapq.heappush(q, (n_cost, n_id))
    nx = x + dx[dir]
    ny = y + dy[dir]
    if 0 <= nx < W and 0 <= ny < H:
        n_cost = cost + 1
        n_id = to_id(nx, ny, dir)
        if n_cost < dist[n_id][dir]:
            dist[n_id][dir] = n_cost
            heapq.heappush(q, (n_cost, n_id))

ans = float('inf')
for i in range(4):
    id = to_id(x2, y2, i)
    ans = min(ans, (dist[id][i] + K - 1) // K)

if ans < float('inf'):
    print(ans)
else:
    print(-1)
