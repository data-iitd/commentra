# Define a class to hold the dimensions and images
class data:
	def __init__(self):
		self.n = 0
		self.m = 0
		self.nImg = []
		self.mImg = []

	# Function to read input dimensions and images, returning a data instance
	def newData(self):
		self.n, self.m = map(int, input().split())
		self.nImg = self.load(self.n)
		self.mImg = self.load(self.m)

	# Function to load an image of given count from standard input
	def load(self, cnt):
		ret = []
		for i in range(cnt):
			ret.append(input())
		return ret

	# Method to check if the second image exists within the first image
	def exist(self):
		for i in range(self.n-self.m+1):
			for j in range(self.n-self.m+1):
				if self.match(i, j):
					return True
		return False

	# Method to check if the second image matches the first image at a specific position
	def match(self, x, y):
		for i in range(self.m):
			for j in range(self.m):
				if self.nImg[x+i][y+j]!= self.mImg[i][j]:
					return False
		return True

# Create a new data instance and check for the existence of a match
d = data()
d.newData()
if d.exist():
	print("Yes")
else:
	print("No")

