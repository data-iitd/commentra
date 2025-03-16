#include <stdio.h>

int main() {
  # Declare variables for height and width of the input, and a loop counter
  height, width, i = 0, 0, 0

  # Read the height and width from user input
  scanf("%d %d", &height, &width)

  # Declare a character array to hold the input strings, with an extra space for the null terminator
  input_str = [0] * (width + 1)

  # Print the top border of the box, consisting of '#' characters
  for i in range(width + 2):
    print("#", end="")
  print()

  # Read each line of input and print it with '#' borders
  for i in range(height):
    # Read a string from user input
    scanf("%s", input_str)
    # Print the string with '#' on both sides
    print("#", end="")
    print(input_str, end="")
    print("#", end="")
    print()

  # Print the bottom border of the box, consisting of '#' characters
  for i in range(width + 2):
    print("#", end="")
  print()

  # Return 0 to indicate successful completion of the program
  return 0
}

