import sys
import heapq

Inf = float('inf')

def read_int():
    return int(sys.stdin.readline().strip())

def read_string():
    return sys.stdin.readline().strip()

def main():
    H, W, K = read_int(), read_int(), read_int()  # Reading the dimensions of the grid and the number of obstacles.
    x1, y1, x2, y2 = read_int() - 1, read_int() - 1, read_int() - 1, read_int() - 1  # Reading the starting and ending coordinates.
    x1, y1 = y1, x1  # Adjusting the coordinates for the grid's indexing.
    x2, y2 = y2, x2  # Adjusting the coordinates for the grid's indexing.
    c = [read_string() for _ in range(H)]  # Reading each row of the grid.

    dx = [1, 0, -1, 0]  # Defining the possible horizontal directions.
    dy = [0, 1, 0, -1]  # Defining the possible vertical directions.

    # Conversion function to get the ID of a state based on its coordinates and direction.
    def to_id(x, y, dir):
        return 4 * (W * y + x) + dir

    # Conversion function to split the ID back into coordinates and direction.
    def splat_id(id):
        return id // 4 % W, id // 4 // W, id % 4

    dist = [Inf] * (W * H * 4)  # Initializing the distance array.

    q = []  # Initializing the priority queue.
    for i in range(4):
        heapq.heappush(q, (0, to_id(x1, y1, i)))  # Starting from all possible directions at the initial position.

    while q:  # Processing each state in the priority queue.
        now_cost, now_id = heapq.heappop(q)  # Getting the state with the minimum cost.
        x, y, dir = splat_id(now_id)  # Splitting the ID back into coordinates and direction.
        if c[y][x] == '@':  # Skipping if the current cell is an obstacle.
            continue
        if dist[now_id] <= now_cost:  # Skipping if the current cost is not the minimum.
            continue
        dist[now_id] = now_cost  # Updating the minimum cost to reach this state.
        if x == x2 and y == y2:  # Breaking if the end is reached.
            break
        for i in range(4):  # Considering all possible directions.
            n_cost = (now_cost + K - 1) // K * K  # Calculating the cost to the next state.
            n_id = to_id(x, y, i)  # Getting the ID of the next state.
            if dist[n_id] <= n_cost:  # Skipping if the next state has been processed with a lower cost.
                continue
            heapq.heappush(q, (n_cost, n_id))  # Pushing the next state into the priority queue.

        nx, ny = x + dx[dir], y + dy[dir]  # Calculating the next x and y coordinates.
        if 0 <= nx < W and 0 <= ny < H:  # Checking if the next position is within the grid.
            n_cost = now_cost + 1  # Calculating the cost to move to the next position.
            n_id = to_id(nx, ny, dir)  # Getting the ID of the next position.
            if dist[n_id] <= n_cost:  # Skipping if the next position has been processed with a lower cost.
                continue
            heapq.heappush(q, (n_cost, n_id))  # Pushing the next position into the priority queue.

    ans = Inf  # Initializing the answer with infinity.
    for i in range(4):
        id = to_id(x2, y2, i)  # Getting the ID of the end position from each direction.
        if dist[id] < ans:  # Updating the answer if a new minimum cost is found.
            d2 = (dist[id] + K - 1) // K  # Calculating the minimum number of obstacles to overcome.
            if d2 < ans:
                ans = d2

    if ans < Inf:  # Outputting the result.
        print(ans)
    else:
        print(-1)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
