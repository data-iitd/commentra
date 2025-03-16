
# Read a string from standard input
str = input()

# Calculate the length of the input string
len = len(str)

# Loop through the string in reverse order
for i in range(len - 1, -1, -1):
    # Output each character of the string in reverse
    print(str[i], end='')

# Print a newline character after the reversed string
print()

# 