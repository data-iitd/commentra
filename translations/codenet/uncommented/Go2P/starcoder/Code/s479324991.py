import sys

def main():
	sc = NewScanner()

	n = sc.NextInt()
	arr = []
	for i in range(n):
		arr.append(sc.NextInt())
	arr.sort()
	prev = arr[0]
	for i in range(1, len(arr)):
		prev = (prev + arr[i]) / 2
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
		v, _ = int(self.Next()), None
		return v
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
				v, _ = int(self.buf[start:self.p]), None
				result.append(v)
				start = self.p + 1
			self.p += 1
		v, _ = int(self.buf[start:self.p]), None
		result.append(v)
		return result
	def NextMap(self):
		self.pre()
		start = self.p
		mp = {}
		while self.p < len(self.buf):
			if self.buf[self.p] =='':
				v, _ = int(self.buf[start:self.p]), None
				mp[v] = True
				start = self.p + 1
			self.p += 1
		v, _ = int(self.buf[start:self.p]), None
		mp[v] = True
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

