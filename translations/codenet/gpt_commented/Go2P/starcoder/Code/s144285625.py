import sys

# Create a new scanner to read input from standard input
sc = bufio.NewScanner(sys.stdin)

# Set the scanner to split input by whitespace
sc.split(bufio.ScanWords)

# Read the number of groups of three integers
n = int(input())

# Initialize a slice to hold 3*n integers
ar = [0] * (3*n)

# Populate the slice with integers from input
for i in range(0, 3*n):
	ar[i] = int(input())

# Sort the slice of integers in ascending order
ar.sort()

# Initialize a variable to hold the sum of selected integers
sum = 0

# Calculate the sum of the second largest integer from each group of three
for i in range(0, n):
	sum += ar[3*n-(i+1)*2] # Select the second largest integer from the sorted slice

# Print the final computed sum
print(sum)

# 