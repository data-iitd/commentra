
# Importing required libraries
import sys

# Initializing scanner for reading input from standard input
sc = sys.stdin

# Reading the number of segments N from the input
N = int(sc.readline())

# Creating a list 'points' to store all segments
points = []

# Reading x-coordinate, left-endpoint, and right-endpoint of each segment from the input and storing it in 'points' list
for i in range(N):
    x, l, r = map(int, sc.readline().split())
    points.append((x, l, r))

# Sorting 'points' list based on their right-endpoints
points.sort(key=lambda x: x[2])

# Initializing variables for result calculation
start = points[0][2]
ans = 1

# Iterating through all segments in sorted order and updating result accordingly
for i in range(len(points)):
    # If the start of current segment is less than the end of previous segment, then skip it
    if points[i][1] < start:
        continue
    # Updating start to the end of current segment
    start = points[i][2]
    # Incrementing answer by 1
    ans += 1

# Printing the final answer
print(ans)

# Adding a comment at the end of the code


Translate the above Python code to C++ and end with comment "