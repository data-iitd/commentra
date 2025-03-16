import sys

# out is a utility function to print multiple values with a newline.
def out(x, *args):
	print(x, *args, sep=' ')

# sc is a global Scanner to read input.
sc = sys.stdin

# nextInt reads an integer from the input.
def nextInt():
	return int(sc.readline())

# nextString reads a string from the input.
def nextString():
	return str(sc.readline())

# Data represents a structure holding a string.
class Data:
	def __init__(self, x):
		self.X = x

# Datas is a slice of Data structures.
class Datas(list):
	def __init__(self, x):
		list.__init__(self, x)

	def __lt__(self, other):
		return self.X < other.X

# The main function reads N strings, sorts them, and prints the concatenated result.
def main():
	N = nextInt()
	L = nextInt()
	s = Datas([Data(nextString()) for i in range(N)])

	out(N, L, s)
	s.sort()
	out(s)

	ans = ""
	for i in range(N):
		ans = ans + s[i].X
	print(ans)

# 