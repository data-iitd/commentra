
# Include the iostream library for input and output operations
import sys

# Define the main function
def main():
	# Read the size of the string from the standard input
	n = int(sys.stdin.readline())

	# Read the string from the standard input
	s = sys.stdin.readline()

	# Initialize a counter variable 'cnt' to 0
	cnt = 0

	# Beginning of the first for loop
	for i in range(n):
		# Increment the counter variable 'cnt'
		cnt += 1

		# Initialize a variable 'j' to check for the next character
		j = i + 1

		# Beginning of the inner for loop
		while j < n:
			# Compare the current character with the next characters in the string
			if s[i]!= s[j]:
				break

			# If the current character is repeated, update the index 'i' to the previous index
			j += 1

		i = j - 1

	# Output the result
	print(cnt)

# Call the main function
if __name__ == "__main__":
	main()

