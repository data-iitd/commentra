
def max(a, b):
	# Return the maximum of two integers
	if a > b:
		return a
	return b

def primeFactorize(n):
	# Calculate the prime factors and their powers of a given integer
	res = {}
	for i in range(2, int(n**0.5)+1):
		if n%i == 0:
			res[i] = 0
			while n%i == 0:
				n /= i
				res[i] += 1
	if n!= 1:
		res[n] = 1
	return res

def pow(n, k):
	# Calculate n raised to the power of k modulo mod
	if k == 0:
		return 1
	elif k%2 == 1:
		return pow(n, k-1) * n % mod
	else:
		t = pow(n, k/2)
		return t * t % mod

def add(a, b):
	# Return the sum of two integers modulo mod
	return (a + b) % mod

def sub(a, b):
	# Return the difference of two integers modulo mod
	return (a + mod - b) % mod

def mul(a, b):
	# Return the product of two integers modulo mod
	return a % mod * b % mod % mod

def div(a, b):
	# Return the quotient of a and b modulo mod
	return mul(a, pow(b, mod-2))

mod = 1000000007

n = int(input())
as = [int(input()) for i in range(n)]
ps = {}

for i in range(n):
	ns = primeFactorize(as[i])
	for k, v in ns.items():
		if k in ps:
			ps[k] = max(ps[k], v)
		else:
			ps[k] = v

x = 1
for k, v in ps.items():
	for i in range(1, v+1):
		x = mul(x, k)

ans = 0
for i in range(n):
	ans = add(ans, div(x, as[i]))

print(ans)

