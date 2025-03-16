# Declare four integer variables to store user input
a, b, c, d = int(input()), int(input()), int(input()), int(input())

# Check if the product of a and b is odd and if the sum of c and d is also odd
if (a*b)%2==1 and (c+d)%2==1:
	# If both conditions are true, print "No"
	print("No")
else:
	# Otherwise, print "Yes"
	print("Yes")

