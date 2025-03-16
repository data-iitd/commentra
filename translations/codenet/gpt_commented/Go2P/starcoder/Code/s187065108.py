# Read three integers from input: r, D, and x
r, D, x = map(int, input().split())

# Perform calculations and print the result for 10 iterations
for i in range(1, 11):
	x = r*x - D # Update x based on the formula
	print(x) # Print the current value of x

