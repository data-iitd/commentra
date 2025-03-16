
# -*- coding: utf-8 -*-

# <START-OF-CODE>

MOD = 1000000000 + 7
ALPHABET_NUM = 26
INF_INT64 = 1 << 60
INF_BIT60 = 1 << 60
INF_INT32 = 1 << 30
INF_BIT30 = 1 << 30
NIL = -1

WHITE = 0
GRAY = 1
BLACK = 2

n, q = map(int, input().split())
C = list(map(int, input().split()))

P = [NIL] * (500000 + 50)
Answers = [0] * q

class Query:
	def __init__(self, idx, l, r):
		self.idx = idx
		self.l = l
		self.r = r

Q = []
for i in range(q):
	l, r = map(int, input().split())
	Q.append(Query(i, l, r))

Q.sort(key=lambda x: x.r)

ft = FenwickTree(500000 + 50)

k = 0
for _, query in Q:
	for k < query.r:
		if P[C[k]]!= NIL:
			ft.Add(P[C[k]] + 1, -1)
		P[C[k]] = k
		ft.Add(k + 1, 1)
		k += 1

	Answers[query.idx] = ft.Sum(query.r) - ft.Sum(query.l - 1)

for i in range(q):
	print(Answers[i])

# 