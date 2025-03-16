
# <START-OF-CODE>

# Constants for large prime numbers used in modular arithmetic.
INF  = 1000000007
INF2 = 1000000009
INF3 = 998244353

# Global variable for debug mode.
DEBUG = False

# -----------------------------------------------------------------------------
# IO helper functions

# Returns next token from input. It must be initialized by SetInput() before the first call.
var nextToken = None
var nextLine = None

# Holds a buffer for output. It must be initialized by SetOutput().
# All IO functions (read*() and [e]print*()) should write to OutputWriter instead of this.
var OutputBuffer = None

# Holds an io.Writer. It must be initialized by SetOutput()
var OutputWriter = None

# Set IO functions for interactive input/output.
def SetInteractive(w, r):
	SetUnbufferedInput(r)
	OutputBuffer = None
	OutputWriter = w

# Setup OutputBuffer and OutputWriter.
def SetOutput(w):
	OutputBuffer = bufio.NewWriter(w)
	OutputWriter = OutputBuffer

# Flushes OutputBuffer
def Flush():
	if OutputBuffer!= None:
		OutputBuffer.Flush()

# Returns true if c is a white space
def IsSpace(c):
	return c =='' or c == '\t' or c == '\n' or c == '\r' or ord(c) == 0x0B or ord(c) == 0x0C

def IsNewLine(c):
	return c == '\n' or c == '\r'

# Setup nextToken with input buffer.
def SetInput(r):
	buf = new(bytes.Buffer)
	var b []byte

	var i = 0
	rest = lambda: None
	initial = lambda: None
	nextToken = initial

	restLn = lambda: None
	initialLn = lambda: None
	nextLine = initialLn

	def readb():
		global i
		for i < len(b) and IsSpace(b[i]):
			i += 1
		if i == len(b):
			return None
		j = i
		for i < len(b) and not IsSpace(b[i]):
			i += 1
		return b[j:i]

	def reads():
		s = readb()
		if s == None:
			return None
		return s.decode()

	def readbln():
		global i
		for i < len(b) and IsNewLine(b[i]):
			i += 1
		if i == len(b):
			return None
		j = i
		for i < len(b) and not IsNewLine(b[i]):
			i += 1
		return b[j:i]

	def readsln():
		s = readbln()
		if s == None:
			return None
		return s.decode()

	def readll():
		s = reads()
		if s == None:
			return None
		i, err = strconv.ParseInt(s, 10, 64)
		if err!= None:
			raise err
		return i

	def readi():
		return int(readll())

	def readf():
		s = reads()
		if s == None:
			return None
		i, err = strconv.ParseFloat(s, 64)
		if err!= None:
			raise err
		return i

	def printf(f, *args):
		return OutputWriter.write(bytes(f % args, 'ascii'))

	def println(args):
		s = ''
		for _, v in enumerate(args):
			s += str(v)
			if _ < len(args) - 1:
				s +=''
		s += '\n'
		OutputWriter.write(bytes(s, 'ascii'))

	def eprintf(f, *args):
		return os.Stderr.write(bytes(f % args, 'ascii'))

	def eprintln(args):
		s = ''
		for _, v in enumerate(args):
			s += str(v)
			if _ < len(args) - 1:
				s +=''
		s += '\n'
		os.Stderr.write(bytes(s, 'ascii'))

	def debugf(f, *args):
		if not DEBUG:
			return
		eprintf(f, *args)

	def debug(args):
		if not DEBUG:
			return
		eprintln(args)

	# -----------------------------------------------------------------------------
	# Simple math functions

	# min returns the minimum of two integers.
	def min(a, b):
		if a < b:
			return a
		return b

	# minll returns the minimum of two int64.
	def minll(a, b):
		if a < b:
			return a
		return b

	# minf returns the minimum of two float64.
	def minf(a, b):
		if a < b:
			return a
		return b

	# max returns the maximum of two integers.
	def max(a, b):
		if a < b:
			return b
		return a

	# maxll returns the maximum of two int64.
	def maxll(a, b):
		if a < b:
			return b
		return a

	# maxf returns the maximum of two float64.
	def maxf(a, b):
		if a < b:
			return b
		return a

	# abs returns the absolute value of an integer.
	def abs(a):
		if a < 0:
			return -a
		return a

	# absll returns the absolute value of an int64.
	def absll(a):
		if a < 0:
			return -a
		return a

	# absf returns the absolute value of a float64.
	def absf(a):
		if a < 0:
			return -a
		return a

	# egcd returns the greatest common divisor of a and b, along with x and y such that a*x + b*y = gcd.
	def egcd(a, b):
		if b == 0:
			return a, 1, 0
		d, x, y = egcd(b, a % b)
		return d, y, x - a // b * y

	def egcdll(a, b):
		if b == 0:
			return a, 1, 0
		d, x, y = egcdll(b, a % b)
		return d, y, x - a // b * y

	# gcd returns the greatest common divisor of two integers.
	def gcd(a, b):
		d, _, _ = egcd(a, b)
		return d

	# gcdll returns the greatest common divisor of two int64.
	def gcdll(a, b):
		d, _, _ = egcdll(a, b)
		return d

	# -----------------------------------------------------------------------------
	# Utilities

	def sumSlice(a):
		res = 0
		for _, v in enumerate(a):
			res += v
		return res

	def sumSlicell(a):
		res = 0
		for _, v in enumerate(a):
			res += v
		return res

	# -----------------------------------------------------------------------------
	# Main function

	def init():
		# for non-interactive
		SetInput(os.Stdin)
		SetOutput(os.Stdout)

		# Enable below when interactive. Its ok to leave above intact.
		SetInteractive(os.Stdout, os.Stdin)

	# Main function for solving the problem.
	def main():
		defer Flush()

		# Read input
		h, w, a = readi(), readi(), readi()
		m = make([][], h)
		for i in range(h):
			m[i] = make([]int, w)
			s = reads()
			for j in range(w):
				m[i][j] = int(s[j])

		# Solve the problem
		answer = solve(h, w, a, m)

		# Print the result
		println(answer)

	# Function to count the number of black cells in a grid.
	def countBlack(h, w, m):
		count = 0
		debug("new table")
		for i in range(h):
			for j in range(w):
				if m[i][j] == Black:
					count += 1
			debug(m[i])
		debug("result : ", count)
		return count

	# Function to solve the problem.
	def solve(h, w, a, m):
		result = 0
		for i in range(1 << h):
			for k in range(1 << w):
				tmp = make([][], h)
				for j in range(h):
					tmp[j] = make([]int, w)
					copy(tmp[j], m[j])
				for j in range(h):
					hPainted = (1 << j & i)
					if hPainted > 0:
						debug("painted ", j, 1 << j, i, hPainted)
						for l in range(w):
							tmp[j][l] = 1
				for j in range(w):
					wPainted = (1 << j & k)
					if wPainted > 0:
						for l in range(h):
							tmp[l][j] = 1
				debug("i", format(i, 'b'))
				debug("k", format(k, 'b'))
				if countBlack(h, w, tmp) == a:
					result += 1
		return result

	# Constants for black cell representation.
	Black = 35

	init()
	main()

# 