
# Include standard input/output library
from sys import stdin, stdout

# Include string manipulation library
from string import *

# Declare main function with no arguments and no return value
def main():
	# Declare two character arrays, str and tmp, with sizes 201 and 101 respectively
	str = [None] * 201
	tmp = [None] * 101

	# Declare another character array p with size 101
	p = [None] * 101

	# Declare two integer variables, slen and plen, to store the length of str and p respectively
	slen = 0
	plen = 0

	# Declare three integer variables, i, j, and flag
	i = 0
	j = 0
	flag = 0

	# Read two strings from the standard input and store them in str and p respectively
	stdin.readline().strip().split(" ", 1)[0]
	stdin.readline().strip().split(" ", 1)[0]

	# Copy the contents of str to tmp
	tmp = str[:]

	# Concatenate the contents of str and tmp, i.e., str now contains str concatenated with itself
	str = str + tmp

	# Get the length of str and store it in slen
	slen = len(str)

	# Get the length of p and store it in plen
	plen = len(p)

	# Initialize flag to 0
	flag = 0

	# Iterate through the string str from the beginning to the end - plen characters
	for i in range(0, slen - plen):
		# Compare the substring of str starting from index i with length plen to p
		if str[i:i + plen] == p:
			# If the comparison is successful, set flag to 1
			flag = 1

	# If flag is 1, print "Yes" to the standard output
	if flag:
		stdout.write("Yes\n")
	# If flag is 0, print "No" to the standard output
	else:
		stdout.write("No\n")

# Call the main function
if __name__ == "__main__":
	main()

