import math  # Importing math for mathematical functions

def main():
    N = int(input())  # Reading the number of points
    pos = [list(map(int, input().split())) for _ in range(N)]  # Reading coordinates of points

    total_distance = 0  # Initializing sum to store the total distance

    # Calculating the sum of distances between all pairs of points
    for i in range(N):
        for j in range(N):
            if i == j:
                continue  # Skipping the diagonal elements
            total_distance += dist(pos[i][0], pos[i][1], pos[j][0], pos[j][1])  # Adding distance to sum

    # Calculating and printing the average distance
    print(total_distance / N)

# Helper function to calculate the Euclidean distance between two points
def dist(x1, y1, x2, y2):
    return math.sqrt((x1 - x2) ** 2 + (y1 - y2) ** 2)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
