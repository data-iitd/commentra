import sys

def main():
	N = int(sys.stdin.readline())
	X = []
	Y = []
	for i in range(N):
		x = int(sys.stdin.readline())
		X.append(x)
		Y.append(x)
	Y.sort()
	m1 = Y[N / 2 - 1]
	m2 = Y[N / 2]
	for i in range(N):
		if X[i] <= m1:
			print(m2)
		else:
			print(m1)

if __name__ == "__main__":
	main()

