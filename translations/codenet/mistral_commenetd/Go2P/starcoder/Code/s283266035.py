
# Declare a variable n of type int and initialize it to zero
n = 0
# Read an integer value from the standard input and store it in the variable n
n = int(input())
# Declare a variable ans of type int and initialize it to zero
ans = 0
# Use a for loop to iterate through all possible factors of n
for i in range(1, n):
	# Check if i is a factor of n
	if n % i == 0:
		# Check if i is the last factor of n
		if n % (n // i - 1) == i:
			# If both conditions are true, add the last factor to the answer
			ans += n // i - 1
# Print the answer to the standard output
print(ans)
# End of the code
