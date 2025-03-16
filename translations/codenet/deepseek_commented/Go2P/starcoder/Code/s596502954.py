
# Importing the sys module for input operations
import sys

# Reading three integers and checking if their sum is greater than or equal to the third integer
if int(sys.stdin.readline())+int(sys.stdin.readline()) >= int(sys.stdin.readline()):
	print("Yes") # Printing "Yes" if the condition is true
else:
	print("No") # Printing "No" if the condition is false

