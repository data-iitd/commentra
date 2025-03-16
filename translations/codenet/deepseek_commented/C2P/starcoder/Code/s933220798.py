# <START-OF-CODE>

# Declare a variable to store the input value
a = 0
# Initialize a variable to store the sum of values
ave = 0
# Declare a counter variable for the loop
i = 0

# Loop to read 5 values from the user
while i < 5:
	a = float(input()) # Read a double value from the user and store it in 'a'
	if a <= 40: # Check if the value of 'a' is less than or equal to 40
		ave += 40 # Add 40 to 'ave' if the condition is true
	else:
		ave += a # Add the value of 'a' to 'ave' if the condition is false
	i += 1

ave /= 5.0 # Calculate the average of the values added to 'ave' and divide by 5.0

print(int(ave)) # Print the average value rounded to the nearest integer

# 