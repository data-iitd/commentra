# Initialize a new scanner for reading input from standard input
import sys
import math

sc = sys.stdin

# NextLine reads a line of text from stdin and returns it as a string.
def NextLine():
	return sc.readline().strip()

# NextIntsLine reads a line of text consisting of integers separated by spaces from stdin.
# It then converts these strings to integers and returns them as a slice of integers.
def NextIntsLine():
	intsStr = NextLine() # Read the line of integers
	tmp = intsStr.split(" ") # Split the line into individual string components
	ints = []
	for s in tmp:
		i, _ = int(s), 1 # Convert each string to an integer
		ints.append(i) # Append the integer to the slice
	return ints

# NextStringsLine reads a line of text consisting of strings separated by spaces from stdin.
# It returns these strings as a slice.
def NextStringsLine():
	stringsStr = NextLine() # Read the line of strings
	tmp = stringsStr.split(" ") # Split the line into individual string components
	strs = []
	for s in tmp:
		strs.append(s) # Append each string to the slice
	return strs

# NextRunesLine reads a line of text consisting of characters arranged continuously from stdin.
# It returns these characters as a slice of runes.
def NextRunesLine():
	return list(NextLine()) # Convert the line to a slice of runes

# Max returns the maximum integer from a variable number of input integers.
# This function requires at least one argument, otherwise it will raise an exception.
def Max(integers):
	m = integers[0] # Initialize max with the first integer
	for i, integer in enumerate(integers):
		if i == 0:
			continue # Skip the first iteration
		if m < integer:
			m = integer # Update max if a larger integer is found
	return m # Return the maximum integer

# Min returns the minimum integer from a variable number of input integers.
# This function requires at least one argument, otherwise it will raise an exception.
def Min(integers):
	m = integers[0] # Initialize min with the first integer
	for i, integer in enumerate(integers):
		if i == 0:
			continue # Skip the first iteration
		if m > integer:
			m = integer # Update min if a smaller integer is found
	return m # Return the minimum integer

# PowInt calculates the power of an integer base raised to an integer exponent.
# It raises an exception if either argument is negative.
def PowInt(a, e):
	if a < 0 or e < 0:
		raise Exception("[argument error]: PowInt does not accept negative integers")
	fa = float(a) # Convert base to float
	fe = float(e) # Convert exponent to float
	fanswer = math.pow(fa, fe) # Calculate power
	return int(fanswer) # Return the result as an integer

# AbsInt returns the absolute value of an integer.
def AbsInt(a):
	fa = float(a) # Convert integer to float
	fanswer = math.fabs(fa) # Calculate absolute value
	return int(fanswer) # Return the result as an integer

# DeleteElement removes an element at a specified index from a slice of integers.
# It returns a new slice with the element removed.
def DeleteElement(s, i):
	if i < 0 or len(s) <= i:
		raise Exception("[index error]") # Raise an exception if the index is out of bounds
	# Create a new slice with one less element
	n = []
	n = n + s[:i] # Append elements before the index
	n = n + s[i+1:] # Append elements after the index
	return n # Return the new slice

# Concat concatenates two slices of runes and returns a new slice.
def Concat(s, t):
	n = []
	n = n + s # Append the first slice
	n = n + t # Append the second slice
	return n # Return the concatenated slice

# Main function where the program execution begins
x = NextIntsLine()[0] # Read a line of integers
i = 1 # Initialize counter
sum = 0 # Initialize sum
while True:
	sum += i # Incrementally add to sum
	if sum >= x: # Check if sum has reached or exceeded x
		break # Exit the loop if condition is met
	i += 1 # Increment counter
print(i) # Print the result

