import sys

def main():
	sc = NewScanner()

	n = sc.NextInt()
	ans = 0.0
	for i in range(n):
		tmp = 1 / float(sc.NextInt())
		ans += tmp
	print(1/ans)

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
		return int(self.Next())

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
				result.append(int(self.buf[start:self.p]))
				start = self.p + 1
			self.p += 1
		result.append(int(self.buf[start:self.p]))
		return result

	def NextMap(self):
		self.pre()
		start = self.p
		mp = {}
		while self.p < len(self.buf):
			if self.buf[self.p] =='':
				v = int(self.buf[start:self.p])
				mp[v] = True
				start = self.p + 1
			self.p += 1
		v = int(self.buf[start:self.p])
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
			self.buf += l
			if not l:
				break

