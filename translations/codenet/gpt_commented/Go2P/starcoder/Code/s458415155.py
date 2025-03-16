# <START-OF-CODE>
import sys

# scanner wraps sys.stdin to provide convenient methods for reading input.
class scanner:
	def __init__(self):
		self.buf = sys.stdin.buffer
		self.sc = self.buf.readline
		self.ln = self.buf.readline
		self.f = self.buf.read
		self.s = self.buf.read
		self.int = int
		self.str = str
		self.float = float
		self.bool = bool
		self.byte = bytes
		self.complex = complex
		self.list = list
		self.tuple = tuple
		self.set = set
		self.dict = dict
		self.abs = abs
		self.all = all
		self.any = any
		self.ascii = ascii
		self.bin = bin
		self.bool = bool
		self.bytearray = bytearray
		self.bytes = bytes
		self.callable = callable
		self.chr = chr
		self.classmethod = classmethod
		self.compile = compile
		self.complex = complex
		self.delattr = delattr
		self.dict = dict
		self.dir = dir
		self.divmod = divmod
		self.enumerate = enumerate
		self.eval = eval
		self.exec = exec
		self.filter = filter
		self.float = float
		self.format = format
		self.frozenset = frozenset
		self.getattr = getattr
		self.globals = globals
		self.hasattr = hasattr
		self.hash = hash
		self.help = help
		self.hex = hex
		self.id = id
		self.input = input
		self.int = int
		self.isinstance = isinstance
		self.issubclass = issubclass
		self.iter = iter
		self.len = len
		self.list = list
		self.locals = locals
		self.map = map
		self.max = max
		self.memoryview = memoryview
		self.min = min
		self.next = next
		self.object = object
		self.oct = oct
		self.open = open
		self.ord = ord
		self.pow = pow
		self.print = print
		self.property = property
		self.range = range
		self.repr = repr
		self.reversed = reversed
		self.round = round
		self.set = set
		self.setattr = setattr
		self.slice = slice
		self.sorted = sorted
		self.staticmethod = staticmethod
		self.str = str
		self.sum = sum
		self.super = super
		self.tuple = tuple
		self.type = type
		self.vars = vars
		self.zip = zip

# newScanner initializes a new scanner with a specified input reader.
def newScanner(r):
	s = scanner()
	s.buf = r
	s.sc = s.buf.readline
	s.ln = s.buf.readline
	s.f = s.buf.read
	s.s = s.buf.read
	s.int = int
	s.str = str
	s.float = float
	s.bool = bool
	s.byte = bytes
	s.complex = complex
	s.list = list
	s.tuple = tuple
	s.set = set
	s.dict = dict
	s.abs = abs
	s.all = all
	s.any = any
	s.ascii = ascii
	s.bin = bin
	s.bool = bool
	s.bytearray = bytearray
	s.bytes = bytes
	s.callable = callable
	s.chr = chr
	s.classmethod = classmethod
	s.compile = compile
	s.complex = complex
	s.delattr = delattr
	s.dict = dict
	s.dir = dir
	s.divmod = divmod
	s.enumerate = enumerate
	s.eval = eval
	s.exec = exec
	s.filter = filter
	s.float = float
	s.format = format
	s.frozenset = frozenset
	s.getattr = getattr
	s.globals = globals
	s.hasattr = hasattr
	s.hash = hash
	s.help = help
	s.hex = hex
	s.id = id
	s.input = input
	s.int = int
	s.isinstance = isinstance
	s.issubclass = issubclass
	s.iter = iter
	s.len = len
	s.list = list
	s.locals = locals
	s.map = map
	s.max = max
	s.memoryview = memoryview
	s.min = min
	s.next = next
	s.object = object
	s.oct = oct
	s.open = open
	s.ord = ord
	s.pow = pow
	s.print = print
	s.property = property
	s.range = range
	s.repr = repr
	s.reversed = reversed
	s.round = round
	s.set = set
	s.setattr = setattr
	s.slice = slice
	s.sorted = sorted
	s.staticmethod = staticmethod
	s.str = str
	s.sum = sum
	s.super = super
	s.tuple = tuple
	s.type = type
	s.vars = vars
	s.zip = zip
	return s

# Int reads the next integer from the input.
def Int():
	return int(input())

# IntSlice reads a slice of integers from the input with the specified length.
def IntSlice(l):
	if l == 0:
		return []
	sl = [0] * l
	for i in range(l):
		sl[i] = int(input())
	return sl

# iabs returns the absolute value of an integer.
def iabs(x):
	if x < 0:
		return -x
	return x

# solve computes the minimum cost to reach the last height using dynamic programming.
def solve(n, heights):
	t = [math.inf] * (n+1)
	t[0] = 0
	for i in range(1, n):
		if v := t[i-1] + iabs(heights[i]-heights[i-1]); v < t[i]:
			t[i] = v
		if 1 < i:
			if v := t[i-2] + iabs(heights[i]-heights[i-2]); v < t[i]:
				t[i] = v
	return t[n-1]

# main function to execute the program.
def main():
	sc = newScanner()
	n = Int()
	heights = IntSlice(n)
	ans = solve(n, heights)
	print(ans)

if __name__ == '__main__':
	main()
# 