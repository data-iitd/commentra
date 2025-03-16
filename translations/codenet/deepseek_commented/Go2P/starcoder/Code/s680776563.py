
import sys

# Main function: Entry point of the program.
# Initializes a FastScanner, reads three integers A, B, and C,
# and checks if the difference between consecutive integers is the same.
# If the difference is the same, it prints "YES"; otherwise, it prints "NO".
def main():
	fsc = NewFastScanner()
	A, B, C = fsc.NextInt(), fsc.NextInt(), fsc.NextInt()
	if B-A == C-B:
		print("YES")
	else:
		print("NO")

# FastScanner struct: Efficiently reads input.
class FastScanner:
	def __init__(self):
		self.r = sys.stdin
		self.buf = ""
		self.p = 0

	# Next: Reads the next token from the input.
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

	# NextLine: Reads the next line from the input.
	def NextLine(self):
		self.pre()
		start = self.p
		self.p = len(self.buf)
		return self.buf[start:]

	# NextInt: Reads the next integer from the input.
	def NextInt(self):
		v, _ = int(self.Next()), None
		return v

	# NextInt64: Reads the next 64-bit integer from the input.
	def NextInt64(self):
		v, _ = int(self.Next()), None
		return v

	# pre: Ensures that the buffer has data to read.
	def pre(self):
		if self.p >= len(self.buf):
			self.readLine()
			self.p = 0

	# readLine: Reads the entire line from the input and stores it in the buffer.
	def readLine(self):
		self.buf = ""
		for l in self.r:
			self.buf += l
			if l == "\n":
				break

# Max, Min, Gcd, Abs functions: Utility functions for various operations.
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

# 