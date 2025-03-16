# Python 3.6.1
# <NAME>
# 02/01/2017

# Define a function to print the output to the console
def out(*args):
	print(*args)

# Define a function to read an integer from the input
def nextInt():
	return int(input())

# Define a function to read a string from the input
def nextString():
	return input()

# Define a type Data to represent a single data point
class Data:
	def __init__(self, x):
		self.X = x

# Define a type Datas as a slice of Data
class Datas(list):
	pass

# Define a function to sort the slice based on X field
def sortDatas(s):
	s.sort(key=lambda x: x.X)

# Main function starts here
if __name__ == "__main__":
	# Read number of data points N from the input
	N = nextInt()

	# Read number of queries L from the input
	L = nextInt()

	# Initialize a slice of Data type named s with capacity N
	s = Datas()

	# Read data points X from the input and store them in the slice s
	for i in range(N):
		s.append(Data(nextString()))

	# Print the number of data points N, number of queries L, and the slice s
	out(N, L, s)

	# Sort the slice s in ascending order based on X field
	sortDatas(s)

	# Initialize an empty string ans to store the concatenated X values
	ans = ""

	# Iterate through the slice s and concatenate X values to the string ans
	for i in range(N):
		ans = ans + s[i].X

	# Print the concatenated string ans to the console
	out(ans)

# 