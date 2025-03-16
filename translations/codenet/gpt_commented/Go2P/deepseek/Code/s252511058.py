import sys

# nextInt reads the next integer from the scanner and returns it.
def nextInt(sc):
    return int(sc.readline().strip())

# point class represents a point with its position and its left and right bounds.
class Point:
    def __init__(self, x, l):
        self.x = x
        self.l = x - l
        self.r = x + l

# Read the number of points
N = nextInt(sys.stdin)
points = []

# Read each point's position and calculate its left and right bounds
for _ in range(N):
    x = nextInt(sys.stdin)
    l = nextInt(sys.stdin)
    points.append(Point(x, l))

# Sort the points based on their right bounds
points.sort(key=lambda p: p.r)

# Initialize the scheduling process for the interval scheduling problem
start = points[0].r
ans = 1

# Iterate through the sorted points to count non-overlapping intervals
for p in points:
    if p.l < start:
        continue
    start = p.r
    ans += 1

# Output the total number of non-overlapping intervals
print(ans)
