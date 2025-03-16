import sys
import bisect

# nextInt reads the next word from the input, converts it to an integer, and returns it.
def nextInt(input):
	return int(input.readline())

# point represents a point with x, l (left boundary), and r (right boundary).
class point:
	def __init__(self, x, l, r):
		self.x = x
		self.l = l
		self.r = r

# main function is the entry point of the program.
def main():
	N = nextInt(sys.stdin) # Read the number of points.
	points = []
	for i in range(N):
		x = nextInt(sys.stdin) # Read the x-coordinate of the point.
		L = nextInt(sys.stdin) # Read the length L.
		points.append(point(x, x - L, x + L))
	points.sort(key=lambda p: p.r) # Sort the points by their right boundary.
	# Now we have a list of intervals. We need to select the maximum number of non-overlapping intervals.
	start = points[0].r # Initialize the start of the first interval.
	ans = 1 # Initialize the answer (at least one interval is selected).
	for i in range(len(points)):
		if points[i].l < start: # If the current interval overlaps with the previous one, skip it.
			continue
		start = points[i].r # Move to the next interval.
		ans += 1 # Increment the count of selected intervals.
	print(ans) # Print the number of selected intervals.

# 