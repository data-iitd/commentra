import sys

def main():
	n = int(sys.stdin.readline())
	rt = int(n ** 0.5)
	minf = 100
	for i in range(1, rt+1):
		if n % i == 0:
			b = n // i
			ndigit = 0
			while b > 0:
				b //= 10
				ndigit += 1
			minf = min(minf, ndigit)
	print(minf)

def min(i, j):
	if i > j:
		return j
	return i

main()
# 