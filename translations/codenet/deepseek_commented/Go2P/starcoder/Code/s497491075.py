import sys

# Run function reads input from the reader, processes it, and writes the output to the writer.
def Run(r, w):
	# Create a scanner to read from input.
	sc = NewScanner(r)

	# Read the first line which contains two integers N and D.
	a = sc.ReadLine().Ints()
	N, D = a[0], a[1]

	# Read the next N lines which contain pairs of integers representing points.
	lines = sc.ReadLines(N).Ints()

	# Initialize a counter to keep track of points within the given distance.
	count = 0

	# Iterate over each point and calculate the distance from the origin.
	for _, line in lines:
		# Calculate the Euclidean distance of the point from the origin.
		d = math.sqrt(float(line[0]*line[0] + line[1]*line[1]))
		# Check if the distance is within the given limit.
		if float(D) >= d:
			count += 1

	# Write the count of points within the distance to the writer.
	fmt.Fprintln(w, count)

# main function initializes the Run function with sys.stdin and sys.stdout.
def main():
	Run(sys.stdin, sys.stdout)

# Scanner struct is used to read input efficiently.
class Scanner:
	def __init__(self, r):
		self.r = r
		self.buf = ""
	def Scan(self):
		if self.buf == "":
			self.buf = self.r.readline()
		if self.buf == "":
			return False
		self.buf = self.buf.lstrip()
		return True
	def ReadLine(self):
		if self.Scan():
			self.buf = self.buf.rstrip()
			return self.buf
		return ""
	def ReadLines(self, n):
		a = []
		for i in range(n):
			a.append(self.ReadLine())
		return a
	def Ints(self):
		return [int(x) for x in self.ReadLine().split(" ")]
	def Float64s(self):
		return [float(x) for x in self.ReadLine().split(" ")]
	def Runes(self):
		return [x for x in self.ReadLine()]
	def String(self):
		return self.buf

# Value type represents a string value which can be converted to various data types.
class Value:
	def __init__(self, s):
		self.s = s
	def String(self):
		return self.s
	def Int(self):
		return int(self.s)
	def Float64(self):
		return float(self.s)
	def Strings(self):
		return self.s.split(" ")
	def Ints(self):
		return [int(x) for x in self.Strings()]
	def Float64s(self):
		return [float(x) for x in self.Strings()]
	def Runes(self):
		return [x for x in self.s]

# Values is a slice of Value.
class Values:
	def __init__(self, a):
		self.a = a
	def Strings(self):
		return [x.Strings() for x in self.a]
	def Ints(self):
		return [x.Ints() for x in self.a]
	def Float64s(self):
		return [x.Float64s() for x in self.a]
	def Runes(self):
		return [x.Runes() for x in self.a]

# NewScanner creates a new Scanner instance with the given reader.
def NewScanner(r):
	return Scanner(r)

# main function initializes the Run function with sys.stdin and sys.stdout.
main()

# 