
s = input("Please enter a string: ") # Ask user for input

if len(s) == 2: # Check if the length of the string is 2
    print(s) # If yes, print the string as it is
else:
    print(s[::-1]) # If no, print the reversed string