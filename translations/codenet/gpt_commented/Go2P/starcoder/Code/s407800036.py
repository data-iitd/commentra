# Declare variables A, B, and C to hold integer values
A = 0
B = 0
C = 0

# Read three integers from standard input
A, B, C = map(int, input().split())

# Check if C is within the range defined by A and B (inclusive)
if C >= A and C <= B:
	# If C is within the range, print "Yes"
	print("Yes")
else:
	# If C is outside the range, print "No"
	print("No")

