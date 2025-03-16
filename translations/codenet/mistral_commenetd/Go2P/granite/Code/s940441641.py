

import heapq

def read_int():
    return int(input())

def read_ints(n):
    return list(map(int, input().split()))

def read_grid(H, W):
    return [input() for _ in range(H)]

def to_id(x, y, dir):
    return 4 * (W * y + x) + dir

def splat_id(id):
    x = id % W
    y = id // W
    dir = id % 4
    return x, y, dir

def process_heap():
    while q:
        now = heapq.heappop(q)
        x, y, dir = splat_id(now.id)

        if x == x2 and y == y2:
            break

        if dist[now.id] <= now.cost:
            continue

        dist[now.id] = now.cost
        for i in range(4):
            n_cost = now.cost + K
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

def calculate_answer():
    ans = float('inf')
    for i in range(4):
        id = to_id(x2, y2, i)
        if dist[id] < ans:
            ans = dist[id]
    return ans

def main():
    global dist, q, H, W, K, x1, y1, x2, y2
    H, W, K, x1, y1, x2, y2 = read_ints(8)
    c = read_grid(H, W)
    dist = [float('inf')] * (W * H * 4)
    q = []
    for i in range(4):
        q.append(State(0, to_id(x1, y1, i)))
    process_heap()
    ans = calculate_answer()
    print(ans)

if __name__ == '__main__':
    main()

