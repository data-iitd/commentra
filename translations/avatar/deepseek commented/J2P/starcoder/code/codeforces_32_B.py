import sys; # Import the sys module to read input from the user

n = sys.stdin.readline().strip() # Read the input string and strip the newline character
s = False # Initialize a boolean variable to keep track of the state

# Process each character in the string
for c in n:
    if c == '.': # Check if the current character is a dot
        if s: # If the state is true
            print(1) # Print '1' and reset the state to false
            s = False
        else: # If the state is false
            print(0) # Print '0' and set the state to false
            s = False
    else: # If the current character is not a dot
        if s: # If the state is true
            print(2) # Print '2' and reset the state to false
            s = False
        else: # If the state is false
            s = True # Set the state to true

# 