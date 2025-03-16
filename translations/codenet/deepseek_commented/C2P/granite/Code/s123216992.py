
# Step 1: Import the'sys' module to access the standard input/output.
import sys

# Step 2: Define a function named'swap' that takes two integer references as arguments.
def swap(a, b):
	tmp = a  # Step 3: Inside the'swap' function, declare a temporary variable 'tmp'.
	a = b  # Step 4: Assign the value of 'b' to 'a'.
	b = tmp  # Step 5: Assign the value of 'tmp' to 'b'.

# Step 6: Read two integers from the user and store them in 'a' and 'b'.
a, b = map(int, sys.stdin.readline().split())

# Step 7: Create an infinite loop using 'while True'.
while True:
	# Step 8: Check if both 'a' and 'b' are zero. If true, break the loop.
	if a == 0 and b == 0: break
	# Step 9: Check if 'b' is less than 'a'. If true, call the'swap' function to swap the values of 'a' and 'b'.
	if b < a: swap(a, b)
	# Step 10: Print the values of 'a' and 'b'.
	print(a, b)
	# Step 11: Read two integers from the user and store them in 'a' and 'b'.
	a, b = map(int, sys.stdin.readline().split())

# Step 12: End the program with'sys.exit(0)'.
sys.exit(0)

