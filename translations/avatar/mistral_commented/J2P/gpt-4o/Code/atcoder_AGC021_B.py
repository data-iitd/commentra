import math  # For mathematical functions
from typing import List  # For type hinting

def main():
    # Reading the number of points (N) from the input
    N = int(input())

    # Creating two lists, x and y, for storing the x and y coordinates of the points respectively
    x = [0] * N
    y = [0] * N

    # Reading the x and y coordinates of each point and storing them in the respective lists
    for i in range(N):
        x[i], y[i] = map(int, input().split())  # Reading the x and y coordinates

    # Calculating the angles between each pair of points and storing them in a list called thetas
    for i in range(N):
        thetas = []  # Creating a new list for storing the angles

        # Calculating the angles between the current point and all other points
        for j in range(N):
            if i == j:
                continue  # Skip if the current point is the same as the other point

            # Calculating the angle using the atan2 function
            thetas.append(math.atan2(y[j] - y[i], x[j] - x[i]))

        # Sorting the list of angles in ascending order
        thetas.sort()

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

# <END-OF-CODE>
