# Import the math module for using mathematical functions like sqrt
import math

# Get the number of test cases N
N = int(input())

# Read the list XS of N integers from the standard input
XS = [int(i) for i in input().split()]

# Initialize the minimum value m with a large number
m = 9999999999

# Iterate through all possible values of i from 1 to 100
for i in range(1, 101):
	# Calculate the sum of squared differences between each number in XS and i
	c = sum([(x - i) ** 2 for x in XS])
	# If the current minimum value m is greater than the calculated sum, update m
	if m > c:
		m = c

# Print the minimum sum of squared differences
print(m)
