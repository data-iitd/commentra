# Declare variables for radius (r), distance (d), and initial value (x)
r, d, x = 0, 0, 0

# Read input values for r, d, and x from standard input
r, d, x = map(int, input().split())

# Loop 10 times to perform calculations based on the input values
for i in range(10):
	# Update x using the formula: x = r * x - d
	x = r*x - d
	
	# Print the updated value of x to the standard output
	print(x)

# 