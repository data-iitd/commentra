# Import the sys module
import sys

# Read the first string from standard input
s = sys.stdin.readline()

# Initialize variable c with 'a'
c = 'a'

# Check all characters from 'a' to 'z' in the string s
for j in range(26):
	# Initialize variable found as false
	found = False

	# Iterate through each character in the string s
	for i in range(len(s)):
		# If current character matches c, set found to true and break the loop
		if s[i] == c:
			found = True
			break
	# If character c is not found in the string s, print it and return
	if found == False:
		print(c)
		return
	# Increment variable c
	c = chr(ord(c) + 1)

# If no character from 'a' to 'z' is found in the string s, print "None"
print("None")

