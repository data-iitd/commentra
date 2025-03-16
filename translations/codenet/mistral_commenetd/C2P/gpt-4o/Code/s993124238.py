import math

# Function to read points and count pairs on the same circle
def main():
    # Read number of points and their dimensions from the user
    n, d = map(int, input().split())

    # Declare a list to store the coordinates of each point
    points = []

    # Read the coordinates of each point and store them in the 'points' list
    for i in range(n):
        point = list(map(int, input().split()))
        points.append(point)
        # Comment explaining the loop
        # Read the coordinates of the i-th point

    # Initialize a counter variable 'count' to 0
    count = 0

    # Iterate through all pairs of points (i, j) where i < j
    for i in range(n - 1):
        for j in range(i + 1, n):
            # Initialize a variable 'sum' to store the sum of the squared differences
            sum_squared_diff = 0

            # Calculate the sum of the squared differences between the corresponding coordinates of points i and j
            for k in range(d):
                sum_squared_diff += (points[i][k] - points[j][k]) ** 2
                # Comment explaining the inner loop
                # Calculate the difference between the k-th coordinate of point i and the k-th coordinate of point j, square it, and add it to the 'sum_squared_diff' variable

            # Calculate the Euclidean distance between points i and j using the 'sum_squared_diff' variable
            distance = math.sqrt(sum_squared_diff)

            # Check if the Euclidean distance is equal to an integer value (i.e., the points are on the same circle)
            if distance.is_integer():
                # If so, increment the 'count' variable
                count += 1

    # Print the final count of pairs of points on the same circle
    print(count)

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
