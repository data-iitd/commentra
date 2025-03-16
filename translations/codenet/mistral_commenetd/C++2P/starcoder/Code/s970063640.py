
# Declare and initialize variables
n = int(input()) # Number of elements in the array
a = int(input()) # Size of the subarray to be summed
sum = 0 # Initialize the sum variable to zero
s = [0]*n # Declare an array of size n to store the input elements

# Read the elements of the array from the user
for i in range(n):
	s[i] = int(input()) # Read the i-th element of the array

# Sort the array in ascending order
s.sort() # Sort the array using the sort function

# Calculate the sum of the last 'a' elements of the sorted array
for i in range(n-a,n):
	sum += s[i] # Add the current element to the sum

# Print the result
print(sum) # Print the sum of the last 'a' elements

