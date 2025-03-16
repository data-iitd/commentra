# <START-OF-CODE>

# Prompt user to enter the number of test cases
j = int(input("Enter the number of test cases: "))

# Loop through each test case
for i in range(j):
	# Prompt user to enter the values of a, b, and c for the current test case
	a, b, c = map(int, input("Enter the values of a, b, and c for test case {}: ".format(i+1)).split())

	# Initialize max with the value of a
	max = a

	# Initialize k with 0
	k = 0

	# Check if max is less than or equal to b
	if max <= b:
		# If true, update max with the value of b
		max = b
		# Set k to 1 to indicate that b is greater than a
		k = 1

	# Check if max is less than or equal to c
	if max <= c:
		# If true, update max with the value of c
		max = c
		# Set k to 2 to indicate that c is greater than max (which was previously a or b)
		k = 2

	# Multiply max with itself to calculate max*max
	max *= max
	# Multiply a with itself to calculate a*a
	a *= a
	# Multiply b with itself to calculate b*b
	b *= b
	# Multiply c with itself to calculate c*c

	# Check if k is 0 and max is equal to the sum of b and c
	if k == 0 and max == b+c:
		# If true, print "YES" to the console
		print("YES")
	# Check if k is 1 and max is equal to the sum of a and c
	elif k == 1 and max == a+c:
		# If true, print "YES" to the console
		print("YES")
	# Check if k is 2 and max is equal to the sum of a and b
	elif k == 2 and max == a+b:
		# If true, print "YES" to the console
		print("YES")
	# If none of the above conditions are true
	else:
		# Print "NO" to the console
		print("NO")

# 