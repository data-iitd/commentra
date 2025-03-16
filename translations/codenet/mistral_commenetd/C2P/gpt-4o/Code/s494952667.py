# Import the necessary library for string manipulation
# (not needed in this case, but included for completeness)
import sys

# Declare a string variable
str_input = input("Enter a string: ")  # Prompt the user to enter a string

# Calculate the length of the string
length = len(str_input)  # Get the length of the input string

print("Reversed string: ", end="")  # Print a message to indicate that the reversed string will be printed

# Use a for loop to print each character of the string in reverse order
for i in range(length - 1, -1, -1):  # Loop from the last index to the first
    print(str_input[i], end="")  # Print the character at index 'i' without a newline

print()  # Print a newline character
# Indicate successful execution
# <END-OF-CODE>
