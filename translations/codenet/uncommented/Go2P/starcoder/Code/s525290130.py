
import sys

def nextInt(sc):
	sc.readline()
	return int(sc.readline())

def reva(b):
	for i in range(len(b)//2):
		b[i], b[len(b)-1-i] = b[len(b)-1-i], b[i]

def main():
	sc = sys.stdin
	n = nextInt(sc)
	a = [0] * n
	for i in range(n):
		a[i] = nextInt(sc)
	q = nextInt(sc)
	for i in range(q):
		b = nextInt(sc)
		e = nextInt(sc)
		reva(a[b:e])
	for i in range(n):
		if i > 0:
			print(" ", end="")
		print(a[i], end="")
	print()

main()

