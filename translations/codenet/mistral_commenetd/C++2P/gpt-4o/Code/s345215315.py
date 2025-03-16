import sys
from collections import deque

# Constants
INF = 1e9
h, w = 19, 15
dx = [0, 1, 0, -1, 1, 1, -1, -1]
dy = [1, 0, -1, 0, 1, -1, 1, -1]

# Global variable
ans = INF
s = []

def gcd(a, b):
    # Function to find the greatest common divisor of two numbers
    while b:
        a, b = b, a % b
    return a

def lcm(a, b):
    # Function to find the least common multiple of two numbers
    return a // gcd(a, b) * b

# Function to perform a depth-first search from a given position
# with a given number of steps
def dfs(x, y, cnt):
    global ans
    # Base case: if the number of steps is greater than 20, return
    if cnt > 20:
        return

    # Check if the current position is the last row of the grid
    if x == h - 1:
        # Update the answer if the current number of steps is less than the previous answer
        ans = min(ans, cnt)
        return

    # Iterate through all the possible directions
    for i in range(8):
        nx, ny = x + dx[i], y + dy[i]

        # Check if the next position is out of the grid
        if nx < 0 or nx >= h or ny < 0 or ny >= w:
            continue

        # Check if the next position contains an 'X'
        if s[nx][ny] != 'X':
            continue

        # Perform a depth-first search from the next position with one more step
        c = True
        while c and s[nx][ny] == 'X':
            s[nx][ny] = '.'
            nx += dx[i]
            ny += dy[i]
            if nx < 0 or nx >= h or ny < 0 or ny >= w:
                if nx >= h:
                    ans = min(ans, cnt + 1)
                c = False

        # If the loop did not exit due to an out-of-grid position, perform the depth-first search
        if c:
            dfs(nx, ny, cnt + 1)

        # Backtrack by restoring the previous state of the grid
        while nx != x or ny != y:
            nx -= dx[i]
            ny -= dy[i]
            s[nx][ny] = 'X'

        # Restore the current position of the 'O'
        s[x][y] = '.'

# Main function
if __name__ == "__main__":
    # Initialize the 2D vector to store the grid
    for _ in range(h):
        s.append(list(input().strip()))

    # Find the position of the 'O'
    sx, sy = -1, -1
    for i in range(h):
        for j in range(w):
            if s[i][j] == 'O':
                sx, sy = i, j
                s[i][j] = '.'

    # Perform a depth-first search from the position of the 'O' with 0 steps
    dfs(sx, sy, 0)

    # Print the answer if it is not equal to INF
    if ans == INF:
        print(-1)
    else:
        print(ans)

# <END-OF-CODE>
