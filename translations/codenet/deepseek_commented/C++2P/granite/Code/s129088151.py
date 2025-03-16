
n = int(input()) # Read the number of operations from the user
T = {} # Declare a dictionary to store the presence of strings
for i in range(n): # Loop through each operation
    com, str = input().split() # Read the command and the string
    if com == 'insert': T[str] = True # If the command is 'insert', insert the string into the dictionary
    else: # If the command is not 'insert'
        if str in T: print('yes') # Check if the string is present in the dictionary and print 'yes'
        else: print('no') # If the string is not present, print 'no'
