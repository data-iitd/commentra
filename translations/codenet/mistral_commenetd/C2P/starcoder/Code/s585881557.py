# Include the standard input/output library
import sys

# The entry point of the program
if __name__ == "__main__":
	h, r = map(int, sys.stdin.readline().split()) # Read two integers from the standard input and store them in variables h and r
	if r > -h: # Check if r is greater than the negative value of h
		print("1") # If the condition is true, print the number 1
	elif r == -h: # Check if r is equal to the negative value of h
		print("0") # If the condition is true, print the number 0
	else: # If the previous conditions are false
		print("-1") # Print the number -1

# 