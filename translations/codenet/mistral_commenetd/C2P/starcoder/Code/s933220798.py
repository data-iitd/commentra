
# <START-OF-CODE>

# Declare and initialize a variable of type double named 'a'
a = 0

# Declare and initialize a variable of type double named 'ave' with an initial value of 0
ave = 0

# Declare and initialize an integer variable named 'i' with an initial value of 0
i = 0

# Start a for loop that iterates 5 times
for i in range(5):
	# Ask the user to enter a number
	a = float(input("Enter a number: "))

	# Check if the value of 'a' is less than or equal to 40
	if a <= 40:
		# If it is, add 40 to the variable 'ave'
		ave += 40
		# Print a message to the user
		print("Number %d is less than or equal to 40. Adding 40 to the average." % (i+1))
	# If the value of 'a' is greater than 40, add it directly to the variable 'ave'
	else:
		ave += a
		# Print a message to the user
		print("Number %d is greater than 40. Adding %lf to the average." % (i+1, a))

# Calculate the average of the 5 numbers by dividing the sum of the numbers (stored in the variable 'ave') by 5
ave /= 5.0

# Print the average value to the standard output using the print function
print("The average of the 5 numbers is: %.0f" % ave)

# 