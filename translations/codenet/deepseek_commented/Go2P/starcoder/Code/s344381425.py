
# Declare three integer variables to store input values
a, b, c = 0, 0, 0

# Read three integers from standard input and assign them to a, b, and c
a, b, c = map(int, input().split())

# Check if a is less than b and b is less than c
if a < b and b < c:
	# If the condition is true, print "Yes"
	print("Yes")
else:
	# Otherwise, print "No"
	print("No")

# Return from the function
return

