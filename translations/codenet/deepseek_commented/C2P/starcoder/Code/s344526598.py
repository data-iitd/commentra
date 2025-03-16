# Step 1: Include the standard input/output library.
import sys

# Step 2: Define the main function.
def main():
	i = 0 # Step 3: Declare integer variables i, j, and an array x with a size of 10000.
	x = [0] * 10000

	for i in range(10000): # Step 4: Initialize the array x with zeros.
		x[i] = 0

	i = 0 # Step 5: Initialize i to 0.
	x[i] = int(input()) # Step 6: Read an integer from the input and store it in x[0].
	
	while x[i]!= 0: # Step 7: Use a while loop to read integers into the array x until a zero is entered.
		i = i + 1
		x[i] = int(input())

	for j in range(i): # Step 8: Use a for loop to print the integers stored in the array x.
		print("Case %d: %d" % (j+1,x[j]))

# Step 9: Return 0 to indicate successful execution.
if __name__ == "__main__":
	main()

