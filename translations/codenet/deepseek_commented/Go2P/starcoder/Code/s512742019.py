import sys

MOD = 1000000007
INF = 1 << 60

# Custom type RuneSlice to implement sort.Interface for sorting rune slices.
class RuneSlice(list):
	def __lt__(self, other):
		return self[0] < other[0]

# Constants MOD and INF for modular arithmetic and infinite values.
# Mon struct and Mons type for monsters.
class Mon:
	def __init__(self, x, h):
		self.x = x
		self.h = h

class Mons(list):
	def __lt__(self, other):
		return self[0].x < other[0].x

# Queue struct to manage a queue of nodes.
# Methods include pushing, popping, and checking if the queue is empty.
class Queue:
	def __init__(self):
		self.arr = []

	def push(self, v):
		self.arr.append(v)

	def first(self):
		return self.arr[0]

	def pop(self):
		res = self.arr[0]
		self.arr = self.arr[1:]
		return res

	def isEmpty(self):
		return len(self.arr) == 0

def max(nums):
	m = nums[0]
	for i in nums:
		if m < i:
			m = i
	return m

def min(nums):
	m = nums[0]
	for i in nums:
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

def ceil(a, b):
	if a%b == 0:
		return a / b
	else:
		return a/b + 1

def main():
	sc = Scanner()
	wtr = Writer()
	N, D, A = sc.nextInt(), sc.nextInt(), sc.nextInt()
	M = []
	for i in range(N):
		M.append(Mon(sc.nextInt(), sc.nextInt()))
	M.sort()
	q = Queue()
	ans = 0
	total = 0
	for i in range(N):
		m = M[i]
		for not q.isEmpty() and q.first().x < m.x:
			total -= q.pop().h
		if total < m.h:
			m.h -= total
			count = ceil(m.h, A)
			ans += count
			damage = count * A
			q.push(Node(m.x + 2*D, damage))
			total += damage
	wtr.write(str(ans) + '\n')
	wtr.flush()

class Scanner:
	def __init__(self):
		self.buf = ""
		self.sc = bufio.Scanner(sys.stdin)
		self.sc.split(lambda x: x.isspace())
		self.sc.split(lambda x: x == ',')

	def nextStr(self):
		if self.buf!= "":
			tmp = self.buf
			self.buf = ""
			return tmp
		else:
			self.sc.scan()
			return self.sc.text()

	def nextInt(self):
		if self.buf!= "":
			tmp = int(self.buf)
			self.buf = ""
			return tmp
		else:
			self.sc.scan()
			return int(self.sc.text())

	def nextFloat(self):
		if self.buf!= "":
			tmp = float(self.buf)
			self.buf = ""
			return tmp
		else:
			self.sc.scan()
			return float(self.sc.text())

	def nextRuneSlice(self):
		return list(self.nextStr())

	def nextIntSlice(self, n):
		res = []
		for i in range(n):
			res.append(self.nextInt())
		return res

	def nextFloatSlice(self, n):
		res = []
		for i in range(n):
			res.append(self.nextFloat())
		return res

class Writer:
	def __init__(self):
		self.buf = ""

	def write(self, s):
		self.buf += s

	def flush(self):
		sys.stdout.write(self.buf)
		self.buf = ""

# 