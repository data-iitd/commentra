# Read input from the user
l = input()

# Split the input string into two parts using '.' as the delimiter
l = l.split('.')

# Convert the first part of the input into a list of characters
s = list(l[0])

# Convert the second part of the input into a list of characters
p = list(l[1])

# Extract the first character from the second part and convert it to an integer
i = int(p[0])

# Check if the last character of the first part is '9'
if s[len(s) - 1] == '9':
    # If it is '9', print the message "GOTO Vasilisa."
    print("GOTO Vasilisa.")
# Check if the last character is not '9' and the integer i is less than 5
elif s[len(s) - 1] != '9' and i < 5:
    # If both conditions are true, join the list of characters into a string and print it
    s = "".join(s)
    print(s)
else:
    # If the last character is not '9' and i is 5 or more
    # Join the list of characters into a string, convert it to an integer, increment it by 1, and convert it back to a string
    s = "".join(s)
    s = str(int(s) + 1)
    # Print the incremented value
    print(s)
