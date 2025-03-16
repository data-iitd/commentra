# Importing necessary Python utility classes
from math import atan2, pi
from typing import List

# Main method where the program starts
def main():
    # Creating a Scanner object for reading input from the console
    scan = input()

    # Reading the number of points (N) from the input
    N = int(scan)

    # Creating two arrays, x and y, of size N for storing the x and y coordinates of the points respectively
    x = [0] * N
    y = [0] * N

    # Reading the x and y coordinates of each point and storing them in the respective arrays
    for i in range(N):
        x[i], y[i] = map(int, input().split())

    # Calculating the angles between each pair of points and storing them in a list called thetas
    thetas = []
    for i in range(N):
        thetas.append([])
        for j in range(N):
            if i == j:
                continue
            thetas[i].append(atan2(y[j] - y[i], x[j] - x[i]))

    # Sorting the list of angles in ascending order
    for i in range(N):
        thetas[i].sort()

    # Adding the angle between the last point and the first point (wrapped around 2π) to the list
    thetas[i].append(thetas[i][0] + 2 * pi)

    # Finding the maximum angle between consecutive angles and calculating the answer
    ans = 0
    for k in range(N - 1):
        ans = max(ans, thetas[k + 1][k] - thetas[k][k] - pi)

    # Printing the answer
    print(ans / (2 * pi))


