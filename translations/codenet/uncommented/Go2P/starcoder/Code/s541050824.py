import sys

def next():
	return sys.stdin.readline().strip()

def nextInt():
	return int(next())

def nextLine():
	return sys.stdin.readline()

def out(a):
	print(a)

def max(x, y):
	if x > y:
		return x
	return y

def min(x, y):
	if x < y:
		return x
	return y

def joinInts(a, sep):
	b = []
	for v in a:
		b.append(str(v))
	return sep.join(b)

def divUp(x, y):
	return (x + y - 1) / y

def solve():
	N = nextInt()
	T, A = [], []
	for i in range(N):
		T.append(nextInt())
		A.append(nextInt())
	t, a = T[0], A[0]
	for i in range(1, N):
		r = max(divUp(t, T[i]), divUp(a, A[i]))
		t, a = T[i]*r, A[i]*r
	out(t + a)

solve()
# 