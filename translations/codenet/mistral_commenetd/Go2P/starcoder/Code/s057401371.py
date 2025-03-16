# Importing required packages
import sys

# Reading the first line from standard input and storing it in the string's'
s = sys.stdin.readline()

# Declaring and initializing a variable 'd' with the value of 'a' - 'A'
d = ord('a') - ord('A')

# Iterating through each character 'r' in the string's'
for r in s:
	# Declaring and initializing a variable 'rr' with the value of 'r'
	rr = r

	# Checking if the current character 'r' is an uppercase letter
	if ord('A') <= ord(r) and ord(r) <= ord('Z'):
		# If yes, adding the value of 'd' to 'r' and storing it in 'rr'
		rr = chr(ord(r) + d)
	elif ord('a') <= ord(r) and ord(r) <= ord('z'):
		# If no, subtracting the value of 'd' from 'r' and storing it in 'rr'
		rr = chr(ord(r) - d)

	# Printing the transformed character 'rr' to the standard output
	sys.stdout.write(rr)

# Printing a newline character after the transformation is complete
sys.stdout.write('\n')

# 