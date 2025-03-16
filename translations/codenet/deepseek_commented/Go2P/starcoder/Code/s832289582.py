import sys

# N: [1, 2e5]
# len(S) = N
# P: [2, 10000], prime
def main():
	sc = newInputScanner(True, 256) # Initialize the input scanner with word scanning enabled and a buffer size of 256 KB.
	N, P, S = sc.nextInt(), sc.nextInt(), sc.nextStr() # Read the values of N, P, and S from the input.
	answer = checkSubNumbers(N, P, S) # Call the checkSubNumbers function with the read values and print the result.
	print(answer)

# checkSubNumbers determines whether P is 2 or 5 and calls the appropriate helper function.
def checkSubNumbers(N, P, S):
	switch P:
	case 2, 5:
		return checkTwoOrFive(N, P, S) # If P is 2 or 5, call checkTwoOrFive.
	default:
		return checkNotTwoNorFive(N, P, S) # Otherwise, call checkNotTwoNorFive.

# checkTwoOrFive iterates over the string S from the end to the beginning, checking if the last digit of each substring is divisible by P.
def checkTwoOrFive(N, P, S):
	answer = 0
	n = 0
	for i in range(N - 1, -1, -1):
		n = int(S[i]) # Convert the current character to an integer.
		if n % P == 0: # Check if the integer is divisible by P.
			answer += i + 1 # If it is, add the position to the answer.
	return answer

# checkNotTwoNorFive uses a rolling hash approach to efficiently determine the number of substrings of S that are divisible by P.
def checkNotTwoNorFive(N, P, S):
	multiplier = 1 # 10^i % P
	answer = 0
	remainderLookup = [0] * P # Create a slice to store the counts of remainders.
	prevRemaider = -1
	digit = 0
	remainder = 0
	count = 0
	for i in range(N - 1, -1, -1):
		digit = int(S[i]) # Convert the current character to an integer.
		if prevRemaider == -1: # If it's the first digit, calculate the remainder directly.
			remainder = digit % P
		else: # Otherwise, use the rolling hash approach.
			remainder = (((multiplier * digit) % P) + prevRemaider) % P
		if remainder == 0: # If the remainder is 0, increment the answer.
			answer += 1
		count = remainderLookup[remainder] # Get the current count of this remainder.
		answer += count # Add the count to the answer.
		count += 1 # Increment the count.
		remainderLookup[remainder] = count # Update the count in the slice.
		prevRemaider = remainder # Update the previous remainder.
		multiplier = (multiplier * 10) % P # Update the multiplier for the next iteration.
	return answer

class inputScanner:
	def __init__(self, enabledScanWords = True, sizeInKB = 256):
		self.sc = bufio.NewScanner(sys.stdin)
		if enabledScanWords:
			self.sc.split(bufio.ScanWords)
		self.buf = bytearray(sizeInKB * 1024)
		self.sc.Buffer(self.buf, sizeInKB * 1024)

	def nextInt(self):
		i, e = int(self.nextStr()), None
		if e!= None:
			raise e
		return i

	def nextUInt64(self):
		i, e = int(self.nextStr()), None
		if e!= None:
			raise e
		return i

	def nextStr(self):
		self.sc.Scan()
		return self.sc.Text()

if __name__ == '__main__':
	main()

