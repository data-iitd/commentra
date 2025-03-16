# Declare three integer variables A, B, and C
A, B, C = 0, 0, 0

# Read input values for A, B, and C from the standard input
A, B, C = map(int, input().split())

# Check if the sum of A and B is greater than or equal to C
if A+B >= C:
	# If the condition is true, print "Yes"
	print("Yes")
else:
	# If the condition is false, print "No"
	print("No")

