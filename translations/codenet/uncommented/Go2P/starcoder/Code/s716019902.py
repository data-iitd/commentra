import sys

def main():
	sc = newScanner(sys.stdin)
	N = sc.i()
	sum = 0
	for i in range(1, N+1):
		if i%3 == 0 or i%5 == 0:
			continue
		sum += i
	print(sum)

# fmt.Println("Yes")
# fmt.Println("No")

# I/O
class scanner:
	def __init__(self, stream):
		self.stream = stream
		self.buf = ""
		self.pos = 0
		self.fill()

	def fill(self):
		self.buf = self.stream.readline()
		self.pos = 0

	def s(self):
		while True:
			if self.pos == len(self.buf):
				self.fill()
			if self.pos == len(self.buf):
				return ""
			if self.buf[self.pos]!= " ":
				break
			self.pos += 1
		start = self.pos
		while self.pos < len(self.buf):
			if self.buf[self.pos] == " ":
				break
			self.pos += 1
		return self.buf[start:self.pos]

	def i(self):
		return int(self.s())

	def f(self):
		return float(self.s())

	def bs(self):
		return self.s().encode("utf-8")

	def is(self, n):
		r = []
		for i in range(n):
			r.append(self.i())
		return r

	def fs(self, n):
		r = []
		for i in range(n):
			r.append(self.f())
		return r

#const factorial = new
def Pow(a, n):
	ans = 1
	for n > 0:
		if (n & 1) == 1:
			ans = ans * a % mod
		a = a * a % mod
		n = n >> 1
	return ans

def Gcd(a, b):
	if a < b:
		return Gcd(b, a)
	while b!= 0:
		a, b = b, a%b
	return a

def min(a, b):
	if a < b:
		return a
	return b

def combination(n, k, fac, ifac):
	if n < k or n < 0:
		return 0
	if k == 0:
		return 1
	#while n!= 0
	ans = ifac[k] * ifac[n-k] % mod
	return ans * fac[n] % mod

# 階乗: factorial
# コンビネーションを計算する際に前もって計算しておく
# fac[k] => k! (mod M)
# ifac[k] => k!^(M-2) (mod M)
# n: ex. 2 * 10^5 => 200001
# fac, ifac := factorial()
def factorial():
	fac = [0] * facNum
	fac[0] = 1
	ifac = [0] * facNum
	ifac[0] = 1
	for i in range(1, facNum):
		fac[i] = fac[i-1] * i % mod
		ifac[i] = ifac[i-1] * Pow(i, mod-2) % mod
	return fac, ifac

# vs: sorted slice int value
def lowerBound(vs, v):
	n = len(vs) / 2
	m = len(vs)
	for m!= n:
		if vs[n] < v:
			n = (m-n+1)/2 + n
			#m = m
		else:
			m = n
			n = n / 2
	return n

def IntSlice(n, init):
	r = [0] * n
	for i in range(n):
		r[i] = init
	return r

