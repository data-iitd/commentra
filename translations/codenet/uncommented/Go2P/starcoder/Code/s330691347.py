
import sys

def out(x):
	print(x)

def nextInt():
	return int(input())

def nextString():
	return input()

class Data:
	def __init__(self, x):
		self.X = x

class Datas(list):
	def __init__(self, x):
		super().__init__(x)

	def Len(self):
		return len(self)

	def Swap(self, i, j):
		self[i], self[j] = self[j], self[i]

	def Less(self, i, j):
		return self[i].X < self[j].X

def main():
	N = nextInt()
	L = nextInt()
	s = Datas([Data(nextString()) for i in range(N)])
	out(N, L, s)
	s.sort(key=lambda x: x.X)
	out(s)

	ans = ""
	for i in range(N):
		ans = ans + s[i].X
	print(ans)

main()

