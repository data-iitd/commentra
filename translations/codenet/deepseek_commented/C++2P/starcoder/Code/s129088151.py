# Include the standard C library for input/output operations
# Include the map library for efficient key-value pair storage
# Include the string library for string manipulation
# Include the iostream library for input/output operations
from sys import stdin, stdout # Use the standard namespace to avoid prefixing standard library names with'std::'
from collections import defaultdict # Use the default dictionary to store the presence of strings

n = int(stdin.readline()) # Read the number of operations from the user
T = defaultdict(bool) # Declare a default dictionary to store the presence of strings

for i in range(n): # Loop through each operation
	com, str = stdin.readline().split() # Read the command and the string
	if com[0] == 'i': T[str] = True # If the command is 'i', insert the string into the map
	else: # If the command is not 'i'
		if T[str]: stdout.write("yes\n") # Check if the string is present in the map and print 'yes'
		else: stdout.write("no\n") # If the string is not present, print 'no'

# 