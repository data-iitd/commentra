#include <iostream>
using namespace std;

# Function to find the greatest common divisor (GCD) of two numbers using Euclid's algorithm
def Euclid(x, y):
	tmp = 0 # Variable to store the temporary value

	# Swap x and y if x is smaller than y
	if x < y:
		tmp = x
		x = y
		y = tmp

	# If x is divisible by y, return y as the GCD
	if not (x%y):
		return y

	# Recursively call Euclid function with y and the remainder of x divided by y
	return Euclid(y, x%y)

# Read input values of A and B from the standard input
A = int(input())
B = int(input())

# Calculate the product of A and B and print the result divided by their GCD
print((A*B) / Euclid(A, B))

