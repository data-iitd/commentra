
# Define a class named Cube with a public array 'f' of size 6
class Cube:
	def __init__(self):
		self.f = [0] * 6	# Initialize an integer array 'f' of size 6

	def roll_z(self):	# Function to roll the cube along z-axis
		t = self.f[1]
		self.f[1] = self.f[2]
		self.f[2] = t
		t = self.f[3]
		self.f[3] = self.f[4]
		self.f[4] = t

	def roll_y(self):	# Function to roll the cube along y-axis
		t = self.f[0]
		self.f[0] = self.f[2]
		self.f[2] = self.f[5]
		self.f[5] = t
		t = self.f[3]
		self.f[3] = self.f[4]
		self.f[4] = t

	def roll_x(self):	# Function to roll the cube along x-axis
		t = self.f[0]
		self.f[0] = self.f[1]
		self.f[1] = self.f[5]
		self.f[5] = t
		t = self.f[4]
		self.f[4] = self.f[3]
		self.f[3] = t

	def roll(self, i, j, k, l):	# Function to roll the cube in a specific direction
		t = self.f[i]
		self.f[i] = self.f[j]
		self.f[j] = t
		t = self.f[j]
		self.f[j] = self.f[k]
		self.f[k] = t
		t = self.f[k]
		self.f[k] = self.f[l]
		self.f[l] = t

# Function to check if two cubes are equal
def eq(c1, c2):
	for i in range(6):	# Iterate through each element of the first cube 'c1'
		if c1.f[i]!= c2.f[i]:	# If any element is not equal, return false
			return False
	return True		# If all elements are equal, return true

# Function to check if two cubes are equal after rolling
def equal(c1, c2):
	for i in range(6):	# Iterate through each rolling direction for the first cube 'c1'
		for j in range(4):	# Iterate through each rolling step in the current direction
			if eq(c1, c2):	# If the cubes are equal, return true
				return True
			c1.roll_z()	# Roll the cube along z-axis
		if i % 2 == 0:c1.roll_y()	# Roll the cube along y-axis if the current index 'i' is even
		else c1.roll_x()		# Roll the cube along x-axis if the current index 'i' is odd
	return False		# If the cubes are not equal after all rolling directions and steps, return false

# Main function to read the cubes' states and compare them
c1 = Cube()		# Initialize two empty cubes 'c1' and 'c2'
c2 = Cube()

# Read the states of the cubes from the standard input
for i in range(6):
	c1.f[i] = int(input())
for i in range(6):
	c2.f[i] = int(input())

# Compare the cubes and print the result
if equal(c1, c2):
	print("Yes")
else:
	print("No")

