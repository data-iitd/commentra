# I/O
# Read input from stdin
import sys

# Scanner class to facilitate reading input from stdin
class Scanner:
	def __init__(self):
		self.buf = ""
		self.tokens = []
		self.index = 0
		self.read_input()

	def read_input(self):
		self.buf = sys.stdin.readline()
		self.tokens = self.buf.split()
		self.index = 0

	def has_next(self):
		return self.index < len(self.tokens)

	def next_int(self):
		self.index += 1
		return int(self.tokens[self.index - 1])

# Main function
def main():
	scanner = Scanner()

	# Read four integers from input
	A, B, C, K = scanner.next_int(), scanner.next_int(), scanner.next_int(), scanner.next_int()

	# Determine the maximum value among A, B, and C
	ma = max(A, B, C)
	rest = 0 # Initialize the rest variable to hold the sum of the other two values

	# Calculate the sum of the two smaller values
	if ma == A:
		rest += B + C
	elif ma == B:
		rest += A + C
	else:
		rest += A + B

	# Double the maximum value K times
	for i in range(1, K + 1):
		ma *= 2

	# Output the final result: doubled max value plus the sum of the other two
	print(ma + rest)

# Entry point
if __name__ == "__main__":
	main()

