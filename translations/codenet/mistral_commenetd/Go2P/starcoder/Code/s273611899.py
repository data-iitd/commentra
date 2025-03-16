# Importing the'sys' module for input/output operations
import sys

# Function to find triples that sum up to 'x'
def find_triples(n, x):
	# Declaring an integer variable 'c' to store the count of triples
	c = 0

	# Inner loop to find triples that sum up to 'x'
	for i in range(1, n-2):
		# Inner loop to compare 'j' with all the remaining numbers
		for j in range(i+1, n-1):
			# Inner loop to compare 'k' with all the remaining numbers
			for k in range(j+1, n):
				# Check if the sum of 'i', 'j', and 'k' equals 'x'
				if i+j+k == x:
					# Increment the count 'c' if the condition is true
					c += 1

	# Return the count of triples that sum up to 'x'
	return c

# Main function
def main():
	# Loop infinitely until user inputs 0 for both 'n' and 'x'
	while True:
		# Read user input for 'n' and 'x'
		n, x = map(int, input().split())

		# Check if user has entered 0 for both 'n' and 'x' to break the loop
		if n == 0 and x == 0:
			break

		# Find the count of triples that sum up to 'x'
		c = find_triples(n, x)

		# Print the count of triples that sum up to 'x'
		print(c)

# Calling the main function
if __name__ == "__main__":
	main()

# 