#include<stdio.h>

# Function definition for kansu
def kansu(a, b):
	# Declare variables for loop indices and other necessary variables
	i = 0
	j = 0
	x = 0
	y = 0
	n = 0
	
	# Declare 2D arrays to store the number of ways and the presence of obstacles
	suu = [[0 for x in range(17)] for y in range(17)]
	kouji = [[0 for x in range(17)] for y in range(17)]
	
	# Read the number of obstacles
	n = int(input())
	
	# Initialize the kouji array to mark the positions of obstacles
	for i in range(1, a + 1):
		for j in range(1, b + 1):
			kouji[i][j] = 0
	
	# Read the positions of the obstacles and mark them in the kouji array
	for i in range(0, n):
		x, y = map(int, input().split())
		kouji[x][y] = 1
	
	# Initialize the suu array to store the number of ways to reach each cell
	for i in range(1, a + 1):
		for j in range(1, b + 1):
			# If the cell is an obstacle, set its value to 0
			if kouji[i][j] == 1:
				suu[i][j] = 0
			else:
				# If the cell is at the top-left corner, there is 1 way to reach it
				if i == 1 and j == 1:
					suu[i][j] = 1
				else:
					# Calculate the number of ways to reach the cell based on possible movements
					if i == 1:
						suu[i][j] = suu[i][j - 1]
					elif j == 1:
						suu[i][j] = suu[i - 1][j]
					else:
						suu[i][j] = suu[i][j - 1] + suu[i - 1][j]
	
	# Print the number of ways to reach the bottom-right corner of the grid
	print(suu[a][b])

# Main function
if __name__ == "__main__":
	# Declare variables to store the dimensions of the grid
	a = 0
	b = 0
	
	# Read the dimensions of the grid from the input
	a, b = map(int, input().split())
	
	# Continue reading and processing until both dimensions are zero
	while a!= 0 and b!= 0:
		# Call the function kansu with the current dimensions
		kansu(a, b)
		# Read the next pair of dimensions
		a, b = map(int, input().split())

# 