import sys

def main():
	io, flash = NewIO()
	defer flash()

	n, t, a = io.ScanInt(), io.ScanFloat64(), io.ScanFloat64()
	heights = io.ScanFloat64s(n)

	minDiff = abs(t-heights[0]*0.006-a)
	minIdx = 0
	for i, h in enumerate(heights[1:]):
		diff = abs(t-h*0.006-a)
		if diff < minDiff:
			minDiff = diff
			minIdx = i + 1
	io.Println(minIdx + 1)

def NewIO():
	io = IO(sys.stdin, sys.stdout)
	return io, io.Flush

class IO(object):
	def __init__(self, stdin, stdout):
		self.stdin = stdin
		self.stdout = stdout
		self.buffer = ""

	def Scan(self):
		if self.buffer == "":
			self.buffer = self.stdin.readline().strip()
		words = self.buffer.split(" ")
		self.buffer = ""
		return words

	def ScanInt(self):
		return int(self.Scan()[0])

	def ScanFloat(self):
		return float(self.Scan()[0])

	def ScanFloats(self, n):
		return [float(self.Scan()[i]) for i in range(n)]

	def ScanString(self):
		return self.Scan()[0]

	def ScanStrings(self, n):
		return self.Scan()[0:n]

	def Print(self, a):
		self.stdout.write(str(a) + "\n")

	def Println(self, a):
		self.stdout.write(str(a) + "\n")

	def Flush(self):
		self.stdout.flush()

# 