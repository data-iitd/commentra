import sys

# getNextWord reads the next word from the scanner and returns it as a string.
def getNextWord(scanner):
	scanner.readline()
	return scanner.readline()

# getNextInt reads the next word from the scanner, converts it to an integer, and returns it.
def getNextInt(scanner):
	return int(getNextWord(scanner))

def main():
	# Set the input source to standard input; if a file is provided as an argument, open that file.
	fp = sys.stdin
	if len(sys.argv) > 1:
		fp = open(sys.argv[1], "r")

	# Create a new scanner to read from the input source and configure it to split input into words.
	scanner = fp.readline()
	scanner = fp.readline()

	# Read the first two integers, n and m, from the input.
	n = getNextInt(scanner)
	m = getNextInt(scanner)

	# Initialize a map to store the positions that are blocked (not allowed).
	aa = {}
	for i in range(0, m):
		# Read each blocked position and mark it in the map.
		aa[getNextInt(scanner)] = 1

	# Create a dynamic programming array to store the number of ways to reach each position.
	dp = [0] * (n+1)
	dp[0] = 1 # Base case: There is one way to be at the starting position (doing nothing).

	# Iterate through each position from 0 to n.
	for i in range(0, n):
		# Check the next two positions (i+1 and i+2) to see if they can be reached.
		for ii in range(1, 3):
			if i+ii > n:
				break # If the next position is out of bounds, stop checking.
			_, ok = aa[i+ii] # Check if the next position is blocked.
			if ok:
				continue # If blocked, skip to the next iteration.
			# Update the number of ways to reach position i+ii based on the current position i.
			dp[i+ii] += dp[i]
			dp[i+ii] %= 1000000007 # Ensure the result stays within the modulo limit.

	# Output the total number of ways to reach position n.
	print(dp[n])

# 