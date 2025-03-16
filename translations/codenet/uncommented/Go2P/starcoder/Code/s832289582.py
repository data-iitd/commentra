import sys

# N: [1, 2e5]
# len(S) = N
# P: [2, 10000], prime
def main():
	sc = newInputScanner(True, 256)
	N, P, S = sc.nextInt(), sc.nextInt(), sc.nextStr()
	answer = checkSubNumbers(N, P, S)
	print(answer)

def checkSubNumbers(N, P, S):
	switch P:
	case 2, 5:
		return checkTwoOrFive(N, P, S)
	default:
		return checkNotTwoNorFive(N, P, S)

def checkTwoOrFive(N, P, S):
	answer = 0
	n = 0
	for i in range(N - 1, -1, -1):
		n = int(S[i])
		if n % P == 0:
			answer += i + 1
	return answer

def checkNotTwoNorFive(N, P, S):
	multiplier = 1 # 10^i % P
	answer = 0
	remainderLookup = [0] * P
	prevRemaider = -1
	digit = 0
	remainder = 0
	count = 0
	for i in range(N - 1, -1, -1):
		digit = int(S[i])
		if prevRemaider == -1: # first digit
			remainder = digit % P
		else:
			remainder = (((multiplier * digit) % P) + prevRemaider) % P
		if remainder == 0:
			answer += 1
		count = remainderLookup[remainder]
		answer += count
		count += 1
		remainderLookup[remainder] = count
		prevRemaider = remainder
		multiplier = (multiplier * 10) % P
	return answer

class inputScanner:
	def __init__(self, enabledScanWords=True, sizeInKB=256):
		self.sc = bufio.NewScanner(sys.stdin)
		if enabledScanWords:
			self.sc.split(bufio.ScanWords)
		self.buf = bytearray(sizeInKB * 1024)
		self.sc.buffer(self.buf, sizeInKB * 1024)

	def nextInt(self):
		self.sc.scan()
		i = int(self.sc.text)
		return i

	def nextUInt64(self):
		self.sc.scan()
		i = int(self.sc.text)
		return i

	def nextStr(self):
		self.sc.scan()
		return self.sc.text

