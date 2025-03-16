import sys

# Declare global variables for reading input and writing output.
input = sys.stdin.readline
# input = sys.stdin.read

# Define constants for the program.
MOD = 1000000000 + 7
ALPHABET_NUM = 26
INF_INT64 = 1 << 60
INF_BIT60 = 1 << 60

# Declare memoization array and string variable.
memo = [0] * ALPHABET_NUM
str = ""

def main():
	# Read input until EOF.
	while True:
		str = input()
		if str == "":
			break
		# Count occurrences of each letter.
		for i in range(len(str)):
			c = str[i]

			if 'a' <= c and c <= 'z':
				# Increment count for lowercase letters.
				memo[ord(c) - ord('a')] += 1
			elif 'A' <= c and c <= 'Z':
				# Increment count for uppercase letters.
				memo[ord(c) - ord('A')] += 1
			else:
				# Ignore non-alphabet characters.
				continue

	# Print the count of each letter.
	for i in range(ALPHABET_NUM):
		print(chr(i + ord('a')), ":", memo[i])

# Call the main function.
if __name__ == "__main__":
	main()

# 