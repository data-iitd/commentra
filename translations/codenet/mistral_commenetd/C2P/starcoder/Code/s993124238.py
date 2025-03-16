
#include <stdio.h>
#include <math.h>

# Function declaration for main function
def main():
	# Declare variables for number of points and their dimensions
	n, d = map(int, input().split())

	# Declare a 2D array 'point' to store the coordinates of each point
	point = [[0 for i in range(d+1)] for j in range(n+1)]

	# Read the coordinates of each point and store them in the 'point' array
	for i in range(1, n+1):
		for j in range(1, d+1):
			point[i][j] = int(input())
			# Comment explaining the inner loop
			# Read the j-th coordinate of the i-th point
		# Comment explaining the outer loop
		# Read the i-th row of the 'point' array (i.e., the i-th point's coordinates)

	# Initialize a counter variable 'count' to 0
	count = 0

	# Iterate through all pairs of points (i, j) where i < j
	for i in range(1, n):
		for j in range(i+1, n+1):
			# Initialize a variable'sum' to store the sum of the squared differences between the corresponding coordinates of points i and j
			sum = 0

			# Calculate the sum of the squared differences between the corresponding coordinates of points i and j
			for k in range(1, d+1):
				sum = sum + (point[i][k] - point[j][k])*(point[i][k] - point[j][k])
				# Comment explaining the inner loop
				# Calculate the difference between the k-th coordinate of point i and the k-th coordinate of point j, square it, and add it to the'sum' variable

			# Calculate the Euclidean distance between points i and j using the'sum' variable
			kyori = sqrt(sum)

			# Check if the Euclidean distance is equal to an integer value (i.e., the points are on the same circle)
			if (ceil(kyori) == floor(kyori)):
				# If so, increment the 'count' variable
				count = count + 1

	# Print the final count of pairs of points on the same circle
	print(count)

# 