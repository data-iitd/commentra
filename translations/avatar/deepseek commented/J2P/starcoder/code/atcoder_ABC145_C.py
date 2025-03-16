import sys; # Importing sys for input

def dist(x1, y1, x2, y2):
    return ((x1 - x2) ** 2 + (y1 - y2) ** 2) ** 0.5

if __name__ == "__main__":
    N = int(sys.stdin.readline()) # Reading the number of points
    pos = [[0] * 2 for _ in range(N)] # Initializing a 2D array to store coordinates

    # Reading coordinates of points
    for i in range(N):
        pos[i][0], pos[i][1] = map(int, sys.stdin.readline().split()) # Reading x-coordinate and y-coordinate

    sum = 0 # Initializing sum to store the total distance

    # Calculating the sum of distances between all pairs of points
    for i in range(N):
        for j in range(N):
            if i == j: continue # Skipping the diagonal elements
            sum += dist(pos[i][0], pos[i][1], pos[j][0], pos[j][1]) # Adding distance to sum

    # Calculating and printing the average distance
    print(sum / N)

