
# Read the height and width of the rectangle from the user
height = int(input("Enter the height of the rectangle: "))
width = int(input("Enter the width of the rectangle: "))

# Print the top border of the rectangle
print("#" * (width + 2))

# Print the body of the rectangle
for i in range(height):
  # Read a string from the user
  input_str = input("Enter a string for row {}: ".format(i + 1))
  # Print the top and bottom border of each row with '#' character
  print("#" + input_str + "#")

# Print the bottom border of the rectangle
print("#" * (width + 2))

# End of code
