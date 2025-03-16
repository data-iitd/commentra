import sys

def main():
	sc = NewScanner()
	A, B = sc.NextInt(), sc.NextInt()

	mx = max(A+B, A-B)
	mx = max(mx, A*B)
	print(mx)

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

	def NextLine(self):
		self.pre()
		start = self.p
		self.p = len(self.buf)
		return self.buf[start:]

	def NextInt(self):
		result, _ = self.Next().split()
		return int(result)

	def NextInt64(self):
		result, _ = self.Next().split()
		return int(result)

	def NextFloat(self):
		result, _ = self.Next().split()
		return float(result)

	def NextIntArray(self):
		self.pre()
		start = self.p
		result = []
		for self.p < len(self.buf)+1:
			if self.p == len(self.buf) or self.buf[self.p] =='':
				result.append(int(self.buf[start:self.p]))
				start = self.p + 1
			self.p += 1
		return result

	def NextInt64Array(self):
		self.pre()
		start = self.p
		result = []
		for self.p < len(self.buf)+1:
			if self.p == len(self.buf) or self.buf[self.p] =='':
				result.append(int(self.buf[start:self.p]))
				start = self.p + 1
			self.p += 1
		return result

	def NextMap(self):
		self.pre()
		start = self.p
		mp = {}
		for self.p < len(self.buf):
			if self.buf[self.p] =='':
				result, _ = self.buf[start:self.p].split()
				mp[int(result)] = True
				start = self.p + 1
			self.p += 1
		result, _ = self.buf[start:self.p].split()
		mp[int(result)] = True
		return mp

	def pre(self):
		if self.p >= len(self.buf):
			self.readLine()
			self.p = 0

	def readLine(self):
		self.buf = ""
		for line in self.r:
			self.buf += line
		self.p = 0

if __name__ == "__main__":
	main()

