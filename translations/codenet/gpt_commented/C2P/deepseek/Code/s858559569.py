N = 4

# Define a structure to represent the puzzle state
class Pazz:
    def __init__(self):
        self.P = [[0] * N for _ in range(N)]

# Global variable to hold the current state of the puzzle
Q = Pazz()

# Array to represent movement in the x-direction (right, down, left, up)
dx = [0, 1, 0, -1]
# Array to represent movement in the y-direction (right, down, left, up)
dy = [1, 0, -1, 0]

# Function to calculate the heuristic value (Manhattan distance) of the puzzle state
def Heu(Q):
    sum = 0
    # Loop through each cell in the puzzle
    for i in range(N):
        for j in range(N):
            # Skip the empty tile (represented by 0)
            if Q.P[i][j] == 0:
                continue
            # Calculate the expected position of the tile
            hx = (Q.P[i][j] - 1) % N - j
            hy = (Q.P[i][j] - 1) // N - i
            # Update the sum based on the distances
            sum += abs(hx) + abs(hy)
    return sum

# Depth-first search function to explore possible moves
def dfs(x, y, max, count, n):
    # Calculate the heuristic value for the current state
    h = Heu(Q)
    # If the puzzle is solved (heuristic is 0), return the count of moves
    if h == 0:
        return count
    # If the current count plus heuristic exceeds the maximum allowed, return -1
    if (count + h) > max:
        return -1
    # Explore all possible moves
    for i in range(4):
        x0 = x + dx[i]
        y0 = y + dy[i]
        # Check if the move is valid and not reversing the last move
        if ((i == (n + 2) % 4) and (n != -1)) or not (0 <= x0 < N and 0 <= y0 < N):
            continue
        # Swap the empty tile with the adjacent tile
        Q.P[y][x], Q.P[y0][x0] = Q.P[y0][x0], Q.P[y][x]
        # Recursively call dfs with the new position
        ans = dfs(x0, y0, max, count + 1, i)
        # If a solution is found, return the answer
        if ans != -1:
            return ans
        # Swap back to restore the previous state
        Q.P[y][x], Q.P[y0][x0] = Q.P[y0][x0], Q.P[y][x]
    return -1

# Main function to execute the program
def main():
    kx, ky = -1, -1
    # Read the puzzle input from the user
    for i in range(N):
        for j in range(N):
            a = int(input())
            Q.P[i][j] = a
            if a == 0:
                kx = j
                ky = i
    tP = Pazz()
    for i in range(N):
        for j in range(N):
            tP.P[i][j] = Q.P[i][j]
    # Attempt to solve the puzzle with increasing maximum move limits
    for i in range(1, 46):
        for j in range(N):
            for k in range(N):
                Q.P[j][k] = tP.P[j][k]
        ans = dfs(kx, ky, i, 0, -1)
        if ans != -1:
            print(ans)
            break

if __name__ == "__main__":
    main()
