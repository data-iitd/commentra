import sys

def main():
	sc = NewScanner()
	H, W, N = sc.NextInt(), sc.NextInt(), sc.NextInt()

	A = max(H, W)

	print((N + A - 1) / A)

def max(a, b):
	if a < b:
		return b
	return a

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
		result, _ = self.NextInt64()
		return result

	def NextInt64(self):
		self.pre()
		start = self.p
		while self.p < len(self.buf):
			if self.buf[self.p] =='':
				break
			self.p += 1
		result, _ = int(self.buf[start:self.p]), self.p
		self.p += 1
		return result

	def NextFloat(self):
		self.pre()
		start = self.p
		while self.p < len(self.buf):
			if self.buf[self.p] =='':
				break
			self.p += 1
		result, _ = float(self.buf[start:self.p]), self.p
		self.p += 1
		return result

	def NextLine(self):
		self.pre()
		start = self.p
		self.p = len(self.buf)
		return self.buf[start:]

	def NextArray(self):
		self.pre()
		start = self.p
		result = []
		for self.p < len(self.buf):
			if self.buf[self.p] =='':
				break
			self.p += 1
		result.append(int(self.buf[start:self.p]))
		self.p += 1
		return result

	def NextInt64Array(self):
		self.pre()
		start = self.p
		result = []
		for self.p < len(self.buf):
			if self.buf[self.p] =='':
				break
			self.p += 1
		result.append(int(self.buf[start:self.p]))
		self.p += 1
		return result

	def NextMap(self):
		self.pre()
		start = self.p
		result = {}
		for self.p < len(self.buf):
			if self.buf[self.p] =='':
				break
			self.p += 1
		result[int(self.buf[start:self.p])] = True
		self.p += 1
		return result

	def pre(self):
		if self.p >= len(self.buf):
			self.readLine()
			self.p = 0

	def readLine(self):
		self.buf = self.r.readline()

