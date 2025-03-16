
# Declare variables
n = 0
str = ""
com = ""
T = {} # A map to store strings as keys and boolean values

# Read the number of input pairs from the standard input
n = int(input())

# Iterate through each input pair
for i in range(n):
	# Read the command and the string from the standard input
	com, str = input().split()

	# If the command is 'i', add the string to the map with a value of true
	if com[0] == 'i':
		T[str] = True # Set the value of the string as a key in the map to true
	# If the command is not 'i', check if the string is present in the map and print the result accordingly
	else:
		if str in T: # Check if the string is present in the map
			print("yes") # If present, print 'yes'
		else:
			print("no") # If not present, print 'no'

# 