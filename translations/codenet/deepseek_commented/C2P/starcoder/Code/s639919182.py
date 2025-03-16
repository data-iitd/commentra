# Step 1: Include necessary headers
import sys

# Step 1: Define the main function
def main():
	v = [0] * 10 # Step 2: Declare an array of 10 integers
	sum = 0 # Step 2: Declare and initialize a variable to store the sum
	i = 0 # Step 2: Declare a loop variable
	
	for i in range(0, 10): # Step 3: Initialize a loop to read 10 integers from the user
		v[i] = int(input()) # Step 3: Read an integer and store it in the array
	
	for i in range(0, 10): # Step 4: Initialize a loop to calculate the sum of the integers
		sum += v[i] # Step 4: Add the current element to the sum
	
	print(sum) # Step 5: Print the sum of the integers
	
	return 0 # Step 6: Return 0 to indicate successful execution

# Step 7: Call the main function
if __name__ == "__main__":
	main()

