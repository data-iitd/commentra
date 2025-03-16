import sys
import math

mod = 1000000007
INF = 1000000007

def main():
	r = sys.stdin.readline
	var n, m, R int
	n, m, R = map(int, r().split())
	rs = [int(x) for x in r().split()]
	rs = rs[:R]

	costs = [[INF] * n for _ in range(n)]
	for i in range(n):
		costs[i][i] = 0
	var a, b, c int
	for i in range(m):
		a, b, c = map(int, r().split())
		a -= 1
		b -= 1
		costs[a][b] = c
		costs[b][a] = c

	# Warshall-Floyd
	for k in range(n):
		for i in range(n):
			for j in range(n):
				costs[i][j] = min(costs[i][j], costs[i][k]+costs[k][j])

	# permutation
	perms = permutations(rs)
	ans = INF
	for perm in perms:
		tmp = 0
		for j in range(1, len(perm)):
			from_ = perm[j-1]
			to_ = perm[j]
			tmp += costs[from_][to_]
		ans = min(ans, tmp)
	print(ans)

# permutations
def permutations(arr):
	def helper(arr, n):
		if n == 1:
			tmp = [0] * len(arr)
			for i in range(len(arr)):
				tmp[i] = arr[i]
			res.append(tmp)
		else:
			for i in range(n):
				helper(arr, n-1)
				if n%2 == 1:
					tmp = arr[i]
					arr[i] = arr[n-1]
					arr[n-1] = tmp
				else:
					tmp = arr[0]
					arr[0] = arr[n-1]
					arr[n-1] = tmp
	res = []
	helper(arr, len(arr))
	return res

# Union-Find
class unionFind:
	def __init__(self, n):
		self.d = [-1] * n

	def find(self, x):
		if self.d[x] < 0:
			return x
		self.d[x] = self.find(self.d[x])
		return self.d[x]

	def unite(self, x, y):
		rootX = self.find(x)
		rootY = self.find(y)
		if rootX == rootY:
			return False
		if self.d[rootX] < self.d[rootY]:
			self.d[rootX] += self.d[rootY]
			self.d[rootY] = rootX
		else:
			self.d[rootY] += self.d[rootX]
			self.d[rootX] = rootY
		return True

	def same(self, x, y):
		return self.find(x) == self.find(y)

	def size(self, x):
		return -self.d[self.find(x)]

# mod
def modpow(a, n, mod):
	res = 1
	for n > 0:
		if n%2!= 0:
			res = res * a % mod
		a = a * a % mod
		n = n / 2
	return res

def modinv(n, mod):
	return modpow(n, mod-2, mod)

def modcomb(n, a, mod):
	x = 1
	y = 1
	for i in range(a):
		x = x * (n - i)
		x %= mod
		y = y * (i + 1)
		y %= mod
	return x * modpow(y, mod-2, mod) % mod

def modfactorial(n, mod):
	result = 1
	for i in range(1, n+1):
		result = (result * i) % mod
	return result

# Combination
class Combination:
	def __init__(self, n, mod):
		self.facts = [0] * (n+1)
		self.invs = [0] * (n+1)
		self.mod = mod
		self.facts[0] = 1
		for i in range(1, n+1):
			self.facts[i] = self.facts[i-1] * i % mod
		self.invs[n] = modinv(self.facts[n], mod)
		for i in range(n, 0, -1):
			self.invs[i-1] = self.invs[i] * i % mod

	def calc(self, n, k):
		ret = self.facts[n] * self.invs[k]
		ret %= self.mod
		ret = ret * self.invs[n-k]
		ret %= self.mod
		return ret

# Utility
def min(x, y):
	if x < y:
		return x
	return y

def max(x, y):
	if x > y:
		return x
	return y

def abs(x):
	if x < 0:
		return -x
	return x

def primeFactor(x):
	res = {}
	for i in range(2, int(math.sqrt(x))+1):
		for x%i == 0:
			res[i] = res.get(i, 0) + 1
			x = x / i
	if x!= 1:
		res[x] = 1
	return res

def divisor(x):
	res = []
	for i in range(1, int(math.sqrt(x))+1):
		if x%i == 0:
			res.append(i)
			if i!= x/i:
				res.append(x/i)
	return res

def gcd(x, y):
	if y == 0:
		return x
	return gcd(y, x%y)

def lcm(x, y):
	return x / gcd(x, y) * y

def reverseString(s):
	r = []
	for i in range(len(s)):
		r.append(s[len(s)-1-i])
	return ''.join(r)

def pow(a, n):
	ret = 1
	for i in range(1, n+1):
		ret *= a
	return ret

# Queue
class Queue:
	def __init__(self):
		self.q = []

	def empty(self):
		return len(self.q) == 0

	def push(self, i):
		self.q.append(i)

	def pop(self):
		if self.empty():
			return 0, False
		else:
			res = self.q[0]
			self.q = self.q[1:]
			return res, True

# Stack
class Stack:
	def __init__(self):
		self.s = []

	def empty(self):
		return len(self.s) == 0

	def push(self, i):
		self.s.append(i)

	def pop(self):
		if self.empty():
			return 0, False
		else:
			index = len(self.s) - 1
			res = self.s[index]
			self.s = self.s[:index]
			return res, True

# priority_queue
class intHeap:
	def __init__(self):
		self.h = []

	def empty(self):
		return len(self.h) == 0

	def push(self, x):
		self.h.append(x)
		self.up(len(self.h)-1)

	def pop(self):
		if self.empty():
			return 0, False
		else:
			res = self.h[0]
			self.h[0] = self.h[len(self.h)-1]
			self.h = self.h[:len(self.h)-1]
			self.down(0)
			return res, True

	def up(self, i):
		if i == 0:
			return
		p = (i - 1) / 2
		if self.h[i] < self.h[p]:
			self.h[i], self.h[p] = self.h[p], self.h[i]
			self.up(p)

	def down(self, i):
		l = 2 * i + 1
		r = 2 * i + 2
		if l >= len(self.h):
			return
		if r >= len(self.h):
			j = l
		else:
			if self.h[l] < self.h[r]:
				j = l
			else:
				j = r
		if self.h[i] > self.h[j]:
			self.h[i], self.h[j] = self.h[j], self.h[i]
			self.down(j)

# sortable points
class point:
	def __init__(self, x, y):
		self.x = x
		self.y = y

class points:
	def __init__(self):
		self.p = []

	def Len(self):
		return len(self.p)

	def Less(self, i, j):
		return self.p[i].x < self.p[j].x

	def Swap(self, i, j):
		self.p[i], self.p[j] = self.p[j], self.p[i]

