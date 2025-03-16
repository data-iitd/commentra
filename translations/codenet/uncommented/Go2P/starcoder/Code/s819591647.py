//problem_b.py

import sys

def getInt():
	return int(sys.stdin.readline())

def getIntSlice(n):
	return [int(x) for x in sys.stdin.readline().split()]

def getIntDoubleSlice(m, n):
	return [getIntSlice(n) for i in range(m)]

def getString():
	return sys.stdin.readline().strip()

def getStringSlice(n):
	return [x for x in sys.stdin.readline().split()]

def getStringDoubleSlice(m, n):
	return [getStringSlice(n) for i in range(m)]

# -----------------------------------------

# Sort Fanction

def sortIntSlice(ns):
	return sorted(ns)

def sortIntReverseSlice(ns):
	return sorted(ns, reverse=True)

# -----------------------------------------

# Num Fanction

#numAbs(x) = abs(s)
def numAbs(x):
	if x < 0:
		return -x
	return x

#numModPow(a, n, m) = a^n % m
def numModPow(a, n, m):
	result = 1

	for n > 0:
		if n%2 == 1:
			result = (result * a) % m
		a = (a * a) % m
		n >>= 1

	return result

# numGcd(a, b) = gcd(a, b)
def numGcd(a, b):
	if b == 0:
		return a
	return numGcd(b, a%b)

# numLcm(a, b) = lcm(a, b)
def numLcm(a, b):
	return a * b / numGcd(a, b)

# numModInv(a, p) = a^(-1) % p
def numModInv(a, p):
	if a == 1:
		return 1
	return p - numModInv(p%a, p)*(p/a)%p

# numModFrac(n) = n! % constMod
def numModFrac(n):
	frac = [1]

	for i in range(1, n+1):
		frac.append(i*frac[i-1]%constMod)

	return frac

# numModConb(n, r) = nCr % constMod
def numModConb(n, r):
	frac = numModFrac(n)

	return (frac[n] / ((frac[n-r] * frac[r]) % constMod)) % constMod

# -----------------------------------------

def solve():

	n, m = getInt(), getInt()
	a = getIntSlice(n)

	sum = 0
	for v in a:
		sum += v

	count = 0
	for v in a:
		rate = float(sum) / float(4*m)
		if float(v) >= rate:
			count += 1

	if count >= m:
		print("Yes")
	else:
		print("No")

# -----------------------------------------

if __name__ == "__main__":
	maxBufSize = 1024**2
	sys.setrecursionlimit(maxBufSize)
	solve()

# 