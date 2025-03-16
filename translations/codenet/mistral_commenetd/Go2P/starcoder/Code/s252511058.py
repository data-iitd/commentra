import sys

# Initializing scanner for reading input from standard input
sc = sys.stdin

# Defining a custom type 'point' for storing x-coordinate, left-endpoint, and right-endpoint of a segment
class point:
	def __init__(self, x, l, r):
		self.x = x
		self.l = l
		self.r = r

# Defining a slice 'ps' of type 'point' for storing all segments in sorted order based on their right-endpoints
class ps(list):
	def __init__(self, points):
		super().__init__(points)
	def __lt__(self, other):
		return self[0].r < other[0].r

# Main function starts here
if __name__ == "__main__":
	# Reading the number of segments N from the input
	N = int(sc.readline())
	# Creating a slice 'points' of type 'point' to store all segments
	points = []
	# Reading x-coordinate, left-endpoint, and right-endpoint of each segment from the input and storing it in 'points' slice
	for i in range(N):
		x, l = map(int, sc.readline().split())
		# Calculating right endpoint of the segment based on x-coordinate and left-endpoint
		r = x + l
		points.append(point(x, l, r))
	# Sorting 'points' slice based on their right-endpoints
	points.sort()
	# Initializing variables for result calculation
	start = points[0].r
	ans = 1
	# Iterating through all segments in sorted order and updating result accordingly
	for i in range(len(points)):
		# If the start of current segment is less than the end of previous segment, then skip it
		if points[i].l < start:
			continue
		# Updating start to the end of current segment
		start = points[i].r
		# Incrementing answer by 1
		ans += 1
	# Printing the final answer
	print(ans)

# Adding a comment at the end of the code

