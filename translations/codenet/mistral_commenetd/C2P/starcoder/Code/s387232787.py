
# Initialize an array 'c' of size 26 to store the count of each character.
c = [0] * 26

# Use a loop to read strings from the standard input using input() until the end of file is reached.
while True:
	# Read a string from the standard input using input().
	str = input()
	# Check if the string is empty.
	if str == "":
		# Break out of the loop if the string is empty.
		break
	# Use a loop to traverse the string'str'.
	for p in str:
		# Check if the current character is a lowercase or uppercase letter.
		if 'a' <= p and p <= 'z':
			# Increment the count of the corresponding character in the 'c' array.
			c[ord(p) - ord('a')] += 1
		elif 'A' <= p and p <= 'Z':
			# Increment the count of the corresponding character in the 'c' array.
			c[ord(p) - ord('A')] += 1

# Use a loop to print the count of each character and its corresponding character.
for i in range(26):
	print(chr(ord('a') + i), ':', c[i])

# 