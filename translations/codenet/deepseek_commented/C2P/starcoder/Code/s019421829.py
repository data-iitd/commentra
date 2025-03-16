# AOJ 2275: Fox Number
# 2017.12.11 bal4u@uu

import sys
import math

MAX = 707106			# sqrt(10^12/2)
tbl = [0] * (MAX+1)

def sieve():
	global tbl, MAX, prime, sz, sqp

	for i in range(1, 147):
		k = prime[i]
		for j in range(sqp[i], MAX, k): tbl[j] = 1

	for i in range(853, MAX+1, 2):
		if not tbl[i]: prime.append(i)
	sz = len(prime)

def bsch(x):
	l = 0; r = sz
	while l < r:
		m = (l + r) >> 1
		if prime[m] == x: return m
		if prime[m] < x: l = m + 1
		else: r = m
	return l-1

def main():
	global tbl, MAX, prime, sz, sqp

	sieve()

	A, B = map(int, sys.stdin.readline().split())
	a = A-B; b = A+B
	if b <= 1:
		print(0)
		return 0
	if a <= 1: a = 2

	sz = bsch(int(math.sqrt(b >> 1)))

	idx = [1] * (b-a+1)
	for i in range(0, sz):
		p = prime[i]
		for k in range(1, 41):
			j = p
			while j <= b:
				pp[k] = j
				j *= p
			k -= 1
		while k >= 0:
			j = pp[k]; ll = j*(1+(a-1)/j); rr = j*(b/j)
			while ll <= rr:
				x = int(ll-a)
				if not idx[x] or base[x] == p:
					ll += j
					continue
				if idx[x] < k: idx[x] = 0
				else: base[x] = p; idx[x] = k
				ll += j
	ans = 0; i = b-a+1
	while i > 0:
		i -= 1
		if idx[i]: ans += 1
	print(ans)

if __name__ == '__main__':
	main()

