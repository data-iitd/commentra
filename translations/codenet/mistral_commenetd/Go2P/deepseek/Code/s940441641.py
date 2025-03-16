import heapq
import sys

input = sys.stdin.readline
INF = 1 << 60

# Function to read a single integer from standard input
def read_int():
    return int(input())

# Function to read a single string from standard input
def read_string():
    return input().strip()

# Function to read multiple integers from standard input
def read_ints(n):
    return [int(input()) for _ in range(n)]

# Function to read the initial dimensions and number of moves from standard input
def read_input():
    H, W, K = map(int, input().split())
    x1, y1, x2, y2 = map(lambda x: int(x) - 1, input().split())
    return H, W, K, x1, y1, x2, y2

# Function to read the input grid from standard input
def read_grid(H, W):
    return [read_string() for _ in range(H)]

# Function to calculate the index of a cell in the grid based on its position and direction
def to_id(x, y, dir):
    return 4 * (W * y + x) + dir

# Function to calculate the index of a cell from its index
def splat_id(id):
    x = id % W
    y = id // W
    dir = id % 4
    return x, y, dir

# Global variable to store the distance from the starting cell to all other cells
dist = []

# Global variable to store the heap of states
q = []

# Function to initialize the distances to infinity and add the starting cell to the heap
def init_dist(H, W, K, x1, y1, x2, y2):
    global dist, q
    dist = [[INF] * 4 for _ in range(H * W)]
    for i in range(4):
        heapq.heappush(q, (0, x1, y1, i))

# Type to represent a state of the grid
class State:
    def __init__(self, cost, x, y, dir):
        self.cost = cost
        self.x = x
        self.y = y
        self.dir = dir

    def __lt__(self, other):
        return self.cost < other.cost

# Function to process the heap until the goal cell is reached or all cells have been visited
def process_heap():
    global dist, q
    while q:
        cost, x, y, dir = heapq.heappop(q)
        if cost > dist[y][x][dir]:
            continue
        dist[y][x][dir] = cost
        if x == x2 and y == y2:
            break
        for i in range(4):
            n_cost = cost + K
            n_id = to_id(x, y, i)
            if n_cost < dist[y][x][i]:
                heapq.heappush(q, (n_cost, x, y, i))
        nx, ny = x + dx[dir], y + dy[dir]
        if 0 <= nx < W and 0 <= ny < H:
            n_cost = cost + 1
            n_id = to_id(nx, ny, dir)
            if n_cost < dist[ny][nx][dir]:
                heapq.heappush(q, (n_cost, nx, ny, dir))

# Function to calculate the minimum number of moves to reach the goal cell
def calculate_answer():
    global dist, q
    ans = INF
    for i in range(4):
        ans = min(ans, dist[y2][x2][i])
    return ans

# Function to print the result
def print_result(ans):
    if ans < INF:
        print(ans)
    else:
        print(-1)

# Constants to represent the possible directions of movement
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

# Main function
def main():
    H, W, K, x1, y1, x2, y2 = read_input()
    grid = read_grid(H, W)
    init_dist(H, W, K, x1, y1, x2, y2)
    process_heap()
    ans = calculate_answer()
    print_result(ans)

if __name__ == "__main__":
    main()
