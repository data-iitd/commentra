# Python 3 program to find the number of days
# until the next Sunday

# Constants for days of the week
SUNDAY = 0
MONDAY = 1
TUESDAY = 2
WEDNESDAY = 3
THURSDAY = 4
FRIDAY = 5
SATURDAY = 6

# Array representing the days of the week
week = ["SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"]

# Function to read an integer from input
def getInt():
	return int(input())

# Function to read a string from input
def getString():
	return input()

# Function to compute the absolute value of an integer
def abs(a):
	if a < 0:
		return -a
	return a

# Function to compute p raised to the power of q
def pow(p, q):
	return p ** q

# Function to find the minimum value among given integers
def min(nums):
	res = nums[0]
	for i in range(1, len(nums)):
		res = min(res, nums[i])
	return res

# Function to find the maximum value among given integers
def max(nums):
	res = nums[0]
	for i in range(1, len(nums)):
		res = max(res, nums[i])
	return res

# Function to check if a string exists in a slice of strings
def strSearch(a, b):
	for i in range(len(a)):
		if a[i] == b:
			return True
	return False

# Function to print an array of integers
def printIntArray(array):
	print(array)

# Function to calculate the modulus of x with respect to the defined mod
def calcMod(x):
	return x % mod

# Function to find the number of days until the next Sunday
def getDays():
	# Get the input day as a string
	s = getString()
	index = -1 # Initialize index to -1 to indicate not found

	# Search for the input day in the week array
	for i in range(len(week)):
		if s == week[i]:
			index = i # Update index if the day is found
			break

	# Calculate and print the number of days until the next Sunday
	print(7 - index)

# Driver code
if __name__ == "__main__":
	getDays()

