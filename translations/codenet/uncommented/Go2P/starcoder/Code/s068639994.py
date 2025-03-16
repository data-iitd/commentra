
import sys

def main():
	n = int(sys.stdin.readline())
	ls = list(map(int, sys.stdin.readline().split()))
	lsRev = ls[:]
	ls.sort()
	lsRev.sort(reverse=True)

	ans = 0
	for i in range(n):
		for j in range(i+1, n):
			p, q = min(ls[i], ls[j]), max(ls[i], ls[j])
			x, y = q-p, q+p

			l = bisect.bisect_left(ls, x)
			r = n - bisect.bisect_right(lsRev, y)

			sum = r - l
			if (i >= l) and (i <= r):
				sum -= 1
			if (j >= l) and (j <= r):
				sum -= 1
			sum = max(0, sum)
			ans += sum
	ans //= 3
	print(ans)

def min(a, b):
	if a < b:
		return a
	return b

def max(a, b):
	if a > b:
		return a
	return b

# 