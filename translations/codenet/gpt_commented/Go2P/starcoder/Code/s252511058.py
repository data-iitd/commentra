import sys

# nextInt reads the next integer from the scanner and returns it.
def nextInt(sc):
	sc.readline() # Read the next token
	return int(sc.readline()) # Convert the token to an integer

# point struct represents a point with its position and its left and right bounds.
class point:
	def __init__(self, x, l, r):
		self.x = x # x is the position, l is the left bound, r is the right bound
		self.l = l
		self.r = r

# ps is a slice of point, implementing sort.Interface.
class ps(list):
	# Len returns the number of points in the slice.
	def Len(self):
		return len(self)

	# Swap exchanges the points at indices i and j.
	def Swap(self, i, j):
		self[i], self[j] = self[j], self[i]

	# Less reports whether the point at index i should sort before the point at index j.
	def Less(self, i, j):
		return self[i].r < self[j].r # Sort by the right bound

def main():
	sc = sys.stdin # Create a new scanner for standard input
	sc.readline() # Read the number of points
	N = int(sc.readline()) # Read the number of points
	points = [] # Create a slice to hold the points

	# Read each point's position and calculate its left and right bounds
	for i in range(N):
		x = int(sc.readline()) # Read the position of the point
		L = int(sc.readline()) # Read the length to calculate bounds
		points.append(point(x, x - L, x + L)) # Create a point and append it to the slice

	# Sort the points based on their right bounds
	points.sort(key=lambda p: p.r)

	# Initialize the scheduling process for the interval scheduling problem
	start = points[0].r # Start with the right bound of the first point
	ans = 1 # Initialize the count of non-overlapping intervals

	# Iterate through the sorted points to count non-overlapping intervals
	for i in range(len(points)):
		if points[i].l < start: # If the left bound overlaps with the current start
			continue # Skip to the next point
		start = points[i].r # Update the start to the right bound of the current point
		ans += 1 # Increment the count of non-overlapping intervals

	# Output the total number of non-overlapping intervals
	print(ans)

# 