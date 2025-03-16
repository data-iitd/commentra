# Read a string input from the user
s = input()

# Construct the abbreviated version of the string
t = s[0]  # Start with the first character of the input string
t += str(len(s) - 2)  # Append the number of characters between the first and last characters
t += s[-1]  # Append the last character of the input string

# Output the abbreviated string
print(t)  # Print the result

# <END-OF-CODE>
