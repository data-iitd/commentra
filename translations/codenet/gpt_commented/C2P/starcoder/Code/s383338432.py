# <START-OF-CODE>

# Declare variables for height and width of the input, and a loop counter
height = 0
width = 0
i = 0

# Read the height and width from user input
height = int(input())
width = int(input())

# Declare a character array to hold the input strings, with an extra space for the null terminator
input_str = [''for i in range(width + 1)]

# Print the top border of the box, consisting of '#' characters
for i in range(width + 2):
    print("#", end='')
print()

# Read each line of input and print it with '#' borders
for i in range(height):
    # Read a string from user input
    input_str = input()
    # Print the string with '#' on both sides
    print("#" + input_str + "#")

# Print the bottom border of the box, consisting of '#' characters
for i in range(width + 2):
    print("#", end='')
print()

# 