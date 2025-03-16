import math  # Importing the math module for mathematical functions

def main():  # Defining the main function
    N = int(input())  # Reading the number of points from the user

    pos = [[0, 0] for _ in range(N)]  # Creating a 2D list of size N x 2 to store the x and y coordinates of the points

    for i in range(N):  # Iterating through each point
        pos[i][0] = int(input())  # Reading the x coordinate of the point
        pos[i][1] = int(input())  # Reading the y coordinate of the point

    total_distance = 0  # Initializing the total distance variable to 0

    for i in range(N):  # Iterating through each point
        for j in range(N):  # Iterating through all other points except the current one
            if i == j:
                continue  # Skipping the current point when comparing it with itself
            total_distance += dist(pos[i][0], pos[i][1], pos[j][0], pos[j][1])  # Adding the distance between the current and the other point to the total distance

    print(total_distance / N)  # Printing the average distance between all pairs of points

def dist(x1, y1, x2, y2):  # Defining the dist function to calculate the Euclidean distance between two points
    return math.sqrt((x1 - x2) ** 2 + (y1 - y2) ** 2)  # Returning the calculated distance

if __name__ == "__main__":  # Checking if the script is being run directly
    main()  # Calling the main function

# <END-OF-CODE>
