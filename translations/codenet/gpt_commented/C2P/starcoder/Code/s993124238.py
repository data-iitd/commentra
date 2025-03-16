# <START-OF-CODE>

# Read the number of points (n) and the number of dimensions (d)
n, d = map(int, input().split())

# Declare a 2D array to store the coordinates of the points
point = [[0 for i in range(d + 1)] for j in range(n + 1)]

# Input the coordinates for each point
for i in range(1, n + 1):
    for j in range(1, d + 1):
        point[i][j] = int(input())

# Initialize a counter for the number of pairs with integer distance
count = 0

# Iterate through all unique pairs of points
for i in range(1, n):
    for j in range(i + 1, n + 1):
        
        # Calculate the squared distance between point i and point j
        sum = 0
        for k in range(1, d + 1):
            sum = sum + (point[i][k] - point[j][k]) * (point[i][k] - point[j][k])
        
        # Compute the Euclidean distance
        kyori = sum ** 0.5
        
        # Check if the distance is an integer
        if (kyori % 1 == 0):
            count = count + 1 # Increment the count if the distance is an integer

# Output the total count of pairs with integer distance
print(count)

# 