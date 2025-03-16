
# Declare variables
n = 0
m = 0

# Read input
n = int(input())

# Assign the value of n to m for later use
m = n

# Decrement n by 1
n -= 1

# Loop through n-1 times to calculate the factorial
for i in range(n):
	# Multiply m with current value of n
	m *= n

# Print the result
print(m)

# 