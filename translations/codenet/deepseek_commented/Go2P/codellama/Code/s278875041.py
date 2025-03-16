
# Declare a string variable to hold user input
a = input()

# Replace all occurrences of "1" with "0" in the string `a`
tmp = a.replace("1", "0")

# Store the result of the first replacement in a temporary variable `tmp`
# Replace all occurrences of "9" with "1" in the string `tmp`
b = tmp.replace("9", "1")

# Store the result of the second replacement in the variable `b`
# Replace all occurrences of "0" with "9" in the string `b`
ans = b.replace("0", "9")

# Print the final result to the console
print(ans)

