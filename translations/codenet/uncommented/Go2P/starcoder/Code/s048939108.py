import sys

def main():
	sc = newScanner()
	S = sc.next()
	if S.startswith("YAKI"):
		print("Yes")
	else:
		print("No")

def min(a, b):
	if a > b:
		return b
	return a

def max(a, b):
	if a > b:
		return a
	return b

class scanner:
	def __init__(self):
		self.r = bufio.NewReaderSize(sys.stdin, 1000)
		self.buf = ""
		self.p = 0
	def next(self):
		self.pre()
		start = self.p
		while self.p < len(self.buf):
			if self.buf[self.p] =='':
				break
			self.p += 1
		result = self.buf[start:self.p]
		self.p += 1
		return result
	def nextLine(self):
		self.pre()
		start = self.p
		self.p = len(self.buf)
		return self.buf[start:]
	def nextInt(self):
		result, _ = int(self.next()), None
		return result
	def nextIntArray(self):
		self.pre()
		start = self.p
		result = []
		while self.p < len(self.buf)+1:
			if self.p == len(self.buf) or self.buf[self.p] =='':
				result.append(int(self.buf[start:self.p]))
				start = self.p + 1
			self.p += 1
		return result
	def pre(self):
		if self.p >= len(self.buf):
			self.readLine()
			self.p = 0
	def readLine(self):
		self.buf = ""
		for {
			l, p, e = self.r.ReadLine()
			if e!= None:
				panic(e)
			self.buf += l
			if not p:
				break
		}

if __name__ == "__main__":
	main()

