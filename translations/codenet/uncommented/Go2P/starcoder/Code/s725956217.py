import sys

def out(*args, **kwargs):
	print(*args, **kwargs)

def getInt():
	return int(sys.stdin.readline())

def getString():
	return sys.stdin.readline().strip()

# min, max, asub, absなど基本関数
def max(a, b):
	if a > b:
		return a
	return b

def min(a, b):
	if a < b:
		return a
	return b

def asub(a, b):
	if a > b:
		return a - b
	return b - a

def abs(a):
	if a >= 0:
		return a
	return -a

def lowerBound(a, x):
	idx = bisect.bisect_left(a, x)
	return idx

def upperBound(a, x):
	idx = bisect.bisect_right(a, x)
	return idx

class shop:
	def __init__(self, a, b):
		self.a = a
		self.b = b

# Datas :
class Datas(list):
	def __init__(self, *args):
		list.__init__(self, *args)

	def __lt__(self, other):
		return self.a < other.a

def main():
	N, M = getInt(), getInt()
	s = Datas()
	for i in range(N):
		a, b = getInt(), getInt()
		s.append(shop(a, b))
	s.sort()

	total = 0
	for e in s:
		n = min(e.b, M)
		total += n * e.a
		M -= n
		if M == 0:
			break
	out(total)

# 