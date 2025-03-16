import sys

# Initialize a new scanner to read from standard input
sc = __import__('bufio').__new__(__import__('bufio').BufferedReader)
sc.__init__(sys.stdin)

# Function to read an integer from input
def ri():
	sc.readline() # Read the next line of input
	return int(sc.readline()) # Return the integer

# Function to calculate the average of a slice of float64 numbers
def ave(s):
	return sum(s) / len(s) # Return the average

# Function to calculate the absolute difference between two float64 numbers
def diff(a, b):
	if a > b:
		return a - b # Return the difference if a is greater than b
	return b - a # Return the difference if b is greater than or equal to a

n = ri() # Read the number of elements
a = [float(ri()) for i in range(n)] # Read the array of float64 numbers

# Calculate the average of the numbers
ave = ave(a)

# Initialize variables to track the minimum difference and the corresponding index
minDiff = 999999.9
ansIndex = -1
for i, v in enumerate(a): # Iterate over the slice to find the closest value to the average
	diff = diff(v, ave) # Calculate the difference between the current value and the average
	if diff < minDiff: # Check if the current difference is less than the minimum difference found so far
		minDiff = diff # Update the minimum difference
		ansIndex = i # Update the index of the closest value

# Print the index of the value closest to the average
print(ansIndex)

# 