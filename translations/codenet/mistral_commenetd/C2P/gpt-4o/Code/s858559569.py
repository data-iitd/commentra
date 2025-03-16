import sys

N = 4

# Define a class Pazz to hold a 2D array P
class Pazz:
    def __init__(self):
        self.P = [[0] * N for _ in range(N)]

Q = Pazz()  # Initialize an empty Pazz structure Q
dx = [0, 1, 0, -1]  # Define the possible moves in x direction
dy = [1, 0, -1, 0]  # Define the possible moves in y direction

# Function to calculate the heuristic value of the given Pazz structure Q
def Heu(Q):
    sum = 0  # Local variable
    for i in range(N):
        for j in range(N):
            if Q.P[i][j] == 0:
                continue
            hx = (Q.P[i][j] - 1) % N - j
            hy = (Q.P[i][j] - 1) // N - i
            if hx < 0:
                sum -= hx
            else:
                sum += hx
            if hy < 0:
                sum -= hy
            else:
                sum += hy
    return sum  # Return the final sum as the heuristic value of the given Pazz structure Q

# Recursive function to find the solution using Depth First Search algorithm
def dfs(x, y, max_count, count, n):
    h = Heu(Q)  # Calculate the heuristic value h of the current Pazz structure Q
    if h == 0:
        return count  # Base case: If the heuristic value h is 0, return the current count as the solution
    if (count + h) > max_count:
        return -1  # Check if the current count plus the heuristic value h is greater than the maximum allowed count

    for i in range(4):
        x0 = x + dx[i]
        y0 = y + dy[i]
        if (i == (n + 2) % 4 and n != -1) or not (0 <= x0 < N and 0 <= y0 < N):
            continue  # Check if the new position (x0, y0) is valid or not

        # Swap the current position (x, y) with the new position (x0, y0) in the Pazz structure Q
        Q.P[y][x], Q.P[y0][x0] = Q.P[y0][x0], Q.P[y][x]

        ans = dfs(x0, y0, max_count, count + 1, i)  # Recursively call the function dfs
        if ans != -1:
            return ans  # If the function call returns a valid solution, return it

        # Swap back the current position (x, y) with the new position (x0, y0) in the Pazz structure Q
        Q.P[y][x], Q.P[y0][x0] = Q.P[y0][x0], Q.P[y][x]

    return -1  # If no valid solution is found, return -1

# Main function to read the input and call the function dfs to find the solution
if __name__ == "__main__":
    kx, ky = -1, -1  # Local variables to store the position of the empty cell
    for i in range(N):
        for j in range(N):
            a = int(input())  # Read the input and store it in the Pazz structure Q
            Q.P[i][j] = a
            if a == 0:
                kx, ky = j, i  # Store the position of the empty cell

    ans = dfs(kx, ky, 46, 0, -1)  # Call the function dfs with the initial parameters

    if ans != -1:
        print(ans)  # If a valid solution is found, print it
        sys.exit(0)

    print("No solution found")  # If no valid solution is found, print an error message
    sys.exit(1)

# <END-OF-CODE>
