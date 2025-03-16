# Python code to find the maximum number of consecutive 'I's in a string

# Importing the'sys' module for input/output operations
import sys

# Taking input from the user
n = int(input())
s = input()

# Variable declaration and initialization for maximum count and current count
max = 0
cnt = 0

# Iterating through each character in the string's'
for i in s:
	# Checking if the character is 'I'
	if i == 'I':
		# Incrementing the current count
		cnt += 1
	else:
		# Decrementing the current count
		cnt -= 1

	# Updating the maximum count if the current count is greater
	if cnt > max:
		max = cnt

# Printing the maximum count
print(max)

# 