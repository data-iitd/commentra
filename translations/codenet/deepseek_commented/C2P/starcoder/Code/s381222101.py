# Step 1: Include the standard input/output library.
import sys

# Step 2: Define the main function.
def main():
	# Step 3: Declare three integer variables a, b, and h.
	a = 0
	b = 0
	h = 0
	
	# Step 4: Read three integer values from the user and store them in a, b, and h.
	a = int(raw_input("Enter a: "))
	b = int(raw_input("Enter b: "))
	h = int(raw_input("Enter h: "))
	
	# Step 5: Calculate the area of a trapezoid using the formula (a+b)*h/2.
	area = (a+b)*h/2
	
	# Step 6: Print the area of a trapezoid.
	print "Area of a trapezoid is", area

# Step 7: End the main function and return 0.
if __name__ == "__main__":
	main()
	sys.exit(0)

