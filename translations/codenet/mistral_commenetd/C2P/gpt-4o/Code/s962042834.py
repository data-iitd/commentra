def kansu(a, b):
    # Function to calculate the number of unique paths in a grid
    suu = [[0] * (b + 1) for _ in range(a + 1)]  # 2D array to store unique paths
    kouji = [[0] * (b + 1) for _ in range(a + 1)]  # 2D array to mark visited cells

    n = int(input("Enter the number of obstacles in the grid: "))  # Read user input for number of obstacles

    # Initialize 2D array kouji with zeros
    for i in range(1, a + 1):
        for j in range(1, b + 1):
            kouji[i][j] = 0

    # Read user input for obstacle positions and mark them in kouji
    for _ in range(n):
        x, y = map(int, input().split())
        kouji[x][y] = 1

    # Initialize first row and column of suu with ones
    for i in range(1, a + 1):
        for j in range(1, b + 1):
            if kouji[i][j] == 1:
                suu[i][j] = 0  # Set suu[i][j] to zero if cell is an obstacle
            else:
                if i == 1 and j == 1:
                    suu[i][j] = 1  # Set suu[i][j] to one if it's the starting cell
                else:
                    if i == 1:
                        suu[i][j] = suu[i][j - 1]  # Set suu[i][j] to the value of suu[i][j-1]
                    elif j == 1:
                        suu[i][j] = suu[i - 1][j]  # Set suu[i][j] to the value of suu[i-1][j]
                    else:
                        suu[i][j] = suu[i][j - 1] + suu[i - 1][j]  # Set suu[i][j] to the sum of suu[i][j-1] and suu[i-1][j]

    # Print the result (unique paths)
    print(f"The number of unique paths in the grid is: {suu[a][b]}")

def main():
    a, b = map(int, input("Enter the dimensions of the grid (width and height): ").split())  # Read user input for grid dimensions

    # Loop until user enters valid dimensions (non-zero)
    while a != 0 and b != 0:
        kansu(a, b)  # Call function kansu to calculate unique paths
        a, b = map(int, input("Enter the dimensions of the next grid (width and height): ").split())  # Read user input for next grid dimensions

if __name__ == "__main__":
    main()

# <END-OF-CODE>
