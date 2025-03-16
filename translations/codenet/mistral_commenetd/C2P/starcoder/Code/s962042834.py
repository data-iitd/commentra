
# Function to calculate the number of unique paths in a grid
def kansu(a, b):
	# Declare variables i, j, x, y, and n
	i = 0
	j = 0
	x = 0
	y = 0
	n = 0

	# Declare 2D array suu to store unique paths
	suu = [[0 for x in range(17)] for y in range(17)]

	# Declare 2D array kouji to mark visited cells
	kouji = [[0 for x in range(17)] for y in range(17)]

	# Read user input for number of obstacles in the grid
	n = int(input("Enter the number of obstacles in the grid: "))

	# Read user input for obstacle positions and mark them in kouji
	for i in range(n):
		x, y = map(int, input("Enter the position of an obstacle: ").split())
		kouji[x][y] = 1

	# Initialize first row and column of suu with ones
	for i in range(1, a + 1):
		for j in range(1, b + 1):
			if kouji[i][j] == 1:
				suu[i][j] = 0 # Set suu[i][j] to zero if cell is an obstacle
			else:
				if i == 1 and j == 1:
					suu[i][j] = 1 # Set suu[i][j] to one if it's the starting cell
				else:
					if i == 1:
						suu[i][j] = suu[i][j - 1] # Set suu[i][j] to the value of suu[i][j-1]
					else if j == 1:
						suu[i][j] = suu[i - 1][j] # Set suu[i][j] to the value of suu[i-1][j]
					else:
						suu[i][j] = suu[i][j - 1] + suu[i - 1][j] # Set suu[i][j] to the sum of suu[i][j-1] and suu[i-1][j]

	# Print the result (unique paths)
	print("The number of unique paths in the grid is: ", suu[a][b])

# Main program
if __name__ == "__main__":
	a = 0
	b = 0

	# Loop until user enters valid dimensions (non-zero)
	while a!= 0 and b!= 0:
		a, b = map(int, input("Enter the dimensions of the grid (width and height): ").split())
		kansu(a, b) # Call function kansu to calculate unique paths
		a = 0
		b = 0
		a, b = map(int, input("Enter the dimensions of the next grid (width and height): ").split())

