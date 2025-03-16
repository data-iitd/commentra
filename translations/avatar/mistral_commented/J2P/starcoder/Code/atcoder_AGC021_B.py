# Importing necessary Python utility classes
import sys  # For reading input from the console
import math  # For calculating the angles
from operator import itemgetter  # For sorting the list of thetas

# Main method where the program starts
def main():
    # Reading the number of points (N) from the input
    N = int(sys.stdin.readline())

    # Creating two arrays, x and y, of size N for storing the x and y coordinates of the points respectively
    x = [0] * N
    y = [0] * N

    # Reading the x and y coordinates of each point and storing them in the respective arrays
    for i in range(N):
        x[i], y[i] = map(int, sys.stdin.readline().split())

    # Calculating the angles between each pair of points and storing them in a list called thetas
    thetas = []
    for i in range(N):
        # Calculating the angles between the current point and all other points
        for j in range(N):
            if i == j: continue  # Skip if the current point is the same as the other point

            # Calculating the angle using the atan2 function
            thetas.append(math.atan2(y[j] - y[i], x[j] - x[i]))

    # Sorting the list of angles in ascending order
    thetas.sort(key=itemgetter(0))

    # Adding the angle between the last point and the first point (wrapped around 2π) to the list
    thetas.append(thetas[0] + 2 * math.pi)

    # Finding the maximum angle between consecutive angles and calculating the answer
    ans = 0
    for k in range(N - 1):
        ans = max(ans, thetas[k + 1] - thetas[k] - math.pi)

    # Printing the answer
    print(ans / (math.pi * 2))

if __name__ == "__main__":
    main()

