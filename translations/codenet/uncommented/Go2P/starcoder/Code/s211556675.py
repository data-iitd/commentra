import sys

# I/O
def NewScanner():
	return bufio.NewScanner(sys.stdin)

def nextStr():
	return s.next()

def nextInt():
	return int(s.next())

def nextFloat():
	return float(s.next())

def nextRuneSlice():
	return list(s.next())

def nextIntSlice(n):
	return [int(s.next()) for _ in range(n)]

def nextFloatSlice(n):
	return [float(s.next()) for _ in range(n)]

# Arithmetic
def max(nums):
	m = nums[0]
	for _, i in enumerate(nums):
		if m < i:
			m = i
	return m

def min(nums):
	m = nums[0]
	for _, i in enumerate(nums):
		if m > i:
			m = i
	return m

def abs(x):
	if x > 0:
		return x
	return -x

def pow(x, y):
	res = 1
	for i in range(y):
		res *= x
	return res

# Sort
class Val:
	def __init__(self, id, num):
		self.id = id
		self.num = num

class ByNum(list):
	def __init__(self, vals):
		self.vals = vals
		self.sort()

	def sort(self):
		self.vals.sort(key=lambda x: x.num)

	def __len__(self):
		return len(self.vals)

	def __getitem__(self, i):
		return self.vals[i]

	def __setitem__(self, i, v):
		self.vals[i] = v

	def __delitem__(self, i):
		del self.vals[i]

	def __iter__(self):
		return iter(self.vals)

	def __reversed__(self):
		return reversed(self.vals)

	def __contains__(self, x):
		return x in self.vals

	def __add__(self, x):
		return self.vals + x

	def __iadd__(self, x):
		self.vals += x
		return self

	def __mul__(self, x):
		return self.vals * x

	def __imul__(self, x):
		self.vals *= x
		return self

	def __rmul__(self, x):
		return self.vals * x

	def __imul__(self, x):
		self.vals *= x
		return self

	def __repr__(self):
		return repr(self.vals)

	def __str__(self):
		return str(self.vals)

# Main
s = NewScanner()
wtr = sys.stdout
A, B, C, K = nextInt(), nextInt(), nextInt(), nextInt()
ma = max(A, B, C)
rest = 0
if ma == A:
	rest += B + C
elif ma == B:
	rest += A + C
else:
	rest += A + B
for i in range(1, K+1):
	ma *= 2

print(ma+rest)

