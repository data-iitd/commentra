

n = int(input())
# Use the input() function to read the first integer (n) from the standard input stream

k = int(input())
# Use the input() function to read the second integer (k) from the standard input stream

x = n // k
# Calculate the integer division of n by k and assign the result to the variable x

y = n % k
# Calculate the remainder of n divided by k and assign the result to the variable y

if y!= 0:
	z = x + 1 - x
	# If the remainder y is non-zero, assign the value 1 to the variable z
else:
	z = x - x
	# If the remainder y is zero, assign the value 0 to the variable z

print(z)
# Use the print() function to print the value of z to the standard output stream

