import sys

def dist(x1, y1, x2, y2):
    return ((x1 - x2) ** 2 + (y1 - y2) ** 2) ** 0.5

def main():
    # Read the number of points (N) from the user
    N = int(input())
    
    # Initialize a 2D array to store the coordinates of the points
    pos = [[0] * 2 for i in range(N)]
    
    # Loop to read the coordinates of each point
    for i in range(N):
        # Read the x and y coordinates for the i-th point
        pos[i][0], pos[i][1] = map(int, input().split())
    
    # Initialize a variable to accumulate the sum of distances
    sum = 0
    
    # Loop through each pair of points to calculate distances
    for i in range(N):
        for j in range(N):
            # Skip the distance calculation if both points are the same
            if i == j: continue
            
            # Calculate the distance between point i and point j and add it to the sum
            sum += dist(pos[i][0], pos[i][1], pos[j][0], pos[j][1])
    
    # Print the average distance by dividing the total sum by N
    print(sum / N)

if __name__ == "__main__":
    main()

# 