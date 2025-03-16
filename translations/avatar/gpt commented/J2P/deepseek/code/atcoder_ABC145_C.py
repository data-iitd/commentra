import math

def main():
    # Read the number of points (N) from the user
    N = int(input())
    
    # Initialize a list to store the coordinates of the points
    pos = []
    
    # Loop to read the coordinates of each point
    for _ in range(N):
        # Read the x and y coordinates for the current point and append them to the list
        x, y = map(int, input().split())
        pos.append((x, y))
    
    # Initialize a variable to accumulate the sum of distances
    sum_dist = 0
    
    # Loop through each pair of points to calculate distances
    for i in range(N):
        for j in range(N):
            # Skip the distance calculation if both points are the same
            if i == j:
                continue
            
            # Calculate the distance between point i and point j and add it to the sum
            sum_dist += distance(pos[i], pos[j])
    
    # Print the average distance by dividing the total sum by N
    print(sum_dist / N)

# Method to calculate the Euclidean distance between two points (x1, y1) and (x2, y2)
def distance(point1, point2):
    x1, y1 = point1
    x2, y2 = point2
    return math.sqrt((x1 - x2) ** 2 + (y1 - y2) ** 2)

# Call the main function
if __name__ == "__main__":
    main()
