# Include standard input-output library for input and output operations
# Include mathematical library for mathematical functions like sqrt
import math

# Function to read the number of points and dimensions from the standard input
def read_input():
	n = int(input())  # Read the number of points
	d = int(input())  # Read the number of dimensions
	return n, d

# Function to read the coordinates of each point from the standard input
def read_points(n, d):
	points = []  # Initialize an empty list to store the points
	for i in range(n):
		point = []  # Initialize an empty list to store the coordinates of a point
		for j in range(d):
			point.append(int(input()))  # Read the coordinates of a point
		points.append(point)  # Add the point to the list of points
	return points

# Function to calculate the Euclidean distance between two points
def distance(point1, point2):
	sum = 0  # Initialize a variable to store the sum of squared differences
	for i in range(len(point1)):
		sum = sum + (point1[i] - point2[i]) * (point1[i] - point2[i])
	return math.sqrt(sum)  # Compute the square root of the sum to get the distance

# Function to check if the distance is an integer
def is_integer(distance):
	return (math.ceil(distance) == math.floor(distance))  # Check if the distance is an integer by comparing ceil and floor of the distance

# Function to count the number of integer distances
def count_integer_distances(points):
	count = 0  # Initialize a counter to zero to count the number of integer distances
	for i in range(len(points)-1):
		for j in range(i+1, len(points)):
			if is_integer(distance(points[i], points[j])):
				count = count + 1  # Increment the counter if the distance is an integer
	return count

# Main function
def main():
	n, d = read_input()  # Read the number of points and dimensions from the standard input
	points = read_points(n, d)  # Read the coordinates of each point from the standard input
	count = count_integer_distances(points)  # Count the number of integer distances
	print(count)  # Print the final count of integer distances

# Call the main function
main()

