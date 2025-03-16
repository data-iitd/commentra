
import sys
import io
import re
import math
import itertools

# <START-OF-CODE>

MOD = 1000000000 + 7
ALPHABET_NUM = 26
INF_INT64 = math.inf
INF_BIT60 = 1 << 60
INF_INT32 = math.inf
INF_BIT30 = 1 << 30
NIL = -1

WHITE = 0
GRAY = 1
BLACK = 2

def main():
	n, q = map(int, input().split())
	C = list(map(int, input().split()))

	P = [NIL] * (n + 1)
	for i in range(1, n + 1):
		P[i] = -1

	Q = []
	for i in range(q):
		l, r = map(int, input().split())
		query = Query(i, l, r)
		Q.append(query)

	Q.sort(key=lambda x: x.r)
	ft = NewFenwickTree(n + 1)

	k = 0
	for _, query in Q:
		for k < query.r:
			if P[C[k]]!= -1:
				ft.Add(P[C[k]] + 1, -1)
			P[C[k]] = k
			ft.Add(k + 1, 1)

			k += 1
		# print("P:", P)

		print(ft.Sum(query.r) - ft.Sum(query.l - 1))

class FenwickTree:
	def __init__(self, n):
		self.dat = [0] * (n + 1)
		self.n = n
		self.minPow2 = 1
		while (self.minPow2 << 1) <= n:
			self.minPow2 <<= 1

	def Sum(self, i):
		s = 0
		while i > 0:
			s += self.dat[i]
			i -= i & (-i)
		return s

	def Add(self, i, x):
		while i <= self.n:
			self.dat[i] += x
			i += i & (-i)

class Query:
	def __init__(self, idx, l, r):
		self.idx = idx
		self.l = l
		self.r = r

def NewFenwickTree(n):
	return FenwickTree(n)

# 