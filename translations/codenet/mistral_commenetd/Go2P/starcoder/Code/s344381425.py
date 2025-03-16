# Import the "fmt" package for formatted I/O
import sys

def main():
	# Declare and initialize three integer variables "a", "b", and "c"
	# with values read from the standard input using the Scanf function
	a, b, c = map(int, sys.stdin.readline().split())

	# Check if the condition "a < b and b < c" is true using an if statement
	if a < b and b < c:
		# If the condition is true, print the string "Yes" to the standard output
		print("Yes")
	else:
		# If the condition is false, print the string "No" to the standard output
		print("No")

	# Return from the main function
	return

# End of code

