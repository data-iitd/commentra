import math

def main():
    # Read the number of points (n) and the number of dimensions (d)
    n, d = map(int, input().split())
    
    # Declare a list to store the coordinates of the points
    points = []
    
    # Input the coordinates for each point
    for _ in range(n):
        point = list(map(int, input().split()))
        points.append(point)
    
    # Initialize a counter for the number of pairs with integer distance
    count = 0
    
    # Iterate through all unique pairs of points
    for i in range(n - 1):
        for j in range(i + 1, n):
            # Calculate the squared distance between point i and point j
            sum_squared = sum((points[i][k] - points[j][k]) ** 2 for k in range(d))
            
            # Compute the Euclidean distance
            distance = math.sqrt(sum_squared)
            
            # Check if the distance is an integer
            if distance.is_integer():
                count += 1  # Increment the count if the distance is an integer
    
    # Output the total count of pairs with integer distance
    print(count)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
