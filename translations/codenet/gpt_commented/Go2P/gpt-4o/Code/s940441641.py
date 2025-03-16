import sys
import heapq

Inf = float('inf')  # Define a constant for infinity

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

# Read the dimensions of the grid and the cost parameter
H = read_int()
W = read_int()
K = read_int()
# Read the starting and ending coordinates, adjusting for 0-based indexing
x1, y1, x2, y2 = read_int() - 1, read_int() - 1, read_int() - 1, read_int() - 1
x1, y1 = y1, x1  # Swap x and y for the starting point
x2, y2 = y2, x2  # Swap x and y for the ending point

# Read the grid representation
c = [read_string() for _ in range(H)]

# Define movement directions (right, down, left, up)
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

# Initialize the distance array with infinity
dist = [Inf] * (W * H * 4)

# Initialize the priority queue (min-heap) with starting states
q = []
for i in range(4):
    heapq.heappush(q, State(0, to_id(x1, y1, i)))

# Main loop for Dijkstra's algorithm
while q:
    now = heapq.heappop(q)  # Get the state with the lowest cost
    x, y, dir = splat_id(now.id)  # Decompose the ID into coordinates and direction

    # Skip if the current position is a wall
    if c[y][x] == '@':
        continue
    # Skip if we have already found a better cost for this state
    if dist[now.id] <= now.cost:
        continue
    # Update the distance for the current state
    dist[now.id] = now.cost

    # If we reached the destination, exit the loop
    if x == x2 and y == y2:
        break

    # Explore all four possible directions
    for i in range(4):
        n_cost = (now.cost + K - 1) // K * K  # Calculate the new cost
        n_id = to_id(x, y, i)  # Get the new ID for the direction
        if dist[n_id] <= n_cost:  # Skip if we have a better cost
            continue
        # Push the new state into the priority queue
        heapq.heappush(q, State(n_cost, n_id))

    # Move in the current direction
    nx = x + dx[dir]
    ny = y + dy[dir]
    # Check if the new position is within bounds
    if 0 <= nx < W and 0 <= ny < H:
        n_cost = now.cost + 1  # Increment the cost for moving forward
        n_id = to_id(nx, ny, dir)  # Get the new ID for the position
        if dist[n_id] <= n_cost:  # Skip if we have a better cost
            continue
        # Push the new state into the priority queue
        heapq.heappush(q, State(n_cost, n_id))

# Determine the minimum cost to reach the destination
ans = Inf
for i in range(4):
    id = to_id(x2, y2, i)  # Get the ID for the destination in each direction
    if dist[id] < ans:  # Check if we found a better cost
        d2 = (dist[id] + K - 1) // K  # Calculate the cost in terms of K
        if d2 < ans:  # Update the answer if it's better
            ans = d2

# Output the result
if ans < Inf:
    print(ans)  # Print the minimum cost
else:
    print(-1)  # Print -1 if the destination is unreachable

# <END-OF-CODE>
