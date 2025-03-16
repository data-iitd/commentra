# I/O
# Initialize the scanner for input
sc = Scanner()
# Create a writer for output
wtr = Writer()

# Read N, D, A
N, D, A = sc.nextInt(), sc.nextInt(), sc.nextInt()
# Create a slice to hold monsters
M = []
for i in range(N):
	M.append(Mon(sc.nextInt(), sc.nextInt()))

# Sort monsters by their position
M.sort(key=lambda x: x.x)

# Define a constant for modulo operation
MOD = 1000000007
# Define a constant for infinity
INF = 1 << 60

# Mon represents a monster with position x and health h
class Mon:
	def __init__(self, x, h):
		self.x, self.h = x, h

# Mons is a slice of Mon for sorting
class Mons(list):
	def __init__(self, l):
		super().__init__(l)
	def __lt__(self, other):
		return self[0].x < other[0].x

# Node represents a position and damage
class Node:
	def __init__(self, x, h):
		self.x, self.h = x, h

# Queue is a simple queue implementation for Nodes
class Queue:
	def __init__(self):
		self.arr = []
	def push(self, v):
		self.arr.append(v)
	def first(self):
		return self.arr[0]
	def pop(self):
		res = self.arr[0]
		self.arr = self.arr[1:]
		return res
	def isEmpty(self):
		return len(self.arr) == 0

# max returns the maximum value from a list of integers
def max(*nums):
	m = nums[0]
	for i in nums:
		if m < i:
			m = i
	return m

# min returns the minimum value from a list of integers
def min(*nums):
	m = nums[0]
	for i in nums:
		if m > i:
			m = i
	return m

# abs returns the absolute value of an integer
def abs(x):
	if x > 0:
		return x
	return -x

# pow calculates x raised to the power of y
def pow(x, y):
	res = 1
	for i in range(y):
		res *= x
	return res

# ceil calculates the ceiling of a/b
def ceil(a, b):
	if a%b == 0:
		return a / b
	else:
		return a/b + 1

# Sort
# RuneSlice is a type that implements sort.Interface for slices of runes
class RuneSlice(list):
	def __init__(self, l):
		super().__init__(l)
	def __lt__(self, other):
		return self[0] < other[0]

# Main
# Define a constant for modulo operation
MOD = 1000000007
# Define a constant for infinity
INF = 1 << 60

# Mon represents a monster with position x and health h
class Mon:
	def __init__(self, x, h):
		self.x, self.h = x, h

# Mons is a slice of Mon for sorting
class Mons(list):
	def __init__(self, l):
		super().__init__(l)
	def __lt__(self, other):
		return self[0].x < other[0].x

# Node represents a position and damage
class Node:
	def __init__(self, x, h):
		self.x, self.h = x, h

# Queue is a simple queue implementation for Nodes
class Queue:
	def __init__(self):
		self.arr = []
	def push(self, v):
		self.arr.append(v)
	def first(self):
		return self.arr[0]
	def pop(self):
		res = self.arr[0]
		self.arr = self.arr[1:]
		return res
	def isEmpty(self):
		return len(self.arr) == 0

# main function to execute the program logic
def main():
	# Initialize the scanner for input
	sc = Scanner()
	# Create a writer for output
	wtr = Writer()

	# Read N, D, A
	N, D, A = sc.nextInt(), sc.nextInt(), sc.nextInt()
	# Create a slice to hold monsters
	M = []
	for i in range(N):
		M.append(Mon(sc.nextInt(), sc.nextInt()))

	# Sort monsters by their position
	M.sort(key=lambda x: x.x)

	# Initialize a queue to manage damage
	q = Queue()
	ans = 0    # Variable to count the total number of attacks
	total = 0  # Variable to track total damage dealt

	# Iterate through each monster
	for i in range(N):
		m = M[i] # Get the current monster
		# Remove monsters from the queue that are out of range
		for not q.isEmpty() and q.first().x < m.x:
			total -= q.pop().h # Decrease total damage by the damage of the popped monster
		# If the total damage is less than the monster's health
		if total < m.h:
			m.h -= total # Reduce the monster's health by total damage
			count = ceil(m.h, A) # Calculate how many attacks are needed
			ans += count # Increment the total attack count
			damage = count * A # Calculate the total damage dealt to this monster
			q.push(Node(m.x + 2*D, damage)) # Add the monster's damage to the queue
			total += damage # Update the total damage
	# Output the total number of attacks
	fmt.Fprintln(wtr, ans)
	wtr.Flush() # Flush the writer to ensure all output is written

