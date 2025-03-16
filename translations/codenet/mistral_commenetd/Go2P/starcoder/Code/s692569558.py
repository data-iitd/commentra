
# Import the sys module for reading input from the standard input
import sys

# Initialize a new scanner for reading from standard input
s = sys.stdin

# Read the first two lines from standard input and store them in the scanner
s.readline()
s.readline()

# Assign the text of the second line to the variable ds
ds = s.readline()

# Split the string ds into an array of strings dd using the split function
dd = ds.split(" ")

# Create a new slice dn of length len(dd) and initialize each element to 0 using the list comprehension
dn = [0 for i in range(len(dd))]

# Iterate through each element i in the slice dd and convert its string value to integer using the int function and store it in the corresponding index of slice dn
for i in range(len(dd)):
	dn[i] = int(dd[i])

# Initialize sum variable to 0
sum = 0

# Iterate through each index i in the slice dn
for i in range(len(dn)):
	# Iterate through each index j greater than i in the slice dn
	for j in range(i + 1, len(dn)):
		# Add the product of dn[i] and dn[j] to the sum variable
		sum += dn[i] * dn[j]

# Print the value of sum variable to the standard output using the print function
print(sum)

# End of code

