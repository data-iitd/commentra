
# <START-OF-CODE>

import sys

def run(input, output):
	N = int(input.readline())
	S = input.readline().strip()

	if N == 0:
		return 0

	if N < 4:
		print(0)
		return 0

	nr, nb, ng = 0, 0, 0
	for c in S:
		if c == 'R':
			nr += 1
		if c == 'B':
			nb += 1
		if c == 'G':
			ng += 1

	same = 0
	for a in range(1, N):
		i, j, k = 0, 1 * a, 2 * a
		if k >= N:
			break
		for k in range(k, N):
			if S[i]!= S[j] and S[i]!= S[k] and S[j]!= S[k]:
				same += 1
			i += 1
			j += 1
			k += 1

	tot = nr * nb * ng
	print(tot - same)

	return 0

def main():
	sys.exit(run(sys.stdin, sys.stdout))

# 