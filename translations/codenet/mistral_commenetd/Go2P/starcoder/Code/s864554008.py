
# Define a custom data structure
class data:
	def __init__(self):
		# Read dimensions from user input
		self.n, self.m = map(int, input().split())
		# Load image data as strings
		self.nImg = self.load(self.n)
		self.mImg = self.load(self.m)

	# Load image data as strings
	def load(self, cnt):
		# Allocate memory for image data
		ret = [None] * cnt
		# Read image data from user input
		for i in range(cnt):
			ret[i] = input()

		# Return loaded image data
		return ret

	# Check if data already exists in the larger image
	def exist(self):
		# Iterate through all possible positions in larger image
		for i in range(self.n-self.m+1):
			for j in range(self.n-self.m+1):
				# Check if current position matches the smaller image
				if self.match(i, j):
					# If match is found, return true
					return True

		# If no match is found, return false
		return False

	# Check if smaller image matches at current position in larger image
	def match(self, x, y):
		# Iterate through each pixel in smaller image
		for i in range(self.m):
			for j in range(self.m):
				# Check if corresponding pixel in larger image matches
				if self.nImg[x+i][y+j]!= self.mImg[i][j]:
					# If mismatch is found, return false
					return False

		# If all pixels match, return true
		return True

# Main function
if __name__ == "__main__":
	# Initialize a new data object
	d = data()
	# Check if data already exists
	if d.exist():
		print("Yes")
	else:
		print("No")

