# Declare variables A, B, and C of type int
A, B, C = 0, 0, 0

# Read three integers from the standard input using input() function
A, B, C = map(int, input().split())

# Check if the condition C-A+B is less than zero
if C-A+B < 0:
	# If the condition is true, print zero as output
	print("0")
else:
	# If the condition is false, calculate the value of C-A+B and print it as output
	print(C-A+B)

