
import sys

def scan_int():
	return int(sys.stdin.readline())

def scan_ints():
	return map(int, sys.stdin.readline().split())

def print_ints(ints):
	sys.stdout.write(" ".join(map(str, ints)) + "\n")

def modpow(a, n):
	res = 1
	while n > 0:
		if n & 1 == 1:
			res = res * a % mod
		a = a * a % mod
		n >>= 1
	return res

mod = 1000000007

n = scan_int()

c = scan_ints()

c.sort()

ans = 0
for i in range(n):
	ans = (ans + (n + 1 - i) * c[i] % mod) % mod

print(ans * modpow(4, n - 1) % mod)

#