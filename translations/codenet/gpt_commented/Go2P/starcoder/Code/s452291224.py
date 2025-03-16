# Declare three integer variables A, B, and C
A, B, C = 0, 0, 0

# Read three integer values from standard input and store them in A, B, and C
A, B, C = map(int, input().split())

# Check if the expression C - A + B is less than 0
if C-A+B < 0:
	# If the expression is less than 0, print "0"
	print("0")
else:
	# If the expression is 0 or greater, print the result of C - A + B
	print(C-A+B)

