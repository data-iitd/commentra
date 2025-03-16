import sys

# a stores the counts of characters 'M', 'A', 'R', 'C', 'H'
a = []
# ans accumulates the result of the calculations performed by the dfs function
ans = 0

# dfs is a recursive function that calculates the product of 3 elements from slice a
def dfs(left, i, res):
	if left == 0:
		global ans
		ans += res # When no elements are left to multiply, add the result to ans
		return
	for j in range(i, len(a)):
		dfs(left-1, j+1, res*a[j]) # Recursively call dfs with updated parameters

# main function to execute the program
def main():
	io = newIo()
	n = io.nextInt() # Read the number of characters
	dic = {}

	# Count occurrences of 'M', 'A', 'R', 'C', 'H'
	for _ in range(n):
		c = io.nextString()[0]
		if c in dic:
			dic[c] += 1
		else:
			dic[c] = 1

	# Append the counts of 'M', 'A', 'R', 'C', 'H' to slice a
	for k, v in dic.items():
		a.append(v)

	# Call dfs with parameters 3, 0, and 1
	dfs(3, 0, 1)
	print(ans) # Print the final result

# io struct to handle input operations
class io:
	def __init__(self):
		self.reader = sys.stdin
		self.tokens = []
		self.nextToken = 0

	# nextLine reads a full line from the input
	def nextLine(self):
		buffer = []
		for line in self.reader:
			buffer.append(line)
		return ''.join(buffer)

	# nextString retrieves the next token from the tokens slice
	def nextString(self):
		while self.nextToken >= len(self.tokens):
			line = self.nextLine()
			self.tokens = line.split()
			self.nextToken = 0
		r = self.tokens[self.nextToken]
		self.nextToken += 1
		return r

	# nextInt converts the next token to an integer
	def nextInt(self):
		return int(self.nextString())

if __name__ == '__main__':
	main()

