
import sys

# Read the first line which contains two integers N and D.
N, D = map(int, sys.stdin.readline().split())

# Read the next N lines which contain pairs of integers representing points.
lines = []
for i in range(N):
    lines.append(list(map(int, sys.stdin.readline().split())))

# Initialize a counter to keep track of points within the given distance.
count = 0

# Iterate over each point and calculate the distance from the origin.
for line in lines:
    # Calculate the Euclidean distance of the point from the origin.
    d = (line[0]**2 + line[1]**2)**0.5
    # Check if the distance is within the given limit.
    if D >= d:
        count += 1

# Write the count of points within the distance to the writer.
print(count)

