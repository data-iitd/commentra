
# Read the dimensions of the grid (a x b)
a, b = map(int, input().split())

# Continue processing until both dimensions are zero
while a!= 0 and b!= 0:
    # Read the number of obstacles
    n = int(input())
    
    # Initialize the kouji array to mark all cells as free (0)
    kouji = [[0 for _ in range(b + 1)] for _ in range(a + 1)]
    
    # Read the positions of obstacles and mark them in the kouji array
    for _ in range(n):
        x, y = map(int, input().split())
        kouji[x][y] = 1
    
    # Calculate the number of paths to each cell in the grid
    suu = [[0 for _ in range(b + 1)] for _ in range(a + 1)]
    for i in range(1, a + 1):
        for j in range(1, b + 1):
            if kouji[i][j] == 1:
                suu[i][j] = 0
            else:
                if i == 1 and j == 1:
                    suu[i][j] = 1
                else:
                    if i == 1:
                        suu[i][j] = suu[i][j - 1]
                    elif j == 1:
                        suu[i][j] = suu[i - 1][j]
                    else:
                        suu[i][j] = suu[i][j - 1] + suu[i - 1][j]
    
    # Output the total number of paths to the bottom-right cell
    print(suu[a][b])
    
    # Read the next set of dimensions
    a, b = map(int, input().split())

