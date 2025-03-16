
# Include the standard input/output library
import sys

# Declare the main function
def main():
	# Declare three integer variables: a, b, and h
	a = 0
	b = 0
	h = 0

	# Read three integers from the user and store them in variables a, b, and h
	a = int(raw_input("Enter the value of a: "))
	b = int(raw_input("Enter the value of b: "))
	h = int(raw_input("Enter the value of h: "))

	# Calculate the area of the rectangle using the formula: area = length * width
	area = (a+b)*h/2

	# Print the result, which is the area of the rectangle
	print area

# Call the main function
main()

# Indicate that the program has run successfully
sys.exit(0)

