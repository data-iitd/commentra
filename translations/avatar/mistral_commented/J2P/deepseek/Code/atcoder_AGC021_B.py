import math
import sys

def main():
    # Reading the number of points (N) from the input
    N = int(input())

    # Reading the x and y coordinates of each point and storing them in the respective lists
    points = [tuple(map(int, input().split())) for _ in range(N)]

    # Calculating the angles between each pair of points and storing them in a list called thetas
    thetas = []
    for i in range(N):
        x_i, y_i = points[i]
        angles = []

        # Calculating the angles between the current point and all other points
        for j in range(N):
            if i == j:
                continue  # Skip if the current point is the same as the other point

            # Calculating the angle using the atan2 function
            x_j, y_j = points[j]
            angle = math.atan2(y_j - y_i, x_j - x_i)
            angles.append(angle)

        # Sorting the list of angles in ascending order
        angles.sort()

        # Adding the angle between the last point and the first point (wrapped around 2π) to the list
        angles.append(angles[0] + 2 * math.pi)

        # Appending the angles list to the thetas list
        thetas.append(angles)

    # Finding the maximum angle between consecutive angles and calculating the answer
    ans = 0
    for k in range(N):
        for l in range(len(thetas[k]) - 1):
            angle_diff = thetas[k][l + 1] - thetas[k][l] - math.pi
            if angle_diff > ans:
                ans = angle_diff

    # Printing the answer
    print(ans / (2 * math.pi))

if __name__ == "__main__":
    main()
