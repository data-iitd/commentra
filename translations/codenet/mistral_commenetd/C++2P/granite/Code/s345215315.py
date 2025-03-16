
import sys
sys.setrecursionlimit(10**6)

def gcd(a, b):
    # Function to find the greatest common divisor of two numbers
    if b == 0:
        return a
    return gcd(b, a % b)

def lcm(a, b):
    # Function to find the least common multiple of two numbers
    return a // gcd(a, b) * b

# Global variables
ans = float('inf')
h = 19
w = 15
s = [list(input()) for _ in range(h)]
dx = [0, 1, 0, -1, 1, 1, 1, -1, -1]
dy = [1, 0, -1, 0, 1, -1, 1, 1, -1]

def dfs(x, y, cnt):
    # Base case: if the number of steps is greater than 20, return
    if cnt > 20:
        return

    # Print the current position, number of steps, and the current state of the grid
    # for debugging purposes
    #print(x, y, cnt)
    # Print the current state of the grid
    #for row in s:
    #    print(''.join(row))

    # Check if the current position is the last row of the grid
    if x == h - 1:
        # Update the answer if the current number of steps is less than the previous answer
        global ans
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
        if s[nx][ny]!= 'X':
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
        while nx!= x or ny!= y:
            nx -= dx[i]
            ny -= dy[i]
            s[nx][ny] = 'X'

        # Restore the current position of the 'O'
        s[x][y] = '.'

# Main function
if __name__ == '__main__':
    # Initialize the 2D vector to store the grid
    for i in range(h):
        s[i] = list(input())

    # Find the position of the 'O'
    sx, sy = -1, -1
    for i in range(h):
        for j in range(w):
            if s[i][j] == 'O':
                sx, sy = i, j
                s[i][j] = '.'
    # Perform a depth-first search from the position of the 'O' with 0 steps
    dfs(sx, sy, 0)

    # Print the answer if it is not equal to float('inf')
    if ans == float('inf'):
        print(-1)
    else:
        print(ans)

