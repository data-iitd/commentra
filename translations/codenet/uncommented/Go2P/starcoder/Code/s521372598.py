import sys

def solve():
	n = int(sys.stdin.readline())
	as = [int(x) for x in sys.stdin.readline().split()]

	xs = [a - i + 1 for i, a in enumerate(as)]
	xs.sort()

	b = xs[n//2]
	ans = 0
	for x in xs:
		ans += abs(x - b)
	print(ans)

def abs(n):
	if n < 0:
		return -n
	return n

# -----------------------------------------

import sys

maxBufSize = 10 ** 8
sys.stdin = open('input.txt', 'r', maxBufSize)
sys.stdout = open('output.txt', 'w', maxBufSize)

solve()

# 