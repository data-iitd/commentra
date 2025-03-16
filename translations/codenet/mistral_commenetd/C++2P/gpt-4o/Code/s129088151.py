# Import necessary modules
import sys

# Declare variables
n = int(input())  # Read the number of input pairs
T = {}  # A dictionary to store strings as keys and boolean values

# Iterate through each input pair
for _ in range(n):
    com, str_input = input().split()  # Read the command and the string

    # If the command is 'i', add the string to the dictionary with a value of True
    if com[0] == 'i':
        T[str_input] = True  # Set the value of the string as a key in the dictionary to True
    # If the command is not 'i', check if the string is present in the dictionary and print the result accordingly
    else:
        if str_input in T:  # Check if the string is present in the dictionary
            print("yes")  # If present, print 'yes'
        else:
            print("no")  # If not present, print 'no'

# <END-OF-CODE>
