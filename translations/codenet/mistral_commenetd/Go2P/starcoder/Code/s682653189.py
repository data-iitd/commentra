# This file is part of the "main" package.

# Import the "fmt" package.
import fmt

# The main function is the entry point of the program.
def main():
	# Initialize a variable "s" of type string.
	s = ""

	# Read a single string from the standard input (usually the keyboard) and store it in the variable "s".
	fmt.Scan(s)

	# Iterate through each character in the string "s" using a for loop.
	for i in range(len(s)):
		# Print the character at the current index "i" of the string "s" to the standard output (usually the terminal).
		fmt.Print("x")

	# Print a newline character to the standard output.
	fmt.Println("")

	# Indicate the end of the code.

# Call the main function.
main()

