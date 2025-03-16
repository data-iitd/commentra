

n = int(input()) # Read the number of elements 'n' from the standard input
a = list(map(int, input().split())) # Read the elements of the array 'a' from the standard input and convert them to integers
b = list(map(int, input().split())) # Read the elements of the array 'b' from the standard input and convert them to integers
sum = 0 # Initialize the variable'sum' to zero

for i in range(n): # Iterate through the array 'a' and read its elements from the standard input
	if a[i] - b[i] > 0: # Check if the difference between 'a[i]' and 'b[i]' is positive
		sum += a[i] - b[i] # If it is, add the difference to the variable'sum'

print(sum) # Output the value of the variable'sum' to the standard output
