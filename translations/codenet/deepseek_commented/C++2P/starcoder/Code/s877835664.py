
# Function to calculate the greatest common divisor (GCD)
def gcd(a, b):
	if b == 0:
		return a
	else:
		return gcd(b, a % b)

# Function to calculate the least common multiple (LCM)
def lcm(a, b):
	return a / gcd(a, b) * b

# Function to get the prime factors of a number
def getPrimeFactor(n):
	res = {}
	for i in range(2, int(n**0.5)+1):
		while n % i == 0:
			res[i] = res.get(i, 0) + 1
			n /= i
	if n!= 1:
		res[n] = res.get(n, 0) + 1
	return res

# Function to check if a number is a prime number
def IsPrimeNumber(num):
	if num <= 2:
		return True
	else:
		if num % 2 == 0:
			return False
		else:
			sqrtNum = int(num**0.5)
			for i in range(3, sqrtNum+1, 2):
				if num % i == 0:
					return False
			return True

# Function to calculate the modular inverse of a number
def modinv(a, m):
	b = m
	u = 1
	v = 0
	while b:
		t = a / b
		a -= t * b
		a, b = b, a
		u -= t * v
		u, v = v, u
	u %= m
	if u < 0:
		u += m
	return u

# Macro for looping from s to e
def rep(i, s, e):
	for i in range(s, e):
		yield i

# Macro for looping from s to e inclusive
def repeq(i, s, e):
	for i in range(s, e+1):
		yield i

N, K = map(int, input().split())
A = [0] * (N + 1)
for i in repeq(1, 1, N):
	A[i] = int(input())

cur = 1
dic = [0] * (N + 1)
flg = False
for i in repeq(1, 1, K):
	if dic[cur] < 0 or flg:
		dic[cur] = i
		cur = A[cur]
	else:
		tmp = K - (dic[cur] - 1)
		tmp %= i - dic[cur]
		i = K - tmp
		flg = True

print(cur)

