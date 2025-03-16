# Declare integer variables to hold input values
r, d, x = int(input()), int(input()), int(input())

# Start a loop that will run 10 times
for i in range(10):
	# Update the value of x using the formula r*x - d
	x = r*x - d
	# Print the updated value of x
	print(x)

