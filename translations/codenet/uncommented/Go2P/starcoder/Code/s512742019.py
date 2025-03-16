import sys

# I/O
def NewScanner():
	return bufio.Scanner(sys.stdin)

def NewScannerWords():
	return bufio.Scanner(sys.stdin)

def NewWriter():
	return bufio.Writer(sys.stdout)

def nextStr():
	return sys.stdin.readline().strip()

def nextInt():
	return int(nextStr())

def nextFloat():
	return float(nextStr())

def nextRuneSlice():
	return list(nextStr())

def nextIntSlice():
	line = nextStr()
	return [int(i) for i in line.split()]

def nextFloatSlice():
	line = nextStr()
	return [float(i) for i in line.split()]

# Arithmetic
def max(nums):
	return max(nums)

def min(nums):
	return min(nums)

def abs(x):
	return abs(x)

def pow(x, y):
	return pow(x, y)

def ceil(a, b):
	return a // b + (a % b > 0)

# Sort
def sort(nums):
	return sorted(nums)

# Main
MOD = 1000000007
INF = 1 << 60

class Mon:
	def __init__(self, x, h):
		self.x = x
		self.h = h

class Mons:
	def __init__(self, mons):
		self.mons = mons

	def Len(self):
		return len(self.mons)

	def Less(self, i, j):
		return self.mons[i].x < self.mons[j].x

	def Swap(self, i, j):
		self.mons[i], self.mons[j] = self.mons[j], self.mons[i]

class Node:
	def __init__(self, x, h):
		self.x = x
		self.h = h

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

def main():
	sc = NewScanner()
	wtr = NewWriter()
	N, D, A = nextInt(), nextInt(), nextInt()
	M = []
	for i in range(N):
		M.append(Mon(nextInt(), nextInt()))
	Mons(M).sort()
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
	print(ans)

if __name__ == "__main__":
	main()

