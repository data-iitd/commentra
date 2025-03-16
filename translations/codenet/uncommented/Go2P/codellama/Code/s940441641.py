
import sys
import heapq

def main():
    H, W, K = map(int, sys.stdin.readline().split())
    x1, y1, x2, y2 = map(int, sys.stdin.readline().split())
    x1, y1 = y1, x1
    x2, y2 = y2, x2
    c = [sys.stdin.readline().rstrip() for _ in range(H)]

    dx = [1, 0, -1, 0]
    dy = [0, 1, 0, -1]

    toID = lambda x, y, dir: 4 * (W * y + x) + dir
    splatID = lambda id: id // 4 % W, id // 4 // W, id % 4

    dist = [float('inf')] * (W * H * 4)
    q = []
    for i in range(4):
        q.append(State(0, toID(x1, y1, i)))
    while q:
        now = heapq.heappop(q)
        x, y, dir = splatID(now.id)
        if c[y][x] == '@':
            continue
        if dist[now.id] <= now.cost:
            continue
        dist[now.id] = now.cost
        if x == x2 and y == y2:
            break
        for i in range(4):
            nCost = (now.cost + K - 1) // K * K
            nID = toID(x, y, i)
            if dist[nID] <= nCost:
                continue
            heapq.heappush(q, State(nCost, nID))
        nx = x + dx[dir]
        ny = y + dy[dir]
        if 0 <= nx < W and 0 <= ny < H:
            nCost = now.cost + 1
            nID = toID(nx, ny, dir)
            if dist[nID] <= nCost:
                continue
            heapq.heappush(q, State(nCost, nID))
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

class State:
    def __init__(self, cost, id):
        self.cost = cost
        self.id = id

    def __lt__(self, other):
        return self.cost < other.cost

    def __eq__(self, other):
        return self.cost == other.cost

    def __str__(self):
        return f'State({self.cost}, {self.id})'

if __name__ == '__main__':
    main()

