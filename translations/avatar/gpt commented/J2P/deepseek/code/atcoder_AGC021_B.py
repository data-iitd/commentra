import math

def main():
    # Read the number of points N
    N = int(input())
    
    # Initialize lists to store the x and y coordinates of the points
    x = []
    y = []
    
    # Read the coordinates of the points from user input
    for _ in range(N):
        coordinates = list(map(int, input().split()))
        x.append(coordinates[0])
        y.append(coordinates[1])
    
    # Iterate over each point to calculate the angles with respect to other points
    for i in range(N):
        # Create a list to store the angles (thetas) for the current point
        thetas = []
        
        # Calculate the angle between the current point and all other points
        for j in range(N):
            # Skip the current point itself
            if i == j:
                continue
            
            # Calculate the angle using atan2 and add it to the list
            theta = math.atan2(y[j] - y[i], x[j] - x[i])
            thetas.append(theta)
        
        # Sort the angles in ascending order
        thetas.sort()
        
        # Add the angle that wraps around (2 * PI) to handle circularity
        thetas.append(thetas[0] + 2 * math.pi)
        
        # Initialize a variable to find the maximum angle difference
        ans = 0
        
        # Calculate the maximum angle difference between consecutive angles
        for k in range(N - 1):
            ans = max(ans, thetas[k + 1] - thetas[k] - math.pi)
        
        # Output the result as a fraction of the full circle (2 * PI)
        print(ans / (2 * math.pi))

if __name__ == "__main__":
    main()
