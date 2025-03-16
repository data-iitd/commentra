
import math  # Import the math module for mathematical functions like sqrt

n, d = map(int, input().split())  # Read the values of n and d from the standard input

point = [[0 for _ in range(d+1)] for _ in range(n+1)]  # Initialize a 2D list to store the points with dimensions (n+1) x (d+1)

# Nested loop to read the coordinates of each point from the standard input
for i in range(1, n+1):
    point[i] = list(map(int, input().split()))

count = 0  # Initialize a counter to zero to count the number of integer distances

# Nested loop to calculate the Euclidean distance between each pair of points
for i in range(1, n):
    for j in range(i+1, n+1):
        
        sum = 0  # Initialize a variable to store the sum of squared differences
        for k in range(1, d+1):
            sum += (point[i][k] - point[j][k]) ** 2
        kyori = math.sqrt(sum)  # Compute the square root of the sum to get the distance
        
        # Check if the distance is an integer by comparing ceil and floor of the distance
        if math.ceil(kyori) == math.floor(kyori):
            count += 1  # Increment the counter if the distance is an integer

print(count)  # Print the final count of integer distances

