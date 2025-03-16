
import heapq
import sys

def main():
    H, W, K = map(int, input().split())
    x1, y1, x2, y2 = map(lambda x: int(x) - 1, input().split())
    c = [input() for _ in range(H)]
    dx = [1, 0, -1, 0]
    dy = [0, 1, 0, -1]

    def to_id(x, y, dir):
        return 4 * (W * y + x) + dir

    def from_id(id):
        return id // 4 % W, id // 4 // W, id % 4

    def dijkstra():
        dist = [[float('inf')] * 4 for _ in range(H * W)]
        q = []
        for dir in range(4):
            heapq.heappush(q, (0, to_id(x1, y1, dir)))
        while q:
            cost, now_id = heapq.heappop(q)
            if dist[now_id // (W * H)][now_id % (W * H)] <= cost:
                continue
            x, y, dir = from_id(now_id)
            if c[y][x] == '@':
                continue
            dist[now_id // (W * H)][now_id % (W * H)] = cost
            for i in range(4):
                n_cost = (cost + K - 1) // K * K
                n_id = to_id(x, y, i)
                if dist[n_id // (W * H)][n_id % (W * H)] > n_cost:
                    heapq.heappush(q, (n_cost, n_id))
            nx, ny = x + dx[dir], y + dy[dir]
            if 0 <= nx < W and 0 <= ny < H:
                n_cost = cost + 1
                n_id = to_id(nx, ny, dir)
                if dist[n_id // (W * H)][n_id % (W * H)] > n_cost:
                    heapq.heappush(q, (n_cost, n_id))
        ans = float('inf')
        for dir in range(4):
            n_id = to_id(x2, y2, dir)
            if dist[n_id // (W * H)][n_id % (W * H)] < ans:
                d2 = (dist[n_id // (W * H)][n_id % (W * H)] + K - 1) // K
                if d2 < ans:
                    ans = d2
        if ans < float('inf'):
            print(ans)
        else:
            print(-1)

    dijkstra()

if __name__ == '__main__':
    main()

