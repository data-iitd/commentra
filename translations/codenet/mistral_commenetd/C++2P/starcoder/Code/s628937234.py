
# Include necessary libraries

s = input() # Read a string from the standard input and store it in the variable s

# The following block of code creates a new string t from the string s
t = s[0]
t += str(len(s)-2)
t += s[len(s)-1]

# Extract the first character from string s and store it in variable t
# Convert the size of string s minus 2 to a string using to_string function
# Concatenate the extracted first character, the size minus 2 as a string, and the last character of string s to create the new string t

print(t) # Output the newly created string t to the standard output

# 