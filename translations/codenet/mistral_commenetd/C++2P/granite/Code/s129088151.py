

# Read the number of input pairs from the standard input
n = int(input())

# Declare a dictionary to store strings as keys and boolean values
T = {}

# Iterate through each input pair
for i in range(n):
	# Read the command and the string from the standard input
	com, str = input().split()

	# If the command is 'i', add the string to the dictionary with a value of True
	if com == 'i':
		T[str] = True # Set the value of the string as a key in the dictionary to True
	# If the command is not 'i', check if the string is present in the dictionary and print the result accordingly
	else:
		if str in T: # Check if the string is present in the dictionary
			print("yes") # If present, print 'yes'
		else:
			print("no") # If not present, print 'no'

# Translate the above Python code to Java and end with comment "