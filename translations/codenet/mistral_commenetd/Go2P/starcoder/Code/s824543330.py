# Import the "fmt" package for formatted I/O
import sys

def main():
	# Declare and initialize two integer variables, a and b, using sys.stdin.readline()
	a, b = map(int, sys.stdin.readline().split())

	# Check if the product of a and b is even using the modulo operator (%).
	# If the result is zero, it means that a and b are both even or one of them is even and the other is a multiple of 2.
	if a*b%2 == 0:
		# If the condition is true, print the message "Even"
		print("Even")
	else:
		# If the condition is false, print the message "Odd"
		print("Odd")

# End of code

