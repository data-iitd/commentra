#include <stdio.h>  # Include standard input-output library for input and output operations
#include <math.h>   # Include mathematical library for mathematical functions like sqrt

def main():
    n, d = map(int, input().split())  # Read the values of n and d from the standard input

    point = [[0 for i in range(d+1)] for j in range(n+1)]  # Declare a 2D array to store the points with dimensions (n+1) x (d+1)

    # Nested loop to read the coordinates of each point from the standard input
    for i in range(1, n+1):
        for j in range(1, d+1):
            point[i][j] = int(input())

    count = 0  # Initialize a counter to zero to count the number of integer distances

    # Nested loop to calculate the Euclidean distance between each pair of points
    for i in range(1, n):
        for j in range(i+1, n+1):

            sum = 0  # Initialize a variable to store the sum of squared differences
            for k in range(1, d+1):
                sum = sum + (point[i][k] - point[j][k]) * (point[i][k] - point[j][k])
            kyori = sqrt(sum)  # Compute the square root of the sum to get the distance

            # Check if the distance is an integer by comparing ceil and floor of the distance
            if ceil(kyori) == floor(kyori):
                count += 1  # Increment the counter if the distance is an integer

    print(count)  # Print the final count of integer distances


