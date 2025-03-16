# Read a line from the standard input
stdin = input()

# Assign the value of stdin to the variable s
s = stdin

# Initialize the variable result with "Yes" if "A" and "B" are present in s, otherwise initialize it with "No"
result = "Yes" if "A" in s and "B" in s else "No"

# Print the value of the variable result
print(result)
