
# Initialize three integer variables 'a', 'b', and 'c'
a, b, c = 0, 0, 0

# Read values of 'a', 'b', and 'c' from the standard input
a, b, c = map(int, input().split())

# Check if the given condition is true
if ((100*a + 10*b + c) % 4 == 0):
	# If the condition is true, print 'YES' to the standard output
	print("YES")
else:
	# If the condition is false, print 'NO' to the standard output
	print("NO")

