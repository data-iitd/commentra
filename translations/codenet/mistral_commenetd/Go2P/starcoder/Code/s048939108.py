
import sys

# Initialize a new scanner
def main():
	sc = newScanner()

	# Read the first string from the standard input
	S = sc.next()

	# Check if the string starts with "YAKI"
	if S.startswith("YAKI"):
		print("Yes") # Print "Yes" if the condition is true
	else:
		print("No") # Print "No" if the condition is false

# Minimum function
def min(a, b):
	# Determine the minimum of two integers
	if a > b:
		return b
	return a

# Maximum function
def max(a, b):
	# Determine the maximum of two integers
	if a > b:
		return a
	return b

# Scanner structure definition
class scanner:
	def __init__(self):
		self.r = bufio.NewReaderSize(sys.stdin, 1000)
		self.buf = []
		self.p = 0

	# Next function to read the next token as a string
	def next(self):
		self.pre()
		start = self.p
		for ; self.p < len(self.buf); self.p++:
			if self.buf[self.p] =='':
				break
		result = self.buf[start:self.p]
		self.p++
		return result

	# NextLine function to read the next line as a string
	def nextLine(self):
		self.pre()
		start = self.p
		self.p = len(self.buf)
		return self.buf[start:]

	# NextInt function to read the next integer from the standard input
	def nextInt(self):
		v, _ = int(self.next()), None
		return v

	# NextIntArray function to read an array of integers from the standard input
	def nextIntArray(self):
		self.pre()
		start = self.p
		result = []
		for ; self.p < len(self.buf)+1; self.p++:
			if self.p == len(self.buf) or self.buf[self.p] =='':
				v, _ = int(self.buf[start:self.p]), None
				result = append(result, v)
				start = self.p + 1
		return result

	# Pre function to prepare the scanner for reading the next token
	def pre(self):
		if self.p >= len(self.buf):
			self.readLine()
			self.p = 0

	# ReadLine function to read a line from the standard input
	def readLine(self):
		self.buf = []
		for {
			l, p, e := self.r.ReadLine()
			if e!= None:
				panic(e)
			self.buf = append(self.buf, l...)
			if not p:
				break
		}

# Start the execution if it's the main script
if __name__ == "__main__":
	main()

