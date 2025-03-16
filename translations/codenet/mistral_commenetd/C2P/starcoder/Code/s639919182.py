
# Declare an integer array 'v' of size 10 and an integer variable'sum' to store the sum of array elements.
v=[0]*10	# Declare an integer array 'v' of size 10.
sum=0		# Declare an integer variable'sum' and initialize it to zero.
i=0		# Declare an integer variable 'i' to use as a counter in for loops.

# Read 10 integers from the user and store them in the array 'v'.
for i in range(10):
	v[i]=int(input("Enter the value for index %d: "%i))
	# Read an integer value from the user and store it in the current index of the array 'v'.

# Calculate the sum of all elements in the array 'v'.
for i in range(10):
	sum+=v[i]
	# Add the value of the current element in the array 'v' to the variable'sum'.

# Print the sum of all elements in the array 'v'.
print(sum)
# Display the sum of all elements in the array 'v'.

