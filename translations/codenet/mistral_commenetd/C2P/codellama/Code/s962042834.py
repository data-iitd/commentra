
#include<stdio.h>

# Function to calculate the number of unique paths in a grid
def kansu(a, b):
	i, j, x, y, n = 0, 0, 0, 0, 0
	suu = [[0 for i in range(17)] for j in range(17)]
	kouji = [[0 for i in range(17)] for j in range(17)]

	print("Enter the number of obstacles in the grid: ")
	scanf("%d", &n)

	# Initialize 2D array kouji with zeros
	for i in range(1, a + 1):
		for j in range(1, b + 1):
			kouji[i][j] = 0

	# Read user input for obstacle positions and mark them in kouji
	for i in range(0, n):
		scanf("%d %d", &x, &y)
		kouji[x][y] = 1

	# Initialize first row and column of suu with ones
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
					else if j == 1:
						suu[i][j] = suu[i - 1][j]
					else:
						suu[i][j] = suu[i][j - 1] + suu[i - 1][j]

	# Print the result (unique paths)
	print("The number of unique paths in the grid is: ", suu[a][b])

# Main function
def main():
	a, b = 0, 0

	print("Enter the dimensions of the grid (width and height): ")
	scanf("%d %d", &a, &b)

	# Loop until user enters valid dimensions (non-zero)
	while a != 0 and b != 0:
		kansu(a, b)
		print("Enter the dimensions of the next grid (width and height): ")
		scanf("%d %d", &a, &b)

# Call main function
main()

