import sys

# Set the maximum recursion limit to a high value
sys.setrecursionlimit(1 << 25)

# Define input reading functions
readline = sys.stdin.buffer.readline
read = sys.stdin.readline  # Use this for reading strings
ra = range
enu = enumerate

# Custom exit function to print a message and exit the program
def exit(*argv, **kwarg):
    print(*argv, **kwarg)
    sys.exit()

# Function to subtract a value from all elements in the input
def mina(*argv, sub=1): 
    return list(map(lambda x: x - sub, argv))  # Subtract 'sub' from all arguments

# Function to read a single integer from input
def a_int(): 
    return int(readline())

# Function to read a list of integers from input
def ints(): 
    return list(map(int, readline().split()))

# Function to read columns of integers from input
def read_col(H):
    '''H is number of rows
    This function reads H rows of input and returns them as columns.'''
    ret = []
    for _ in range(H):
        ret.append(list(map(int, readline().split())))
    return tuple(map(list, zip(*ret)))  # Transpose the list of rows to columns

# Function to read a grid map and replace characters with integers
def read_map_as(H, replace={'#': 1, '.': 0}, pad=None):
    '''
    Reads a string map and replaces characters based on the 'replace' dictionary.
    Default replacements are '#' -> 1 and '.' -> 0.
    '''
    if pad is None:
        ret = []
        for _ in range(H):
            ret.append([replace[s] for s in read()[:-1]])  # Read and replace characters
    else:  # If padding is specified
        ret = [[pad] * (W + 2)]  # Create a padded row
        for _ in range(H):
            ret.append([pad] + [replace[s] for s in read()[:-1]] + [pad])  # Pad the sides
        ret.append([pad] * (W + 2))  # Add a padded row at the bottom

    return ret  # Return the constructed grid

# Function to perform Dijkstra's algorithm on a grid
def grid_dijkstra(grid, si: int, sj: int):
    '''Applies Dijkstra's algorithm on the grid.
    grid contains the costs to enter each cell.
    si, sj are the starting coordinates.'''
    from heapq import heappop, heappush
    H = len(grid)
    W = len(grid[0])
    D = [[-1] * W for _ in [0] * H]  # Initialize distances with -1 (infinity)
    que = [(0, si, sj)]  # Priority queue for Dijkstra's algorithm

    while que:
        c, i, j = heappop(que)  # Get the cell with the lowest cost
        if D[i][j] != -1:  # If already visited, skip
            continue
        D[i][j] = c  # Set the cost to reach this cell

        # Explore neighboring cells
        for di, dj in product([-2, -1, 0, 1, 2], repeat=2):
            ni, nj = i + di, j + dj  # Calculate neighbor coordinates
            # Check if the neighbor is valid and not visited
            if not (0 <= ni < H and 0 <= nj < W) or D[ni][nj] != -1 or ni == nj == 0 or grid[ni][nj] == 1:
                continue
            # Determine cost to move to the neighbor
            if (di == 0 and abs(dj) == 1) or (dj == 0 and abs(di) == 1):  # Walking
                nc = c
            else:  # Warping
                nc = c + 1
            heappush(que, (nc, ni, nj))  # Add neighbor to the queue with its cost

    return D  # Return the distance grid

# Constants for the problem
MOD = 10**9 + 7
INF = 2**31  # Represents infinity

# Default imports for combinatorial operations
from itertools import product, permutations, combinations
from collections import deque

# Read dimensions of the grid
H, W = ints()
# Read starting coordinates and adjust them
si, sj = mina(*ints())
# Read target coordinates and adjust them
ti, tj = mina(*ints())

# Read the grid map
S = read_map_as(H)

# Initialize distance grid for BFS
D = [[-1] * W for _ in [0] * H]  # -1 indicates unvisited
que = deque([(0, si, sj)])  # Initialize deque for BFS

# Perform BFS to calculate minimum costs
while que:
    c, i, j = que.popleft()  # Get the current cell
    if D[i][j] != -1:  # If already visited, skip
        continue
    D[i][j] = c  # Set the cost to reach this cell

    # Explore neighboring cells
    for di, dj in product([-2, -1, 0, 1, 2], repeat=2):
        ni, nj = i + di, j + dj  # Calculate neighbor coordinates
        # Check if the neighbor is valid and not visited
        if not (0 <= ni < H and 0 <= nj < W) or D[ni][nj] != -1 or ni == nj == 0 or S[ni][nj] == 1:
            continue
        # Determine cost to move to the neighbor
        if (di == 0 and abs(dj) == 1) or (dj == 0 and abs(di) == 1):  # Walking
            que.appendleft((c, ni, nj))  # Prioritize walking
        else:  # Warping
            que.append((c + 1, ni, nj))  # Lower priority for warping

# Output the minimum cost to reach the target coordinates
print(D[ti][tj])
# Uncomment to print the entire distance grid for debugging
# print(*D, sep='\n')

# Note: Consider using union-find to extract connected components and handle crossing components with DFS.
