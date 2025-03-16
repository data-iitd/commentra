# Read input from the standard input (user input)
stdin = input()

# Store the input string in a variable 's'
s = stdin

# Check if both 'A' and 'B' are present in the input string
# If both are found, set result to "Yes", otherwise set it to "No"
result = "Yes" if "A" in s and "B" in s else "No"

# Print the result indicating whether both 'A' and 'B' were found
print(result)
