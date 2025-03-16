# Importing bufio for buffered I/O
# Importing fmt for formatted I/O
# Importing os for operating system functionalities
# Importing string for string manipulation
# Importing sys for system functionalities
import sys
import os
import string
import bufio
import fmt

# Create a new scanner to read input from standard input
s = bufio.NewScanner(sys.stdin)

# Read the first line of input (not used)
s.Scan()
# Read the second line of input which contains space-separated integers
s.Scan()
ds = s.Text()

# Split the input string into a slice of strings
dd = ds.split(" ")
# Create a slice of integers to hold the converted values
dn = []

# Convert each string in the slice to an integer
for i, d in enumerate(dd):
	dn.append(int(d))

# Initialize a variable to hold the sum of products
sum = 0
# Calculate the sum of products of all unique pairs of integers
for i in range(len(dn)):
	for j in range(i + 1, len(dn)):
		sum += dn[i] * dn[j] # Multiply the pair and add to sum

# Output the final sum of products
print(sum)

# 