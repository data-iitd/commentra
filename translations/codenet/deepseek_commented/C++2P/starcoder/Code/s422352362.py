# Include the C standard input/output library for scanf and printf functions.
# Include the map library for using the map container.
# Include the C string library for string manipulation functions.
# Include the C math library for mathematical functions.
# Include the iostream library for input and output operations.
# Include the algorithm library for using the STL algorithms.
# Include the queue library for using the queue container.
from sys import stdin, stdout # Include the standard input/output library for using standard input and output operations.
from collections import deque # Include the deque container from the collections library for using a double-ended queue.
from math import * # Include the math library for using mathematical functions.

a = [0] * 200005 # Declare an array to store the input values.
pre = [0] * 200005 # Declare an array to store the prefix sums.
last = [0] * 200005 # Declare an array to store the suffix sums.

def main(): # The main function where the execution of the program begins.
	n = int(stdin.readline()) # Read the value of n from the standard input.
	for i in range(1, n + 1): # Loop to read n integers into the array a.
		a[i] = int(stdin.readline()) # Read the i-th integer and store it in a[i].
	sumpre = 0 # Declare a variable to store the cumulative sum of prefix.
	sumlast = 0 # Declare a variable to store the cumulative sum of suffix.
	for i in range(1, n): # Loop to calculate the prefix sums.
		sumpre = sumpre + a[i] # Add the current element to the cumulative sum.
		pre[i] = sumpre # Store the cumulative sum in the pre array.
	for i in range(n, 0, -1): # Loop to calculate the suffix sums.
		sumlast = sumlast + a[i] # Add the current element to the cumulative sum.
		last[i] = sumlast # Store the cumulative sum in the last array.
	d = (1 << 60) # Declare a variable to store the minimum difference and initialize it to a large number.
	for i in range(1, n): # Loop to find the minimum absolute difference between prefix and suffix sums.
		d = min(d, abs(pre[i] - last[i + 1])) # Update the minimum difference if a smaller one is found.
	stdout.write(str(d) + '\n') # Print the minimum difference found.

if __name__ == "__main__": # Check if the program is executed as a script and not as an imported module.
	main() # Execute the main function.

