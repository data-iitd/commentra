import sys
sys.setrecursionlimit(10000)

# Global variables
ans = float('inf')
h = 19
w = 15
s = [input().strip() for _ in range(19)]  # 2D list to store the grid
dx = [0, 1, 0, -1, 1, 1, -1, -1]
dy = [1, 0, -1, 0, 1, -1, 1, -1]

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
        nx = x + dx[i]
        ny = y + dy[i]

        # Check if the next position is out of the grid
        if nx < 0 or nx >= h or ny < 0 or ny >= w:
            continue

        # Check if the next position contains an 'X'
        if s[nx][ny] != 'X':
            continue

        # Perform a depth-first search from the next position with one more step
        c = True
        while c and s[nx][ny] == 'X':
            s[nx] = s[nx][:ny] + '.' + s[nx][ny+1:]
            nx += dx[i]
            ny += dy[i]
            if nx < 0 or nx >= h or ny < 0 or ny >= w:
                if nx >= h:
                    ans = min(ans, cnt + 1)
                c = False

        if c:
            dfs(nx, ny, cnt + 1)

        # Backtrack by restoring the previous state of the grid
        while nx != x or ny != y:
            nx -= dx[i]
            ny -= dy[i]
            s[nx] = s[nx][:ny] + 'X' + s[nx][ny+1:]

        # Restore the current position of the 'O'
        s[x] = s[x][:y] + 'O' + s[x][y+1:]

# Main function
def main():
    # Find the position of the 'O'
    for i in range(h):
        for j in range(w):
            if s[i][j] == 'O':
                s[i] = s[i][:j] + '.' + s[i][j+1:]
                dfs(i, j, 0)
                s[i] = s[i][:j] + 'O' + s[i][j+1:]

    # Print the answer if it is not equal to INF
    if ans == float('inf'):
        print(-1)
    else:
        print(ans)

if __name__ == "__main__":
    main()
