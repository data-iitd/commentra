import sys

# bufReader is a struct to efficiently read input.
class bufReader:
	def __init__(self, fh):
		self.fh = fh
		self.buf = ''
		self.pos = 0

	def readLine(self):
		if self.pos < len(self.buf):
			nlPos = self.buf.find('\n', self.pos)
			if nlPos >= 0:
				r = self.buf[self.pos:nlPos]
				self.pos = nlPos + 1
				return r
			else:
				r = self.buf[self.pos:]
				self.buf = ''
				self.pos = 0
				return r
		else:
			self.buf = self.fh.readline()
			if len(self.buf) == 0:
				return ''
			return self.readLine()

	def next(self):
		s = self.readLine()
		if s == '':
			return s
		s = s.strip()
		return s

	def nextInt(self):
		i, err = int(self.next()), None
		if err!= None:
			raise err
		return i

# Initialize global reader and writer for input and output operations.
reader = bufReader(sys.stdin)
writer = sys.stdout

# next is a wrapper for reader.next().
def next():
	return reader.next()

# nextInt reads the next token as an int.
def nextInt():
	return reader.nextInt()

# nextLine is a wrapper for reader.nextLine().
def nextLine():
	return reader.readLine()

# out prints the arguments to the output.
def out(a):
	print(a, file=writer)

# max64 returns the maximum of two int64 values.
def max64(x, y):
	if x > y:
		return x
	return y

# max returns the maximum of two int values.
def max(x, y):
	return max64(x, y)

# min64 returns the minimum of two int64 values.
def min64(x, y):
	if x < y:
		return x
	return y

# min returns the minimum of two int values.
def min(x, y):
	return min64(x, y)

# abs64 returns the absolute value of an int64.
def abs64(x):
	if x < 0:
		return -x
	return x

# abs returns the absolute value of an int.
def abs(x):
	return abs64(x)

# joinInt64s joins an array of int64 values into a string with a separator.
def joinInt64s(a, sep):
	b = []
	for v in a:
		b.append(str(v))
	return sep.join(b)

# joinInts joins an array of int values into a string with a separator.
def joinInts(a, sep):
	b = []
	for v in a:
		b.append(str(v))
	return sep.join(b)

# divUp64 returns the ceiling of the division of x by y.
def divUp64(x, y):
	return (x + y - 1) // y

# divUp returns the ceiling of the division of x by y.
def divUp(x, y):
	return divUp64(x, y)

# gcd64 returns the greatest common divisor of two int64 values.
def gcd64(x, y):
	if x < y:
		x, y = y, x
	while y!= 0:
		x, y = y, x % y
	return x

# gcd returns the greatest common divisor of two int values.
def gcd(x, y):
	return gcd64(x, y)

# lcm64 returns the least common multiple of two int64 values.
def lcm64(x, y):
	return x * y // gcd64(x, y)

# lcm returns the least common multiple of two int values.
def lcm(x, y):
	return lcm64(x, y)

# pow64 returns the result of raising x to the power of y.
def pow64(x, y):
	return x ** y

# pow returns the result of raising x to the power of y.
def pow(x, y):
	return pow64(x, y)

# main function calls solve and flushes the writer at the end.
def main():
	solve()
	writer.flush()

# solve function implements the main logic of the program.
def solve():
	N, _ = nextInt(), nextInt()
	A = []
	for i in range(N):
		A.append(nextInt())
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
	out(maxCnt)

