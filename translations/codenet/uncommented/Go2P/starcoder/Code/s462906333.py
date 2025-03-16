import sys

# const abcd = "abcdefghijklnmopqrstuvwxyz"
# const ABCD = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

# var dy = [...]int{1, 1, 0, -1, -1, -1, 0, 1}
# var dx = [...]int{0, 1, 1, 1, 0, -1, -1, -1}

# var dx = [...]int{0, 1, 0, -1}
# var dy = [...]int{1, 0, -1, 0}

# var inf int = 1e14

# var mod = 1000000007

# ---------------------------------------------------------
def main():
	next = newScanner()
	n = next.Int()
	x = next.Int()
	a = [0] * n
	for i in range(n):
		a[i] = next.Int()
	v = [0] * n
	copy(v, a)
	ans = inf
	for k in range(n):
		kans = 0
		for i in range(n):
			if i-k < 0:
				v[i] = min(v[i], a[n+i-k])
			else:
				v[i] = min(v[i], a[i-k])
			kans += v[i]
		ans = min(ans, kans+k*x)
	print(ans)

# ---------------------------------------------------------

# Pair is liked C++ pair
class Pair:
	def __init__(self, a, b):
		self.a = a
		self.b = b

# Pairs is sorted by []Pair struct
class Pairs:
	def __init__(self, p):
		self.p = p
	def Len(self):
		return len(self.p)
	def Swap(self, i, j):
		self.p[i], self.p[j] = self.p[j], self.p[i]
	def Less(self, i, j):
		if self.p[i].a < self.p[j].a:
			return True
		elif self.p[i].a == self.p[j].a:
			return self.p[i].b < self.p[j].b
		return False

# -------------------------------
def in(c, a, z):
	return c >= a and c < z

def btoi(b):
	if b:
		return 1
	return 0

def itob(a):
	if a == 0:
		return False
	return True

def max(a, b):
	if a > b:
		return b
	return a

def min(a, b):
	if a < b:
		return b
	return a

def minmax(a, b):
	if a > b:
		return b, a
	return a, b

def abs(a):
	if a < 0:
		return -a
	return a

def sum(a, b):
	return a + b

# ---------- buffered reader -----------------------------------------
class reader:
	def __init__(self):
		self.buf = []
		self.p = 0
		self.read()
	def read(self):
		self.buf = sys.stdin.buffer.readlines()
		self.p = 0
	def next(self):
		if self.p >= len(self.buf):
			self.read()
		self.p += 1
		return self.buf[self.p - 1].decode()
	def Int(self):
		return int(self.next())
	def Int64(self):
		return int(self.next())
	def Line(self):
		return self.next()

# ---------- main routine -----------------------------------------
if __name__ == "__main__":
	main()

# 