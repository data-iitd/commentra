# Step 1: Include the standard input/output library.
import sys

# Step 2: Define a function named'swap' that takes two integer pointers as arguments.
def swap(a, b):
	tmp = a  # Step 3: Inside the'swap' function, declare a temporary variable 'tmp'.
	a = b  # Step 4: Assign the value pointed to by 'a' to 'tmp'.
	b = tmp  # Step 5: Assign the value pointed to by 'b' to the memory location pointed to by 'a'.

# Step 7: In the'main' function, declare two integer variables 'a' and 'b'.
while(1):  # Step 8: Create an infinite loop using 'while(1)'.
	a = 0  # Step 9: Use'scanf' to read two integers from the user and store them in 'a' and 'b'.
	b = 0
	a, b = map(int, sys.stdin.readline().split())
	if a == 0 and b == 0: break  # Step 10: Check if both 'a' and 'b' are zero. If true, break the loop.
	if b < a: swap(a, b)  # Step 11: Check if 'b' is less than 'a'. If true, call the'swap' function to swap the values of 'a' and 'b'.
	print(a, b)  # Step 12: Print the values of 'a' and 'b'.

# Step 13: End the'main' function with'return 0'.
return 0

