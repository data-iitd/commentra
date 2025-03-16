
import math

def dist(x1, y1, x2, y2): # Defining the dist function to calculate the Euclidean distance between two points
    return math.sqrt((x1 - x2) ** 2 + (y1 - y2) ** 2) # Returning the calculated distance

N = int(input()) # Reading the number of points from the user

pos = [] # Creating an empty list to store the x and y coordinates of the points

for i in range(N): # Iterating through each point
    x, y = map(int, input().split()) # Reading the x and y coordinates of the point
    pos.append([x, y]) # Appending the coordinates to the list

sum = 0 # Initializing the sum variable to 0

for i in range(N): # Iterating through each point
    for j in range(N): # Iterating through all other points except the current one
        if i == j: continue # Skipping the current point when comparing it with itself
        sum += dist(pos[i][0], pos[i][1], pos[j][0], pos[j][1]) # Adding the distance between the current and the other point to the sum

print(sum / N) # Printing the average distance between all pairs of points

