import sys

def getNextWord(scanner):
	scanner.readline()
	return scanner.readline()

def getNextInt(scanner):
	return int(getNextWord(scanner))

def main():
	fp = sys.stdin
	if len(sys.argv) > 1:
		fp = open(sys.argv[1])

	scanner = fp.readline()
	n = int(scanner)
	scanner = fp.readline()
	m = int(scanner)
	aa = {}
	for i in range(m):
		scanner = fp.readline()
		aa[int(scanner)] = 1

	dp = [0] * (n+1)
	dp[0] = 1
	for i in range(n):
		for ii in range(1, 3):
			if i+ii > n:
				break
			_, ok = aa.get(i+ii, None)
			if ok:
				continue
			dp[i+ii] += dp[i]
			dp[i+ii] %= 1000000007
	print(dp[n])

main()

