#include<stdio.h>

# Function to calculate the number of paths in a grid with obstacles
def kansu(a, b):
    # Initialize the kouji array to mark all cells as free (0)
    kouji = [[0 for i in range(b + 1)] for j in range(a + 1)]
    
    # Read the number of obstacles
    n = int(input())
    
    # Read the positions of obstacles and mark them in the kouji array
    for i in range(n):
        x, y = map(int, input().split())
        kouji[x][y] = 1 # Mark the cell as an obstacle (1)
    
    # Calculate the number of paths to each cell in the grid
    for i in range(1, a + 1):
        for j in range(1, b + 1):
            # If the cell is an obstacle, set paths to 0
            if(kouji[i][j] == 1):
                suu[i][j] = 0
            else:
                # If at the starting cell, initialize paths to 1
                if(i == 1 and j == 1):
                    suu[i][j] = 1
                else:
                    # If in the first row, inherit paths from the left cell
                    if(i == 1):
                        suu[i][j] = suu[i][j - 1]
                    # If in the first column, inherit paths from the above cell
                    elif(j == 1):
                        suu[i][j] = suu[i - 1][j]
                    # For other cells, sum paths from the left and above cells
                    else:
                        suu[i][j] = suu[i][j - 1] + suu[i - 1][j]
    
    # Output the total number of paths to the bottom-right cell
    print(suu[a][b])

# Read the dimensions of the grid (a x b)
a, b = map(int, input().split())

# Continue processing until both dimensions are zero
while(a!= 0 and b!= 0):
    # Call the function to calculate paths in the grid
    kansu(a, b)
    
    # Read the next set of dimensions
    a, b = map(int, input().split())

# 