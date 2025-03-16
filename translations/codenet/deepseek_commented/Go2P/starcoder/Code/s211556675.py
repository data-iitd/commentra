import sys

# I/O
sc = sys.stdin.readline
wtr = sys.stdout.write

# Arithmetic
def max(*nums):
	m = nums[0]
	for i in nums:
		if m < i:
			m = i
	return m

def min(*nums):
	m = nums[0]
	for i in nums:
		if m > i:
			m = i
	return m

def abs(x):
	if x > 0:
		return x
	return -x

def pow(x, y):
	res = 1
	for i in range(y):
		res *= x
	return res

# Sort
class Val:
	def __init__(self, id, num):
		self.id = id
		self.num = num

class ByNum(list):
	def __init__(self, vals):
		list.__init__(self, vals)
	def __cmp__(self, other):
		return self[0].num < other[0].num

# Main
A, B, C, K = map(int, sc().split())
ma = max(A, B, C)
rest = 0
if ma == A:
	rest += B + C
elif ma == B:
	rest += A + C
else:
	rest += A + B
for i in range(1, K+1):
	ma *= 2
wtr(str(ma+rest) + '\n')

