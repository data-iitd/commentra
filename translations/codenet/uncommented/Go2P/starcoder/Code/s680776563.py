import sys

def main():
	fsc = NewFastScanner()
	A, B, C = fsc.NextInt(), fsc.NextInt(), fsc.NextInt()
	if B-A == C-B:
		print("YES")
	else:
		print("NO")

#template
class FastScanner:
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
		v, _ = int(self.Next()), None
		return v
	def NextInt64(self):
		v, _ = int(self.Next()), None
		return v
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

#Max,Min
def IntMax(a, b):
	if a < b:
		return b
	return a

def Int64Max(a, b):
	if a < b:
		return b
	return a
def Float64Max(a, b):
	if a < b:
		return b
	return a

def IntMin(a, b):
	if a > b:
		return b
	return a

def Int64Min(a, b):
	if a > b:
		return b
	return a
def Float64Min(a, b):
	if a > b:
		return b
	return a

#Gcd
def IntGcd(a, b):
	if a < b:
		b, a = a, b
	if b == 0:
		return a
	return IntGcd(b, a%b)

def Int64Gcd(a, b):
	if a < b:
		b, a = a, b
	if b == 0:
		return a
	return Int64Gcd(b, a%b)

def IntAbs(a):
	if a < 0:
		a *= -1
	return a

def Int64Abs(a):
	if a < 0:
		a *= -1
	return a

