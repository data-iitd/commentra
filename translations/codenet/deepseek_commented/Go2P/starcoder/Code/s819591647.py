//problem_b.py

import sys

def get_int():
	return int(sys.stdin.readline())

def get_int_slice(n):
	return [int(x) for x in sys.stdin.readline().split()]

def get_int_double_slice(m, n):
	return [get_int_slice(n) for _ in range(m)]

def get_string():
	return sys.stdin.readline().strip()

def get_string_slice(n):
	return [x for x in sys.stdin.readline().split()]

def get_string_double_slice(m, n):
	return [get_string_slice(n) for _ in range(m)]

def sort_int_slice(ns):
	ns.sort()
	return ns

def sort_int_reverse_slice(ns):
	ns.sort(reverse=True)
	return ns

def num_abs(x):
	return abs(x)

def num_mod_pow(a, n, m):
	result = 1

	for n > 0:
		if n & 1 == 1:
			result = (result * a) % m

		a = (a * a) % m
		n >>= 1

	return result

def num_gcd(a, b):
	if b == 0:
		return a

	return num_gcd(b, a % b)

def num_lcm(a, b):
	return a * b / num_gcd(a, b)

def num_mod_inv(a, p):
	if a == 1:
		return 1

	return p - num_mod_inv(p % a, p) * (p / a) % p

def num_mod_frac(n):
	frac = [1]

	for i in range(1, n + 1):
		frac.append(i * frac[i - 1] % constMod)

	return frac

def num_mod_conb(n, r):
	frac = num_mod_frac(n)

	return (frac[n] / ((frac[n - r] * frac[r]) % constMod)) % constMod

def solve():
	n, m = get_int(), get_int()
	a = get_int_slice(n)

	sum = 0
	for v in a:
		sum += v

	count = 0
	for v in a:
		rate = float(sum) / float(4 * m)
		if float(v) >= rate:
			count += 1

	if count >= m:
		print("Yes")
	else:
		print("No")

if __name__ == "__main__":
	constMod = 1000000007
	solve()

