# Include the standard input/output library

# Declare three integer variables: a, b, and c
a, b, c = 0, 0, 0

# Use the input function to read three integers from the standard input and store them in variables a, b, and c
a, b, c = map(int, input().split())

# Check if the condition a < b and b < c is true. If it is, print "Yes" to the standard output using the print function. Otherwise, print "No"
if a < b and b < c:
	print("Yes") # If the condition is true, print "Yes"
else:
	print("No") # If the condition is false, print "No"

# 