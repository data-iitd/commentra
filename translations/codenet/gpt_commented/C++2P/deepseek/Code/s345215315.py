import sys

# Type definitions for convenience
ll = int
ld = float
EPS = 0.0000000001
INF = 1e9
LINF = INF * INF
MOD = 1000000007

# Redefining int as long long for larger integer support
int = ll

# Function to compute the Greatest Common Divisor (GCD) of two numbers
def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

# Function to compute the Least Common Multiple (LCM) of two numbers
def lcm(a, b):
    return a // gcd(a, b) * b

# Global variables for the problem
ans = INF
h = 19
w = 15
dx = [0, 1, 0, -1, 1, 1, -1, -1]
dy = [1, 0, -1, 0, 1, -1, 1, -1]
s = [""] * 19

# Depth-First Search (DFS) function to explore the grid
def dfs(x, y, cnt):
    global ans
    # Base case: if the count exceeds 20, stop the search
    if cnt > 20:
        return

    # Check if the bottom row is reached
    if x == h - 1:
        ans = min(ans, cnt)
        return

    # Explore all 8 possible directions
    for i in range(8):
        nx = x + dx[i]
        ny = y + dy[i]
        # Check if the new coordinates are within bounds
        if nx < 0 or nx >= h or ny < 0 or ny >= w:
            continue
        # Check if the current cell is not blocked
        if s[nx][ny] != 'X':
            continue

        c = True
        # Move in the current direction while possible
        while c and s[nx][ny] == 'X':
            s[nx] = s[nx][:ny] + '.' + s[nx][ny+1:]
            nx += dx[i]
            ny += dy[i]
            if nx < 0 or nx >= h or ny < 0 or ny >= w:
                if nx >= h:
                    ans = min(ans, cnt + 1)
                c = False

        # Recursive DFS call for the new position
        if c:
            dfs(nx, ny, cnt + 1)
        # Backtrack: restore the grid to its previous state
        while nx != x or ny != y:
            nx -= dx[i]
            ny -= dy[i]
            s[nx] = s[nx][:ny] + 'X' + s[nx][ny+1:]
        s[x] = s[x][:y] + '.' + s[x][y+1:]

# Main function
if __name__ == "__main__":
    # Input the grid
    for i in range(h):
        s[i] = input().strip()
    # Find the starting position 'O' and mark it as visited
    for i in range(h):
        for j in range(w):
            if s[i][j] == 'O':
                sx, sy = i, j
                s[i] = s[i][:j] + '.' + s[i][j+1:]

    # Start DFS from the initial position
    dfs(sx, sy, 0)

    # Output the result: minimum moves or -1 if not reachable
    if ans == INF:
        print(-1)
    else:
        print(ans)
