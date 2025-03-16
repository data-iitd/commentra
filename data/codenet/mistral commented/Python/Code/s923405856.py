
# This is a while loop that runs indefinitely until a specific condition is met.
while True:
	# Take an integer input from the user and assign it to the variable 'n'.
	n = int(input())

	# If 'n' is equal to 0, then the loop breaks.
	if n == 0:
		break

	# Initialize two variables, 'res' and 's', with initial values -1111111111 and 0 respectively.
	res = -1111111111
	s = 0

	# Use a for loop to iterate through the range of 'n' integers.
	for i in range(n):
		# Take an integer input from the user and assign it to the variable 'a'.
		a = int(input())

		# Update the variable 's' by taking the maximum of the current value of 's' and the sum of 's' and 'a'.
		s = max(s + a, a)

		# Update the variable 'res' by taking the maximum of the current value of 'res' and the updated value of 's'.
		res = max(res, s)

	# After the for loop, we print the value of 'res'.
	print(res)