# Declare two integer variables "n" and "k"
n, k = map(int, input().split())

# Check if the value of "k" is less than or equal to the middle index of the slice "n"
if k <= (n+n%2)/2:
	# If the condition is true, print "YES" to the standard output
	print("YES")
else:
	# If the condition is false, print "NO" to the standard output
	print("NO")

# End of the code

