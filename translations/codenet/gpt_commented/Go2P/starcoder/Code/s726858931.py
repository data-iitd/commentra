import sys

# Initialize a new scanner to read input from standard input
sc = __import__('bufio').__new__(__import__('bufio').BufferedReader)
sc.__init__(sys.stdin)
sc.readline = lambda: sys.stdin.readline().strip()

# Read the input string
s = next(sc.readline, '')

# Start checking for the first missing lowercase letter from 'a'
c = ord('a')

# Loop through all lowercase letters from 'a' to 'z'
for j in range(26):
	found = False # Flag to check if the current letter is found in the input string
	# Check if the current letter exists in the input string
	for i in range(len(s)):
		if s[i] == chr(c):
			found = True # Set the flag to true if the letter is found
			break
	# If the letter was not found, print it and exit
	if found == False:
		print(chr(c))
		break
	c += 1 # Move to the next letter

# If all letters from 'a' to 'z' are found, print "None"
if c == ord('z') + 1:
	print('None')

# 