import sys

# Initializes a new Scanner instance to read from standard input.
def main():
	sc = NewScanner()
	
	# Reads three integers H, W, and N from the standard input.
	H, W, N = sc.NextInt(), sc.NextInt(), sc.NextInt()
	
	# Determines the maximum of H and W and assigns it to A.
	A = max(H, W)
	
	# Calculates the result by dividing N by A and rounding up.
	# This is done by adding N-1 to the division result and then performing integer division by A.
	print((N + A - 1) / A)

# Returns the maximum of two integers.
def max(a, b):
	if a < b:
		return b
	return a

# Scanner struct to read input efficiently.
class Scanner:
	def __init__(self):
		self.r = sys.stdin
		self.buf = ""
		self.p = 0
	
	# Reads the next token from the input buffer.
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
	
	# Reads the next line from the input buffer.
	def NextLine(self):
		self.pre()
		start = self.p
		self.p = len(self.buf)
		return self.buf[start:]
	
	# Reads the next integer from the input buffer.
	def NextInt(self):
		v, _ = int(self.Next()), None
		return v
	
	# Reads the next 64-bit integer from the input buffer.
	def NextInt64(self):
		v, _ = int(self.Next()), None
		return v
	
	# Reads the next float from the input buffer.
	def NextFloat(self):
		v, _ = float(self.Next()), None
		return v
	
	# Reads the next array of integers from the input buffer.
	def NextIntArray(self):
		self.pre()
		start = self.p
		result = []
		for self.p < len(self.buf)+1:
			if self.p == len(self.buf) or self.buf[self.p] =='':
				v, _ = int(self.buf[start:self.p]), None
				result.append(v)
				start = self.p + 1
		return result
	
	# Reads the next array of 64-bit integers from the input buffer.
	def NextInt64Array(self):
		self.pre()
		start = self.p
		result = []
		for self.p < len(self.buf)+1:
			if self.p == len(self.buf) or self.buf[self.p] =='':
				v, _ = int(self.buf[start:self.p]), None
				result.append(v)
				start = self.p + 1
		return result
	
	# Reads the next map of integers from the input buffer.
	def NextMap(self):
		self.pre()
		start = self.p
		mp = {}
		for self.p < len(self.buf):
			if self.buf[self.p] =='':
				v, _ = int(self.buf[start:self.p]), None
				mp[v] = True
				start = self.p + 1
		v, _ = int(self.buf[start:self.p]), None
		mp[v] = True
		return mp
	
	# Ensures that the buffer has data before reading.
	def pre(self):
		if self.p >= len(self.buf):
			self.readLine()
			self.p = 0
	
	# Reads the entire line from the input buffer.
	def readLine(self):
		self.buf = ""
		for l in self.r:
			self.buf += l
		self.buf += "\n"

# 