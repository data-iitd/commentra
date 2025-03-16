
# Declare an integer variable 'n' to store the number of elements in arrays 'a' and 'b'
n = int(input())

# Declare an integer array 'a' of size 100
a = [0] * 100

# Declare an integer array 'b' of size 100
b = [0] * 100

# Declare an integer variable'sum' and initialize it to zero
sum = 0

# Iterate through the array 'a' and read its elements from the standard input
for i in range(n):
	a[i] = int(input())

# Iterate through the array 'b' and read its elements from the standard input
for i in range(n):
	b[i] = int(input())

	if (a[i] - b[i] > 0): # Check if the difference between 'a[i]' and 'b[i]' is positive
		sum += a[i] - b[i] # If it is, add the difference to the variable'sum'

# Output the value of the variable'sum' to the standard output
print(sum)

