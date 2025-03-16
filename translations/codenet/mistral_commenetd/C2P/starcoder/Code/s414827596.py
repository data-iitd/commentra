
# <START-OF-CODE>

# Importing the standard input/output library
import sys

# Starting the main function
def main():
	# Declaring variables a to f as integers
	a = 0
	b = 0
	c = 0
	d = 0
	e = 0
	f = 0

	# Declaring variables x and y as double precision floating point numbers
	x = 0.0
	y = 0.0

	# Starting an infinite loop
	while True:
		# Reading input from the standard input
		input = sys.stdin.readline()

		# Checking if the input is valid and can be read into the variables
		if input!= "":
			# Input is valid, so process it
			a,b,c,d,e,f = map(int,input.split())
			y = (c*d-f*a)/(b*d-e*a) # Calculating the value of y using the given formula
			x = (c*e-f*b)/(a*e-d*b) # Calculating the value of x using the given formula
			if y <= 0.0005: # Checking if y is less than or equal to a very small positive number
				y = 0 # If so, set y to 0
			if x <= 0.0005: # Checking if x is less than or equal to a very small positive number
				x = 0 # If so, set x to 0
			# Printing the values of x and y to the standard output with three decimal places
			print("%.3f %.3f" % (x,y))
		else:
			# Input is invalid or end of file reached
			break # Exiting the loop

# Calling the main function
if __name__ == "__main__":
	main()

# 