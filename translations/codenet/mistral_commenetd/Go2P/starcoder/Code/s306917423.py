# Importing the'sys' module for input/output operations
import sys

# Reading the input using'sys.stdin.readline()' function
s = sys.stdin.readline()

# Declaring a variable 'ans' to store the answer
ans = 0

# Looping through each character 'c' in the string's'
for c in s:
	# Checking if the current character 'c' is equal to '1'
	if c == '1':
		# Incrementing the answer if the character is '1'
		ans += 1

# Printing the answer
print(ans)

# End of the code
