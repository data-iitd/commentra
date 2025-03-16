import math

def main():
    # Read the number of points (N) from the user
    N = int(input())
    
    # Initialize a list to store the coordinates of the points
    pos = []
    
    # Loop to read the coordinates of each point
    for _ in range(N):
        # Read the x and y coordinates for the point
        x, y = map(int, input().split())
        pos.append((x, y))
    
    # Initialize a variable to accumulate the sum of distances
    total_distance = 0
    
    # Loop through each pair of points to calculate distances
    for i in range(N):
        for j in range(N):
            # Skip the distance calculation if both points are the same
            if i == j:
                continue
            
            # Calculate the distance between point i and point j and add it to the sum
            total_distance += dist(pos[i][0], pos[i][1], pos[j][0], pos[j][1])
    
    # Print the average distance by dividing the total sum by N
    print(total_distance / N)

# Method to calculate the Euclidean distance between two points (x1, y1) and (x2, y2)
def dist(x1, y1, x2, y2):
    return math.sqrt((x1 - x2) ** 2 + (y1 - y2) ** 2)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
