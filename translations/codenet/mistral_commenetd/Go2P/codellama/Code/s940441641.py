
import sys
from collections import deque

# Function to read a single integer from standard input
def ReadInt():
    return int(sys.stdin.readline().strip())

# Function to read a single string from standard input
def ReadString():
    return sys.stdin.readline().strip()

# Function to read multiple integers from standard input
def ReadInts(n):
    return [int(x) for x in sys.stdin.readline().strip().split()]

# Function to read the initial dimensions and number of moves from standard input
def ReadInput():
    H, W, K = ReadInts(3)
    x1, y1, x2, y2 = ReadInts(4)
    x1, y1 = y1, x1
    x2, y2 = y2, x2
    return H, W, K, x1, y1, x2, y2

# Function to read the input grid from standard input
def ReadGrid(H, W):
    c = []
    for y in range(H):
        c.append(ReadString())
    return c

# Function to calculate the index of a cell in the grid based on its position and direction
def toID(x, y, dir):
    return 4 * (W * y + x) + dir

# Function to extract the position and direction from the index of a cell
def splatID(id):
    x = id % W
    y = id // W
    dir = id % 4
    return x, y, dir

# Function to initialize the distances to all cells to infinity and add the starting cell to the heap
def initDist(H, W, K, x1, y1, x2, y2):
    global dist
    dist = [float('inf')] * (W * H * 4)
    for i in range(4):
        q.append((0, toID(x1, y1, i)))

# Function to process the heap until the goal cell is reached or all cells have been visited
def processHeap():
    global dist
    while q:
        now = q.popleft()
        x, y, dir = splatID(now[1])
        if x == x2 and y == y2:
            break
        if dist[now[1]] <= now[0]:
            continue
        dist[now[1]] = now[0]
        for i in range(4):
            nCost = now[0] + K
            nID = toID(x, y, i)
            if dist[nID] <= nCost:
                continue
            q.append((nCost, nID))
        nx = x + dx[dir]
        ny = y + dy[dir]
        if 0 <= nx < W and 0 <= ny < H:
            nCost = now[0] + 1
            nID = toID(nx, ny, dir)
            if dist[nID] <= nCost:
                continue
            q.append((nCost, nID))

# Function to calculate the minimum number of moves to reach the goal cell
def calculateAnswer():
    global dist
    ans = float('inf')
    for i in range(4):
        id = toID(x2, y2, i)
        if dist[id] < ans:
            ans = dist[id]
    return ans

# Function to print the result
def printResult():
    if ans < float('inf'):
        print(ans)
    else:
        print(-1)

# Global variables
H, W, K, x1, y1, x2, y2 = ReadInput()
c = ReadGrid(H, W)
q = deque()
dist = []
ans = float('inf')

# Constants
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

# Main function
initDist(H, W, K, x1, y1, x2, y2)
processHeap()
ans = calculateAnswer()
printResult()

# END-OF-CODE
