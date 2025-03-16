
# -*- coding: utf-8 -*-

# <START-OF-CODE>

MOD = 1000000007

def main():
	n, q = map(int, input().split())
	C = list(map(int, input().split()))

	P = [-1] * (n + 1)
	Answers = [0] * q

	for i in range(1, n + 1):
		if P[C[i - 1]]!= -1:
			P[C[i - 1]] += 1
			P[C[i - 1]] %= MOD

	for i in range(q):
		l, r = map(int, input().split())
		l -= 1
		r -= 1

		if P[C[l]]!= -1:
			P[C[l]] += 1
			P[C[l]] %= MOD

		if P[C[r]]!= -1:
			P[C[r]] += 1
			P[C[r]] %= MOD

		s = 0
		for i in range(l, r + 1):
			s += P[C[i]]
			s %= MOD

		Answers[i] = s

	for i in range(q):
		print(Answers[i])

if __name__ == '__main__':
	main()

# 