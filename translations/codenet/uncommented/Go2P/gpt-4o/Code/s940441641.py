import sys
import heapq

Inf = 1 << 60

def read_int():
    return int(sys.stdin.readline().strip())

def read_string():
    return sys.stdin.readline().strip()

def to_id(x, y, dir):
    return 4 * (W * y + x) + dir

def splat_id(id):
    return id // 4 % W, id // 4 // W, id % 4

class State:
    def __init__(self, cost, id):
        self.cost = cost
        self.id = id

    def __lt__(self, other):
        return self.cost < other.cost

H = read_int()
W = read_int()
K = read_int()
x1, y1, x2, y2 = read_int() - 1, read_int() - 1, read_int() - 1, read_int() - 1
x1, y1 = y1, x1
x2, y2 = y2, x2

c = [read_string() for _ in range(H)]

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

dist = [Inf] * (W * H * 4)
q = []

for i in range(4):
    heapq.heappush(q, State(0, to_id(x1, y1, i)))

while q:
    now = heapq.heappop(q)
    x, y, dir = splat_id(now.id)
    if c[y][x] == '@':
        continue
    if dist[now.id] <= now.cost:
        continue
    dist[now.id] = now.cost
    if x == x2 and y == y2:
        break
    for i in range(4):
        n_cost = (now.cost + K - 1) // K * K
        n_id = to_id(x, y, i)
        if dist[n_id] <= n_cost:
            continue
        heapq.heappush(q, State(n_cost, n_id))
    nx = x + dx[dir]
    ny = y + dy[dir]
    if 0 <= nx < W and 0 <= ny < H:
        n_cost = now.cost + 1
        n_id = to_id(nx, ny, dir)
        if dist[n_id] <= n_cost:
            continue
        heapq.heappush(q, State(n_cost, n_id))

ans = Inf
for i in range(4):
    id = to_id(x2, y2, i)
    if dist[id] < ans:
        d2 = (dist[id] + K - 1) // K
        if d2 < ans:
            ans = d2

if ans < Inf:
    print(ans)
else:
    print(-1)

# <END-OF-CODE>
