

# Python code to calculate the number of unique paths in a grid

def kansu(a, b):
    # Function to calculate the number of unique paths in a grid
    suu = [[0 for j in range(b+1)] for i in range(a+1)]
    kouji = [[0 for j in range(b+1)] for i in range(a+1)]
    n = int(input("Enter the number of obstacles in the grid: "))
    for i in range(n):
        x, y = map(int, input("Enter the position of the obstacle: ").split())
        kouji[x][y] = 1
    for i in range(1, a+1):
        for j in range(1, b+1):
            if kouji[i][j] == 1:
                suu[i][j] = 0
            else:
                if i == 1 and j == 1:
                    suu[i][j] = 1
                else:
                    if i == 1:
                        suu[i][j] = suu[i][j-1]
                    else:
                        if j == 1:
                            suu[i][j] = suu[i-1][j]
                        else:
                            suu[i][j] = suu[i][j-1] + suu[i-1][j]
    print("The number of unique paths in the grid is:", suu[a][b])

# Main function to read user input and call kansu function
def main():
    while True:
        a, b = map(int, input("Enter the dimensions of the grid (width and height): ").split())
        if a == 0 and b == 0:
            break
        kansu(a, b)

if __name__ == "__main__":
    main()

