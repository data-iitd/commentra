# Include the standard input/output library
import sys

# Define the main function, the entry point of the program
def main():
	# Declare three integer variables
	a = 0
	b = 0
	c = 0
	
	# Read three integers from the user and store them in variables a, b, and c
	a = int(sys.stdin.readline())
	b = int(sys.stdin.readline())
	c = int(sys.stdin.readline())
	
	# Check if a is less than b and b is less than c, and print "Yes" if true
	if a < b and b < c:
		print("Yes")
	else:
		print("No")

# Call the main function, starting the program
if __name__ == "__main__":
	main()

# 