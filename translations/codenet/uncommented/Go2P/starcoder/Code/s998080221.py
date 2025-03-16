import sys

def main():
	reader = sys.stdin
	writer = sys.stdout
	solve(reader, writer)
	writer.close()

def solve(reader, writer):
	N, _ = map(int, reader.readline().split())
	A = map(int, reader.readline().split())
	maxProfit = 0
	maxCnt = 0
	maxA = A[N-1]
	for i in range(N-2, -1, -1):
		profit = max(0, maxA-A[i])
		if maxProfit < profit:
			maxProfit = profit
			maxCnt = 1
		elif maxProfit == profit:
			maxCnt += 1
		maxA = max(maxA, A[i])
	writer.write(str(maxCnt) + '\n')

if __name__ == "__main__":
	main()

