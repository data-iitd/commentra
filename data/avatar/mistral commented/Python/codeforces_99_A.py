# Get the input string from the user
l = input()

# Split the input string using '.' as delimiter and store the list in 'l'
l = l.split('.')

# Extract the first and second parts of the list and store them in 's' and 'p' respectively
s = list(l[0])
p = list(l[1])

# Get the last character of the string 's' and store it in a variable 'last_char'
last_char = s[len(s) - 1]

# Check if the last character of the string 's' is '9'
if last_char == '9':
    # If yes, print the message "GOTO Vasilisa."
    print("GOTO Vasilisa.")

# Else, if the last character is not '9' and the integer value of the first part of 'p' is less than 5
elif last_char != '9' and int(p[0]) < 5:
    # Concatenate all the characters of 's' to form a string
    s = ''.join(s)
    # Print the string 's'
    print(s)

# Else, if the last character is not '9' and the integer value of the first part of 'p' is greater than or equal to 5
else:
    # Concatenate all the characters of 's' to form a string
    s = ''.join(s)
    # Increment the last character of the string 's' by 1
    s = str(int(s) + 1)
    # Print the updated string 's'
    print(s)
