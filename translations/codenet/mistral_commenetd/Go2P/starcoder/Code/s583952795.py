# Python 3

# <START-OF-CODE>

# Function to convert a number to its base-10 string representation
# with digit count K
def TenToN(number, n):
	s = ""
	tmp = number # Initialize temporary variable

	# Repeat the following process until the number becomes less than N
	while True:
		# Append the remainder of the division by N to the result string
		s = str(tmp%n) + s

		# If the number is less than N, break the loop
		if tmp < n:
			break

		# Divide the number by N
		tmp //= n

	# Return the result string
	return s

# Helper functions

# Write a string to the output writer
def write(s):
	print(s, end="")

# Print the content of the output writer
def print():
	print("")

# Read a line from the input scanner
def readLine():
	return input()

# Read an integer from the input scanner
def readInt():
	return int(input())

# Read a float from the input scanner
def readFloat():
	return float(input())

# Read runes from the input scanner
def readRunes():
	return list(input())

# Read a string from the input scanner
def readString():
	return input()

# Read multiple strings from the input scanner
def readStrings():
	return input().split()

# Convert an integer to its string representation
def s2i(s):
	return int(s)

# Convert a string to an integer
def i2s(i):
	return str(i)

# Sum all integers in an integer slice
def sum(i):
	return sum(i)

# Split a string by a delimiter
def split(s):
	return s.split()

# Convert a string array to an integer array
def strAry2intAry(strs):
	return [int(s) for s in strs]

# Convert an integer array to a string array
def intAry2strAry(nums):
	return [str(n) for n in nums]

# Join multiple strings into a single string with a delimiter
def ary2str(strs):
	return " ".join(strs)

# Reverse the order of elements in an integer slice
def reverse(res):
	return res[::-1]

# Initialize an integer slice with a given value
def initalize(res, init):
	if len(res) == 0:
		return
	res[0] = init
	for i in range(len(res)):
		res[i:] = res[:i]

# Unused function, remove it
# def regexpExample():
# 	# Your code here!
# 	str = "13:20"
# 	r = re.compile(r"(\d+):(\d+)")
# 	print(r.findall(str))

# 