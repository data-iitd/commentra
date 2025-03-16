# Declare four integer variables to store input values
a, b, c, d = int(input()), int(input()), int(input()), int(input())

# Check if the condition is true
if (a*b%2==1 and (c+d)%2==1):
	# If the condition is true, print "No" to the output stream
	print("No")
# If the condition is false, print "Yes" to the output stream
else:
	print("Yes")

