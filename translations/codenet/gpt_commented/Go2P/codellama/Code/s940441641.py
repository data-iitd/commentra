
import sys
import heapq

def main():
    # Read the dimensions of the grid and the cost parameter
    H, W, K = map(int, sys.stdin.readline().split())
    # Read the starting and ending coordinates, adjusting for 0-based indexing
    x1, y1, x2, y2 = map(int, sys.stdin.readline().split())
    x1, y1 = y1, x1 # Swap x and y for the starting point
    x2, y2 = y2, x2 # Swap x and y for the ending point

    # Read the grid representation
    c = [sys.stdin.readline().strip() for _ in range(H)]

    # Define movement directions (right, down, left, up)
    dx = [1, 0, -1, 0]
    dy = [0, 1, 0, -1]

    # Function to convert (x, y, dir) to a unique ID
    toID = lambda x, y, dir: 4*(W*y+x) + dir
    # Function to convert an ID back to (x, y, dir)
    splatID = lambda id: id / 4 % W, id / 4 / W, id % 4

    # Initialize the distance array with infinity
    dist = [float('inf')] * (W*H*4)

    # Initialize the priority queue (min-heap) with starting states
    q = []
    for i in range(4):
        q.append(State(
            cost=0,
            id=toID(x1, y1, i),
        ))

    # Main loop for Dijkstra's algorithm
    while len(q) > 0:
        now = q.pop(0) # Get the state with the lowest cost
        x, y, dir = splatID(now.id) # Decompose the ID into coordinates and direction

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
            nCost = (now.cost + K - 1) // K * K # Calculate the new cost
            nID = toID(x, y, i) # Get the new ID for the direction
            if dist[nID] <= nCost: # Skip if we have a better cost
                continue
            # Push the new state into the priority queue
            q.append(State(
                cost=nCost,
                id=nID,
            ))

        # Move in the current direction
        nx = x + dx[dir]
        ny = y + dy[dir]
        # Check if the new position is within bounds
        if 0 <= nx and nx < W and 0 <= ny and ny < H:
            nCost = now.cost + 1 # Increment the cost for moving forward
            nID = toID(nx, ny, dir) # Get the new ID for the position
            if dist[nID] <= nCost: # Skip if we have a better cost
                continue
            # Push the new state into the priority queue
            q.append(State(
                cost=nCost,
                id=nID,
            ))

    # Determine the minimum cost to reach the destination
    ans = float('inf')
    for i in range(4):
        id = toID(x2, y2, i) # Get the ID for the destination in each direction
        if dist[id] < ans: # Check if we found a better cost
            d2 = (dist[id] + K - 1) // K # Calculate the cost in terms of K
            if d2 < ans: # Update the answer if it's better
                ans = d2

    # Output the result
    if ans < float('inf'):
        print(ans) # Print the minimum cost
    else:
        print(-1) # Print -1 if the destination is unreachable

# Define a class for the state
class State:
    def __init__(self, cost, id):
        self.cost = cost
        self.id = id

    def __lt__(self, other):
        return self.cost < other.cost

# END-OF-CODE
