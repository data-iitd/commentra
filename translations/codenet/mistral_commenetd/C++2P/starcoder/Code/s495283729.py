
# Include necessary header files for standard input/output and string manipulation

s = input() # Read a string from the standard input and store it in the variable's'

flag = 0 # Initialize a boolean flag to 0

for i in range(len(s)): # Iterate through each character in the string's'
    if i % 2 == 0: # Check if the current index 'i' is even
        if s[i] == 'R' or s[i] == 'U' or s[i] == 'D': # Check if the character at the even index is 'R', 'U', or 'D'
            pass # Do nothing and move to the next character
        else: # If the character at the even index is not 'R', 'U', or 'D'
            flag = 1 # Set the flag to 1
            break # Break out of the loop
    else: # If the current index 'i' is odd
        if s[i] == 'L' or s[i] == 'U' or s[i] == 'D': # Check if the character at the odd index is 'L', 'U', or 'D'
            pass # Do nothing and move to the next character
        else: # If the character at the odd index is not 'L', 'U', or 'D'
            flag = 1 # Set the flag to 1
            break # Break out of the loop

if flag == 0: # If no invalid character was found during the iteration
    print("Yes") # Output "Yes" to the standard output
else: # If an invalid character was found during the iteration
    print("No") # Output "No" to the standard output

# 