
# Importing necessary Python utility classes
import math  # For calculating trigonometric functions
import sys  # For reading input from the console

# Main method where the program starts
def main():
    # Reading the number of points (N) from the input
    N = int(input())

    # Creating two lists, x and y, of size N for storing the x and y coordinates of the points respectively
    x = []
    y = []

    # Reading the x and y coordinates of each point and storing them in the respective lists
    for _ in range(N):
        line = input().split()
        x.append(int(line[0]))  # Reading the x coordinate
        y.append(int(line[1]))  # Reading the y coordinate

    # Calculating the angles between each pair of points and storing them in a list called thetas
    thetas = []
    for i in range(N):
        thetas_i = []

        # Calculating the angles between the current point and all other points
        for j in range(N):
            if i == j: continue  # Skip if the current point is the same as the other point

            # Calculating the angle using the atan2 function
            thetas_i.append(math.atan2(y[j] - y[i], x[j] - x[i]))

        # Sorting the list of angles in ascending order
        thetas_i.sort()

        # Adding the angle between the last point and the first point (wrapped around 2π) to the list
        thetas_i.append(thetas_i[0] + 2 * math.pi)

        thetas.append(thetas_i)

    # Finding the maximum angle between consecutive angles and calculating the answer
    ans = 0
    for i in range(N - 1):
        for j in range(len(thetas[i])):
            ans = max(ans, thetas[i][j + 1] - thetas[i][j] - math.pi)

    # Printing the answer
    print(ans / (2 * math.pi))

# Executing the main method
if __name__ == "__main__":
    main()

