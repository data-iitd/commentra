import sys

N = 4  # Define a constant N for the size of the puzzle

class Pazz:  # Define a class for the puzzle
    def __init__(self):
        self.P = [[0] * N for _ in range(N)]  # 2D array to store the puzzle state

Q = Pazz()  # Initialize a global variable Q to store the puzzle state
dx = [0, 1, 0, -1]  # Define an array for horizontal movement directions
dy = [1, 0, -1, 0]  # Define an array for vertical movement directions

def Heu(Q):  # Heuristic function to calculate the Manhattan distance
    sum = 0
    for i in range(N):  # Iterate through each row
        for j in range(N):  # Iterate through each column
            if Q.P[i][j] == 0:
                continue  # Skip the empty tile

            hx = (Q.P[i][j] - 1) % N - j  # Calculate the horizontal distance
            hy = (Q.P[i][j] - 1) // N - i  # Calculate the vertical distance

            sum += abs(hx) + abs(hy)  # Add the total distance to the sum
    return sum  # Return the total sum of Manhattan distances

def dfs(x, y, max_depth, count, n):  # Depth-first search function
    h = Heu(Q)  # Calculate the heuristic value of the current state

    if h == 0:
        return count  # If the puzzle is solved, return the number of moves
    if (count + h) > max_depth:
        return -1  # If the maximum depth is exceeded, return -1

    for i in range(4):  # Iterate through all possible moves
        x0 = x + dx[i]
        y0 = y + dy[i]

        if ((i == (n + 2) % 4) and (n != -1)) or not (0 <= x0 < N and 0 <= y0 < N):
            continue  # Skip invalid moves

        # Swap the current tile with the target tile
        Q.P[y][x], Q.P[y0][x0] = Q.P[y0][x0], Q.P[y][x]

        ans = dfs(x0, y0, max_depth, count + 1, i)  # Recursively call dfs with the new state

        if ans != -1:
            return ans  # If a solution is found, return the number of moves

        # Swap back to the original state
        Q.P[y][x], Q.P[y0][x0] = Q.P[y0][x0], Q.P[y][x]

    return -1  # If no solution is found, return -1

def main():  # Main function to read the puzzle, initialize it, and start the DFS search
    kx, ky = -1, -1  # Initialize the position of the empty tile
    for i in range(N):  # Read the puzzle from input
        for j in range(N):
            a = int(sys.stdin.readline().strip())
            Q.P[i][j] = a
            if a == 0:
                kx, ky = j, i

    tP = Q  # Store the initial puzzle state
    for i in range(1, 46):  # Iterate through possible depths
        Q = tP  # Reset to the initial state
        ans = dfs(kx, ky, i, 0, -1)
        if ans != -1:
            print(ans)  # Print the number of moves if a solution is found
            break

if __name__ == "__main__":
    main()  # Execute the main function

# <END-OF-CODE>
