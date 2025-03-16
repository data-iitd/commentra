# Declare a character array to hold the input string (maximum length 20)
str_input = input()[:20]  # Read a string from standard input, limiting to 20 characters

# Calculate the length of the input string
len_input = len(str_input)

# Loop through the string in reverse order and print each character
for i in range(len_input - 1, -1, -1):
    print(str_input[i], end='')  # Output each character of the string in reverse

# Print a newline character after the reversed string
print()

# End of the program
# Return 0 to indicate successful completion of the program (not needed in Python)
# <END-OF-CODE>
