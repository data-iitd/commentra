
# Read the height and width from user input
height = int(input("Enter the height of the box: "))
width = int(input("Enter the width of the box: "))

# Print the top border of the box, consisting of '#' characters
print("#" * (width + 2))

# Read each line of input and print it with '#' borders
for i in range(height):
    # Read a string from user input
    input_str = input("Enter a string: ")
    # Print the string with '#' on both sides
    print("#" + input_str + "#")

# Print the bottom border of the box, consisting of '#' characters
print("#" * (width + 2))

# End of code
