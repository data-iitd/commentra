import sys
import heapq

Inf = float('inf')

# Function to read a single integer from standard input
def read_int():
    return int(sys.stdin.readline().strip())

# Function to read a single string from standard input
def read_string():
    return sys.stdin.readline().strip()

# Function to read multiple integers from standard input
def read_ints(n):
    return list(map(int, sys.stdin.readline().strip().split()))

# Function to read the initial dimensions and number of moves from standard input
def read_input():
    H, W, K = read_ints(3)
    x1, y1, x2, y2 = read_ints(4)
    x1, y1 = y1 - 1, x1 - 1
    x2, y2 = y2 - 1, x2 - 1
    return H, W, K, x1, y1, x2, y2

# Function to read the input grid from standard input
def read_grid(H, W):
    return [read_string() for _ in range(H)]

# Function to calculate the index of a cell in the grid based on its position and direction
def to_id(x, y, dir, W):
    return 4 * (W * y + x) + dir

# Function to extract the position and direction from the index of a cell
def splat_id(id, W):
    x = id % W
    y = id // W
    dir = id % 4
    return x, y, dir

# Function to initialize the distances and add the starting cell to the heap
def init_dist(H, W, K, x1, y1):
    dist = [Inf] * (W * H * 4)
    q = []
    for i in range(4):
        heapq.heappush(q, (0, to_id(x1, y1, i, W)))
    return dist, q

# Constants to represent the possible directions of movement
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

def main():
    # Read the input dimensions, number of moves, and starting and ending positions
    H, W, K, x1, y1, x2, y2 = read_input()

    # Read the input grid
    grid = read_grid(H, W)

    # Initialize the distances and add the starting cell to the heap
    dist, q = init_dist(H, W, K, x1, y1)

    # Process the heap until the goal cell is reached or all cells have been visited
    while q:
        now_cost, now_id = heapq.heappop(q)
        x, y, dir = splat_id(now_id, W)

        # If the current cell is the goal cell, break the loop
        if x == x2 and y == y2:
            break

        # If the current cell has already been visited, continue to the next cell
        if dist[now_id] <= now_cost:
            continue

        # Update the distance to the current cell and add its neighbors to the heap
        dist[now_id] = now_cost
        for i in range(4):
            n_cost = now_cost + K
            n_id = to_id(x, y, i, W)
            if dist[n_id] <= n_cost:
                continue
            heapq.heappush(q, (n_cost, n_id))

        # Move to the next neighbor and repeat the process
        nx = x + dx[dir]
        ny = y + dy[dir]
        if 0 <= nx < W and 0 <= ny < H:
            n_cost = now_cost + 1
            n_id = to_id(nx, ny, dir, W)
            if dist[n_id] <= n_cost:
                continue
            heapq.heappush(q, (n_cost, n_id))

    # Calculate the minimum number of moves to reach the goal cell
    ans = Inf
    for i in range(4):
        id = to_id(x2, y2, i, W)
        if dist[id] < ans:
            ans = dist[id]

    # Print the result
    if ans < Inf:
        print(ans)
    else:
        print(-1)

if __name__ == "__main__":
    main()
# <END-OF-CODE>
