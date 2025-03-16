# by syu
import sys

# Define a custom scanner type that wraps sys.stdin
class Scanner:
	def __init__(self, max=1048576):
		self.buffer = []
		self.max = max
		self.length = 0
		self.pos = 0
		self.read()

	def read(self):
		self.buffer = list(sys.stdin.readline().strip())
		self.length = len(self.buffer)
		self.pos = 0

	def scan(self):
		while self.pos < self.length and isSpace(self.buffer[self.pos]):
			self.pos += 1
		start = self.pos
		for i in range(self.pos, self.length):
			if isSpace(self.buffer[i]):
				return self.buffer[start:i]
		return self.buffer[start:]

	def Int(self):
		return int(self.scan())

# Check if a byte is a whitespace character
def isSpace(b):
	return b =='' or b == '\n' or b == '\r' or b == '\t'

# Print a line to the console with the given arguments
def Pln(*s):
	print(*s, end='')
	print()

# Entry point of the program
def main():
	# Read two integers n and k from standard input
	n, k = Scanner().Int(), Scanner().Int()
	# Check if n is divisible by k
	if n%k == 0:
		# If n is divisible by k, print 0 to the console
		Pln(0)
	else:
		# If n is not divisible by k, print 1 to the console
		Pln(1)

# Check if a byte is a whitespace character
def isSpace(b):
	return b =='' or b == '\n' or b == '\r' or b == '\t'

# Entry point of the program
if __name__ == '__main__':
	main()

