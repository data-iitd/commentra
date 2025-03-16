#include <stdio.h>

# Array to store the count of each letter (a-z)
c = [0] * 26

def main():
	# Array to store the input string
	str = []
	
	# Read input strings until there are no more inputs
	while True:
		# Read a string
		s = raw_input()
		
		# Check if the string is empty
		if s == "":
			break
		
		# Append the string to the array
		str.append(s)
	
	# Traverse each string
	for s in str:
		# Pointer to traverse the string
		p = 0
		
		# Traverse each character in the string
		while p < len(s):
			# Check if the character is a lowercase letter
			if ord('a') <= ord(s[p]) and ord(s[p]) <= ord('z'):
				# Increment the count for the corresponding letter
				c[ord(s[p]) - ord('a')] += 1
			# Check if the character is an uppercase letter
			elif ord('A') <= ord(s[p]) and ord(s[p]) <= ord('Z'):
				# Increment the count for the corresponding letter
				c[ord(s[p]) - ord('A')] += 1
			p += 1
	
	# Print the counts for each letter from 'a' to 'z'
	for i in range(26):
		print '%c : %d' % (chr(ord('a') + i), c[i])

if __name__ == "__main__":
	main()

