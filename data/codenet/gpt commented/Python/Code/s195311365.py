# Get user input and store it in variable 's'
s = input()

# Check if the length of the input string is exactly 2 characters
if len(s) == 2:
    # If the length is 2, print the string as it is
    print(s)
else:
    # If the length is not 2, print the string in reverse order
    print(s[::-1])
