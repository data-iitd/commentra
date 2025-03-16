
# Initialize a scanner for reading input from stdin
import sys
import re

sc = re.compile(r"(\d+)")

def nextStr():
	return sc.match(input()).group(1)

def nextInt():
	return int(nextStr())

# Main function to read input and process it
if __name__ == "__main__":
	# Read the number of test cases
	n = nextInt()

	# Initialize variables for processing the input
	ans = 0
	aPrev = 0

	# Process each test case
	for i in range(n):
		# Read the next integer as 'a'
		a = nextInt()

		# Check if 'a' is valid based on the conditions in the problem statement
		if a > i or a > aPrev+1: # 'a' is not valid, print -1 and exit
			print(-1)
			exit(0)
		elif a == aPrev+1: # Increment the answer if 'a' is consecutive with the previous number
			ans += 1
		else: # Add 'a' to the answer if it's not consecutive but greater than the previous number
			ans += a

		# Update the previous number
		aPrev = a

	# Print the final answer
	print(ans)

	# End of code

