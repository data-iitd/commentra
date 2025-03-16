
import sys

# Initializes the scanner to read from standard input efficiently.
def scanInit():
	const cap = 1000 * 1024
	buf = bytearray(cap)
	sc = bufio.Scanner(sys.stdin.buffer, cap)
	sc.split(bufio.ScanWords)
	return

# Reads an integer from the input.
def nextInt():
	sc.scan()
	i, e = int(sc.text()), None
	if e!= None:
		raise e
	return i

# Reads a string from the input.
def nextStr():
	sc.scan()
	return sc.text()

# Main function that executes the program logic.
def main():
	scanInit()

	# Read the input string.
	s = nextStr()

	# Initialize the character to check against the string.
	c = ord('a')

	# Iterate through the alphabet to find the first missing character.
	for j in range(26):
		found = False
		for i in range(len(s)):
			if s[i] == c:
				found = True
				break
		if found == False:
			print(chr(c))
			return
		c += 1

	# If no missing character is found, print "None".
	print("None")

# 