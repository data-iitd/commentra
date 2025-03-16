# <BEGIN-OF-CODE>

# I/O
class Scanner:
	def __init__(self, stream):
		self.stream = stream
		self.buffer = ""
		self.pos = 0

	def read(self):
		if self.pos >= len(self.buffer):
			self.buffer = self.stream.readline()
			self.pos = 0
		if self.pos < len(self.buffer):
			self.pos += 1
			return self.buffer[self.pos - 1]
		return ""

	def readInt(self):
		result = 0
		sign = 1
		c = self.read()
		for c == " ":
			c = self.read()
		if c == "-":
			sign = -1
			c = self.read()
		for c >= "0" and c <= "9":
			result = result * 10 + int(c)
			c = self.read()
		return sign * result

def run(input, output):
	sc = Scanner(input) # Initialize a new Scanner
	N = sc.readInt() # Read the first integer from input

	#... (empty block for N == 0 case)

	if N < 4: # Check if N is less than 4
		print(0) # Print 0 if N is less than 4
		return 0 # Return 0

	#... (variable initialization block)

	nr, nb, ng = 0, 0, 0 # Declare and initialize variables for red, blue, and green balls

	for c in S: # Iterate through each character in the string S
		if c == 'R': # If the character is 'R'
			nr += 1 # Increment the nr counter
		if c == 'B': # If the character is 'B'
			nb += 1 # Increment the nb counter
		if c == 'G': # If the character is 'G'
			ng += 1 # Increment the ng counter

	same = 0 # Initialize a counter for the number of same-colored groups of three balls

	#... (outer loop block)

	for a in range(1, N): # Iterate through each index a from 1 to N-1
		i, j, k = 0, a, 2 * a # Initialize indices i, j, and k to 0, a, and 2*a respectively

		#... (inner loop block)

		for k < N: # Iterate through each index k from a*2 to N-1
			#... (check condition block)

			if S[i]!= S[j] and S[i]!= S[k] and S[j]!= S[k]: # Check if the balls at indices i, j, and k have different colors
				same += 1 # If so, increment the same counter
			#... (update indices block)

			i += 1 # Increment index i
			j += 1 # Increment index j
			k += 1 # Increment index k

	tot = nr * nb * ng # Calculate the total number of balls

	#... (comment out or remove the following lines as they are not used in the final solution)

	# tot = 0 # Initialize a variable for the total number of balls
	# sum = 0 # Initialize a variable for the number of distinct triples
	# sum2 = 0 # Initialize a variable for the number of distinct triples with the same middle index

	#... (calculate the final result)

	print(tot - same) # Print the result, which is the total number of balls minus the number of same-colored groups of three balls

	return 0 # Return 0 to indicate successful execution

if __name__ == "__main__":
	run(sys.stdin, sys.stdout) # Run the main function with standard input and output

# 