import sys

# Reading a string input and converting it to a character array
n = list(sys.stdin.readline().strip())

# Initializing a boolean variable to track the state of the previous character
s = False

# Iterating through each character in the character array
for i in range(len(n)):
    # Checking if the current character is a dot '.'
    if n[i] == '.':
        # If the previous character was also a dot, print 1 and reset the state
        if s:
            print(1, end="")
            s = False # Resetting the state
        else:
            # If the previous character was not a dot, print 0
            print(0, end="")
    else:
        # If the current character is not a dot
        if s:
            # If the previous character was also not a dot, print 2 and reset the state
            print(2, end="")
            s = False # Resetting the state
        else:
            # If the previous character was a dot, set the state to true
            s = True

# Closing the Scanner object to prevent resource leaks
sys.stdin.close()

