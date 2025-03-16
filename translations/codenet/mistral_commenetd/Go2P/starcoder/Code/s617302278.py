# Importing required packages
import sys

# Initializing scanner
sc = sys.stdin

# Function to read a line text from stdin and return its string
def NextLine():
	# Reading a line text from stdin
	return sc.readline().strip()

# Function to read a line text, that consists of ONLY INTEGERS DELIMITED BY SPACES, from stdin
# And then returns integers slice
def NextIntsLine():
	# Reading a line text from stdin
	intsStr = NextLine()
	# Splitting the line text by space
	tmp = intsStr.split(" ")
	# Creating an empty integers slice
	ints = []
	# Converting each string to integer and appending it to the integers slice
	for s in tmp:
		# Converting string to integer
		i = int(s)
		# Appending integer to the integers slice
		ints.append(i)
	# Returning the integers slice
	return ints

# Function to read a line text, that consists of ONLY CHARACTERS ARRANGED CONTINUOUSLY, from stdin
# And then returns runes slice
def NextRunesLine():
	# Reading a line text from stdin
	return list(NextLine())

# Function to find the maximum integer among input integers
# This function needs at least 1 argument (no argument causes panic)
def Max(integers):
	# Initializing maximum integer as first integer
	m = integers[0]
	# Iterating through the input integers
	for i, integer in enumerate(integers):
		# If current integer is greater than maximum integer, update maximum integer
		if i == 0:
			continue
		if m < integer:
			m = integer
	# Returning the maximum integer
	return m

# Function to find the minimum integer among input integers
# This function needs at least 1 argument (no argument causes panic)
def Min(integers):
	# Initializing minimum integer as first integer
	m = integers[0]
	# Iterating through the input integers
	for i, integer in enumerate(integers):
		# If current integer is smaller than minimum integer, update minimum integer
		if i == 0:
			continue
		if m > integer:
			m = integer
	# Returning the minimum integer
	return m

# Function to calculate integer power
def PowInt(a, e):
	# Checking for negative integers
	if a < 0 or e < 0:
		raise Exception("[argument error]: PowInt does not accept negative integers")
	# Calculating the power using math.Pow
	fanswer = math.pow(a, e)
	# Converting the answer back to integer
	return int(fanswer)

# Function to calculate absolute value of an integer
def AbsInt(a):
	# Calculating the absolute value using math.Abs
	fanswer = math.fabs(a)
	# Converting the answer back to integer
	return int(fanswer)

# Function to delete an element from a slice
def DeleteElement(s, i):
	# Checking for negative index or empty slice
	if i < 0 or len(s) <= i:
		raise Exception("[index error]")
	# Creating a new slice with zero capacity
	n = []
	# Appending elements before the index to the new slice
	n = n + s[:i]
	# Appending elements after the index to the new slice
	n = n + s[i+1:]
	# Returning the new slice
	return n

# Function to concatenate two slices
def Concat(s, t):
	# Creating a new slice with zero capacity
	n = []
	# Appending elements of the first slice to the new slice
	n = n + s
	# Appending elements of the second slice to the new slice
	n = n + t
	# Returning the new slice
	return n

# Function to sort a slice using sort package
#sort.Sort(sort.IntSlice(s))
#sort.Sort(sort.Reverse(sort.IntSlice(s)))
#sort.Sort(sort.Float64Slice(s))
#sort.Sort(sort.StringSlice(s))

# Function to copy elements from one slice to another
#a = []int{0, 1, 2}
#b = make([]int, len(a))
#copy(b, a)

# Variable declaration and initialization
x = 0

# Main function
def main():
	# Reading integers from stdin as a line text
	tmp = NextIntsLine()
	# Assigning the first integer to variable x
	x = tmp[0]
	# Initializing sum variable as zero
	sum = 0
	# Initializing index variable as one
	i = 1
	# Looping until the sum is greater than or equal to x
	while True:
		# Adding current index to sum
		sum += i
		# Checking if sum is greater than or equal to x
		if sum >= x:
			# Breaking the loop
			break
		# Incrementing index
		i += 1
	# Printing the index
	print(i)

# Calling main function
if __name__ == "__main__":
	main()

