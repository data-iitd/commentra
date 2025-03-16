import sys

N = 4

# Define a class to represent the puzzle state
class Pazz:
    def __init__(self):
        self.P = [[0] * N for _ in range(N)]  # 2D array to hold the puzzle grid

Q = Pazz()  # Global variable to hold the current state of the puzzle
dx = [0, 1, 0, -1]  # Array to represent movement in the x-direction (right, down, left, up)
dy = [1, 0, -1, 0]  # Array to represent movement in the y-direction (right, down, left, up)

# Function to calculate the heuristic value (Manhattan distance) of the puzzle state
def Heu(Q):
    sum = 0  # Initialize sum

    # Loop through each cell in the puzzle
    for i in range(N):
        for j in range(N):
            # Skip the empty tile (represented by 0)
            if Q.P[i][j] == 0:
                continue

            # Calculate the expected position of the tile
            hx = (Q.P[i][j] - 1) % N - j  # Horizontal distance
            hy = (Q.P[i][j] - 1) // N - i  # Vertical distance

            # Update the sum based on the distances
            sum += abs(hx) + abs(hy)  # Add the absolute values of hx and hy

    return sum  # Return the total heuristic value

# Depth-first search function to explore possible moves
def dfs(x, y, max_moves, count, n):
    global Q
    h = Heu(Q)  # Calculate the heuristic value for the current state

    # If the puzzle is solved (heuristic is 0), return the count of moves
    if h == 0:
        return count

    # If the current count plus heuristic exceeds the maximum allowed, return -1
    if (count + h) > max_moves:
        return -1

    # Explore all possible moves
    for i in range(4):
        x0 = x + dx[i]  # Calculate new x position
        y0 = y + dy[i]  # Calculate new y position

        # Check if the move is valid and not reversing the last move
        if ((i == (n + 2) % 4) and (n != -1)) or not (0 <= x0 < N and 0 <= y0 < N):
            continue

        # Swap the empty tile with the adjacent tile
        Q.P[y][x], Q.P[y0][x0] = Q.P[y0][x0], Q.P[y][x]

        # Recursively call dfs with the new position
        ans = dfs(x0, y0, max_moves, count + 1, i)

        # If a solution is found, return the answer
        if ans != -1:
            return ans

        # Swap back to restore the previous state
        Q.P[y][x], Q.P[y0][x0] = Q.P[y0][x0], Q.P[y][x]

    return -1  # Return -1 if no solution is found

# Main function to execute the program
if __name__ == "__main__":
    kx = ky = -1  # Variables to hold the position of the empty tile
    # Read the puzzle input from the user
    for i in range(N):
        for j in range(N):
            a = int(input())  # Read each tile value
            Q.P[i][j] = a  # Store the value in the puzzle state
            if a == 0:  # If the tile is empty
                kx, ky = j, i  # Store its x and y positions

    # Attempt to solve the puzzle with increasing maximum move limits
    for i in range(1, 46):
        # Reset the puzzle state
        tP = [row[:] for row in Q.P]
        Q.P = tP
        ans = dfs(kx, ky, i, 0, -1)  # Call dfs to find a solution
        if ans != -1:  # If a solution is found
            print(ans)  # Print the number of moves
            break  # Exit the loop

# <END-OF-CODE>
