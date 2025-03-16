import math

# Function definition for main function
def main():
    # Read number of points and their dimensions from the user
    n, d = map(int, input().split())

    # Declare a 2D list 'point' to store the coordinates of each point
    point = []

    # Read the coordinates of each point and store them in the 'point' list
    for i in range(n):
        point.append(list(map(int, input().split())))

    # Initialize a counter variable 'count' to 0
    count = 0

    # Iterate through all pairs of points (i, j) where i < j
    for i in range(n):
        for j in range(i + 1, n):
            # Initialize a variable 'sum' to store the sum of the squared differences between the corresponding coordinates of points i and j
            sum_squared_diff = 0

            # Calculate the sum of the squared differences between the corresponding coordinates of points i and j
            for k in range(d):
                sum_squared_diff += (point[i][k] - point[j][k]) ** 2

            # Calculate the Euclidean distance between points i and j using the 'sum' variable
            distance = math.sqrt(sum_squared_diff)

            # Check if the Euclidean distance is equal to an integer value (i.e., the points are on the same circle)
            if math.ceil(distance) == math.floor(distance):
                # If so, increment the 'count' variable
                count += 1

    # Print the final count of pairs of points on the same circle
    print(count)

# Call the main function
main()
