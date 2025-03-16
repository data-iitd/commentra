
# Function to find the greatest common divisor (GCD) of two numbers
def gcd(a, b):
	# Base case: if 'a' is 0, return 'b' as the GCD
	if a == 0:
		return b
	# Recursive case: call the function with the remainder of 'a' and 'b' as arguments
	return gcd(b % a, a)

# Declare and read the value of 'R' from the standard input
R = int(input())

# Check the value of 'R' and print the corresponding output
if R < 1200:
	print("ABC") # Output: "ABC" if 'R' is less than 1200
elif R >= 2800:
	print("AGC") # Output: "AGC" if 'R' is greater than or equal to 2800
else:
	print("ARC") # Output: "ARC" if 'R' is between 1200 and 2800 (inclusive)

