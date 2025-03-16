# <START-OF-CODE>

# I/O
# The Scanner class is defined to read input efficiently.
class Scanner:
	def __init__(self, stream):
		self.stream = stream
		self.buffer = ""

	def nextStr(self):
		while " " in self.buffer:
			self.buffer = self.buffer[self.buffer.index(" ") + 1:]
		i = self.buffer.index("\n") if "\n" in self.buffer else len(self.buffer)
		s, self.buffer = self.buffer[:i], self.buffer[i:]
		return s

	def nextInt(self):
		return int(self.nextStr())

	def nextFloat(self):
		return float(self.nextStr())

	def nextRuneSlice(self):
		return [ord(c) for c in self.nextStr()]

	def nextIntSlice(self, n):
		return [self.nextInt() for _ in range(n)]

	def nextFloatSlice(self, n):
		return [self.nextFloat() for _ in range(n)]

# The run function reads the input, processes it, and prints the result.
def run(input, output):
	sc = Scanner(input)
	# Reads the number of elements N and the string S.
	N = sc.nextInt()
	S = sc.nextStr()

	if N == 0:
	pass

	if N < 4:
		print(0)
		return 0

	# Counts the number of 'R', 'B', and 'G' characters in S.
	nr, nb, ng = 0, 0, 0
	for c in S:
		if c == 'R':
			nr += 1
		if c == 'B':
			nb += 1
		if c == 'G':
			ng += 1

	# Calculates the number of triplets where the characters are all different.
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

	# Calculates the total number of possible triplets.
	tot = nr * nb * ng

	# Prints the difference between the total number of possible triplets and the number of triplets with all different characters.
	print(tot - same)

	return 0

# The main function calls the run function with standard input and output, and exits with the return value of run.
if __name__ == "__main__":
	sys.exit(run(sys.stdin, sys.stdout))

# 