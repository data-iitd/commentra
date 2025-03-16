# Read input from the user and split it into a list of strings
p = input().split(" ")

# Convert the first four elements of the list to integers representing coordinates
x1 = int(p[0])  # x-coordinate of the first point
y1 = int(p[1])  # y-coordinate of the first point
x2 = int(p[2])  # x-coordinate of the second point
y2 = int(p[3])  # y-coordinate of the second point

# Calculate the differences in x and y coordinates between the two points
DIF1 = x2 - x1  # Difference in x-coordinates
DIF2 = y2 - y1  # Difference in y-coordinates

# Calculate the coordinates of the third point based on the differences
x3 = x2 - DIF2  # x-coordinate of the third point
y3 = y2 + DIF1  # y-coordinate of the third point

# Calculate the coordinates of the fourth point based on the differences
x4 = x1 - DIF2  # x-coordinate of the fourth point
y4 = y1 + DIF1  # y-coordinate of the fourth point

# Print the coordinates of the third and fourth points
print(str(x3) + " " + str(y3) + " " + str(x4) + " " + str(y4))
