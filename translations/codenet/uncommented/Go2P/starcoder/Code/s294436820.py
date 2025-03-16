
# <START-OF-CODE>

import sys

DEBUG = False

# Returns next token from input.  It must be initialized by SetInput()
# before the first call.
var nextToken = None
var nextLine = None

# Holds a buffer for output.  It must be initialized by SetOutput().
# All IO functions (read*() and [e]print*()) should write to OutputWriter
# instead of this.
var OutputBuffer = None

# Holds an io.Writer.  It must be initialized by SetOutput()
var OutputWriter = None

# Set IO functions for interactive input/output.
def SetInteractive(w, r):
	SetUnbufferedInput(r)
	OutputBuffer = None
	OutputWriter = w

# Setup OutputBuffer and OutputWriter.
def SetOutput(w):
	global OutputBuffer
	OutputBuffer = sys.stdout
	OutputWriter = w

# Flushes OutputBuffer
def Flush():
	if OutputBuffer!= None:
		OutputBuffer.flush()

# Returns true if c is a white space
def IsSpace(c):
	return c =='' or c == '\t' or c == '\n' or c == '\r' or c == '\f' or c == '\v'

def IsNewLine(c):
	return c == '\n' or c == '\r'

# Setup nextToken with input buffer.
def SetInput(r):
	global nextToken
	global nextLine
	buf = []
	var b = []byte

	var i = 0
	rest = lambda: (b[i:], None) if i < len(b) and not IsSpace(b[i]) else (None, io.EOF)
	initial = lambda: (b, None) if i < len(b) and not IsSpace(b[i]) else (None, io.EOF)
	nextToken = initial

	restLn = lambda: (b[i:], None) if i < len(b) and not IsNewLine(b[i]) else (None, io.EOF)
	initialLn = lambda: (b, None) if i < len(b) and not IsNewLine(b[i]) else (None, io.EOF)
	nextLine = initialLn

	for b in r:
		buf.append(b)
		i = len(buf) - 1
		nextToken = rest
		if not IsSpace(b) and not IsNewLine(b):
			break
	nextToken = initial
	nextLine = initialLn

# Setup nextToken without input buffer.
def SetUnbufferedInput(r):
	global nextToken
	global nextLine
	buf = r
	var b = []byte

	var i = 0
	nextToken = lambda: (b[i:], None) if i < len(b) and not IsSpace(b[i]) else (None, io.EOF)
	nextLine = lambda: (b[i:], None) if i < len(b) and not IsNewLine(b[i]) else (None, io.EOF)

	for b in r:
		i = len(b) - 1
		nextToken = rest
		if not IsSpace(b) and not IsNewLine(b):
			break
	nextToken = initial
	nextLine = initialLn

# -----------------------------------------------------------------------------

# IO functions

# Reads next token and return it as []byte
def readb():
	b, err = nextToken()
	if err!= None:
		raise err
	return b[:len(b):len(b)]

# Reads next token and return it as string
def reads():
	return str(readb(), 'utf-8')

# Read next line as []byte.  Trailing '\n' will not be included.
# See also comments on readb()
def readbln():
	b, err = nextLine()
	if err!= None:
		raise err
	return b[:len(b):len(b)]

# Read next line as string
def readsln():
	return str(readbln(), 'utf-8')

# Reads next token and return it as int64
def readll():
	i, err = int(reads()), None
	if err!= None:
		raise err
	return i

# Reads next token and return it as int
def readi():
	return int(readll())

# Reads next token and return it as float64
def readf():
	f, err = float(reads()), None
	if err!= None:
		raise err
	return f

# Write args to OutputWriter with the format f
def printf(f, *args):
	return OutputWriter.write(f % args)

# Write args to OutputWriter without format
def println(*args):
	return OutputWriter.write(str(args) + '\n')

# Write args to stderr with the format f
def eprintf(f, *args):
	return sys.stderr.write(f % args)

# Write args to stderr without format
def eprintln(*args):
	return sys.stderr.write(str(args) + '\n')

def debugf(f, *args):
	if not DEBUG:
		return
	return sys.stderr.write(f % args)

def debug(*args):
	if not DEBUG:
		return
	return sys.stderr.write(str(args) + '\n')

# -----------------------------------------------------------------------------

# Utilities

def sumSlice(a):
	res = 0
	for v in a:
		res += v
	return res

def sumSlicell(a):
	res = 0
	for v in a:
		res += v
	return res

def readInts(N):
	if N == 0:
		N = readi()
	a = [0] * N
	for i in range(N):
		a[i] = readi()
	return N, a

def readIntsll(N):
	if N == 0:
		N = readi()
	a = [0] * N
	for i in range(N):
		a[i] = readll()
	return N, a

# -----------------------------------------------------------------------------

# Simple math functions

INF  = 1000000007
INF2 = 1000000009
INF3 = 998244353

def min(a, b):
	if a < b:
		return a
	return b

def minll(a, b):
	if a < b:
		return a
	return b

def minf(a, b):
	if a < b:
		return a
	return b

def max(a, b):
	if a < b:
		return b
	return a

def maxll(a, b):
	if a < b:
		return b
	return a

def maxf(a, b):
	if a < b:
		return b
	return a

def abs(a):
	if a < 0:
		return -a
	return a

def absll(a):
	if a < 0:
		return -a
	return a

def absf(a):
	if a < 0:
		return -a
	return a

# egcd(a, b) returns d, x, y:
#   d is gcd(a,b)
#   x, y are  integers that satisfy ax + by = d
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

def gcd(a, b):
	d, _, _ = egcd(a, b)
	return d

def gcdll(a, b):
	d, _, _ = egcdll(a, b)
	return d

# set up IO functions
def init():
	# for non-interactive
	SetInput(sys.stdin)
	SetOutput(sys.stdout)

	# Enable below when interactive.  Its ok to leave above intact.
	#SetInput(open("io/tests.txt", "r"))
	#SetOutput(open("io/tests.txt", "w"))
	#SetInteractive(sys.stdout, sys.stdin)

def main():
	defer Flush()
	h, w, k = readi(), readi(), readi()
	m = [0] * h
	for i in range(h):
		m[i] = [0] * w
		s = reads()
		for j in range(w):
			m[i][j] = int(s[j])
	answer = solve(h, w, k, m)
	println(answer)

def countBlack(h, w, m):
	count = 0
	debug("new table")
	for i in range(h):
		for j in range(w):
			if m[i][j] == 35:
				count += 1
		debug(m[i])
	debug("result : ", count)
	return count

def solve(h, w, a, m):
	result = 0
	for i in range(1 << h):
		for k in range(1 << w):
			tmp = [0] * h
			for j in range(h):
				tmp[j] = m[j][:]
			for j in range(h):
				hPainted = (1 << j & i)
				if hPainted > 0:
					debug("painted ", j, 1 << j, i, hPainted)
					for l in range(w):
						tmp[j][l] = 1
				debug(tmp[j])
			for j in range(w):
				wPainted = (1 << j & k)
				if wPainted > 0:
					for l in range(h):
						tmp[l][j] = 1
				debug(tmp[l])
			debug("i", bin(i))
			debug("k", bin(k))
			if countBlack(h, w, tmp) == a:
				result += 1
	return result

# 