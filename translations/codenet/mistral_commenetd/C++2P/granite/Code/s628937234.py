
s = input() # Read a string from the standard input and store it in the variable s

# The following block of code creates a new string t from the string s
t = s[0] + str(len(s) - 2) + s[-1]

print(t) # Output the newly created string t to the standard output
