
# <START-OF-CODE>

import sys

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

def main():
	a, b, c = map(int, input().split())
	k = int(input())

	patterns = duplicate_patterns([0, 1, 2, 3], k)

	for P in patterns:
		r, g, b = a, b, c
		for i in range(len(P)):
			if P[i] == 0:
				continue
			elif P[i] == 1:
				r *= 2
			elif P[i] == 2:
				g *= 2
			elif P[i] == 3:
				b *= 2

		if g > r and b > g:
			print("Yes")
			return

	print("No")

def duplicate_patterns(elems, k):
	return dupli_rec([], elems, k)

def dupli_rec(pattern, elems, k):
	if len(pattern) == k:
		return [pattern]

	res = []
	for e in elems:
		newPattern = pattern[:]
		newPattern.append(e)

		subPatterns = dupli_rec(newPattern, elems, k)

		res.extend(subPatterns)

	return res

# 