import sys

def Run(r, w):
	sc = NewScanner(r)

	a = sc.ReadLine().Ints()
	N, D = a[0], a[1]

	lines = sc.ReadLines(N).Ints()

	count = 0
	for _, line in lines:
		d = math.sqrt(line[0]*line[0] + line[1]*line[1])
		if float(D) >= d:
			count += 1
	print(count)

def main():
	Run(sys.stdin, sys.stdout)

class Value:
	def __init__(self, s):
		self.s = s

	def String(self):
		return self.s

	def Int(self):
		return int(self.s)

	def Float64(self):
		return float(self.s)

	def Strings(self):
		return self.s.split(" ")

	def Ints(self):
		return [int(s) for s in self.Strings()]

	def Float64s(self):
		return [float(s) for s in self.Strings()]

	def Runes(self):
		return [rune(c) for c in self.s]

class Values:
	def __init__(self, vs):
		self.vs = vs

	def Strings(self):
		return [value.Strings() for value in self.vs]

	def Ints(self):
		return [value.Ints() for value in self.vs]

	def Float64s(self):
		return [value.Float64s() for value in self.vs]

	def Runes(self):
		return [value.Runes() for value in self.vs]

class Scanner:
	def __init__(self, r):
		self.sc = r

	def ReadLine(self):
		return Value(self.sc.readline())

	def ReadLines(self, n):
		return Values([self.ReadLine() for i in range(n)])

def NewScanner(r):
	return Scanner(r)

