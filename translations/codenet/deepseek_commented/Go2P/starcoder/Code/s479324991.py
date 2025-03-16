import sys

def main():
	sc = NewScanner()

	# Read the number of elements
	n = sc.NextInt()
	
	# Initialize an array to hold the float values
	arr = make([]float, n)
	
	# Read each integer and convert it to float64, then store in the array
	for i in range(n):
		arr[i] = float(sc.NextInt())
	
	# Sort the array of float64 values
	arr.sort()
	
	# Initialize a variable to keep track of the running average
	prev = arr[0]
	
	# Iterate through the sorted array to calculate the average
	for i in range(1, len(arr)):
		prev = (prev + arr[i]) / 2

	# Print the final average
	print(prev)

class Scanner:
	def __init__(self):
		self.r = sys.stdin
		self.buf = ""
		self.p = 0
	def Next(self):
		self.pre()
		start = self.p
		while self.p < len(self.buf):
			if self.buf[self.p] =='':
				break
			self.p += 1
		result = self.buf[start:self.p]
		self.p += 1
		return result
	def NextInt(self):
		v, _ = self.Next().split()
		return int(v)
	def NextFloat(self):
		v, _ = self.Next().split()
		return float(v)
	def NextLine(self):
		self.pre()
		start = self.p
		self.p = len(self.buf)
		return self.buf[start:]
	def NextIntArray(self):
		self.pre()
		start = self.p
		result = []
		while self.p < len(self.buf):
			if self.buf[self.p] =='':
				v, _ = self.buf[start:self.p].split()
				result.append(int(v))
				start = self.p + 1
			self.p += 1
		v, _ = self.buf[start:self.p].split()
		result.append(int(v))
		return result
	def NextFloatArray(self):
		self.pre()
		start = self.p
		result = []
		while self.p < len(self.buf):
			if self.buf[self.p] =='':
				v, _ = self.buf[start:self.p].split()
				result.append(float(v))
				start = self.p + 1
			self.p += 1
		v, _ = self.buf[start:self.p].split()
		result.append(float(v))
		return result
	def NextMap(self):
		self.pre()
		start = self.p
		mp = {}
		while self.p < len(self.buf):
			if self.buf[self.p] =='':
				v, _ = self.buf[start:self.p].split()
				mp[int(v)] = True
				start = self.p + 1
			self.p += 1
		v, _ = self.buf[start:self.p].split()
		mp[int(v)] = True
		return mp
	def pre(self):
		if self.p >= len(self.buf):
			self.readLine()
			self.p = 0
	def readLine(self):
		self.buf = ""
		while True:
			l = self.r.readline()
			if l == "":
				break
			self.buf += l

