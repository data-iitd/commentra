

# Initialize an array 'c' of size 26 to store the count of each character.
c = [0] * 26

# Use a loop to read strings from the standard input using input() until the end of file is reached.
while True:
	try:
		# Read a string from the standard input.
		str = input()
		# Initialize a pointer 'p' to traverse the string'str'.
		for p in str:
			# Use nested if conditions to check if the current character is a lowercase or uppercase letter.
			if 'a' <= p and p <= 'z':
				# Increment the count of the corresponding character in the 'c' array.
				c[ord(p) - ord('a')] += 1
			elif 'A' <= p and p <= 'Z':
				# Increment the count of the corresponding character in the 'c' array.
				c[ord(p) - ord('A')] += 1
	except EOFError:
		# Break out of the loop when the end of file is reached.
		break

# Use a loop to print the count of each character and its corresponding character.
for i in range(26):
	print(chr(ord('a') + i), ':', c[i])

