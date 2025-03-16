#include <stdio.h>

# Function main is the entry point of the program
def main():
  # Declare variables for height and width of the rectangle to be printed
  height, width = 0, 0
  # Declare a character array to store the input string
  input_str = ""
  # Initialize a counter variable 'i'
  i = 0

  # Read the height and width of the rectangle from the user
  scanf("%d %d", &height, &width)

  # Print the top border of the rectangle
  for i in range(width + 2):
    # Print '#' character for each iteration
    printf("#")
  printf("\n") # Print newline character after the top border

  # Print the body of the rectangle
  for i in range(height):
    # Read a string from the user
    scanf("%s", input_str)
    # Print the top and bottom border of each row with '#' character
    printf("#%s#\n", input_str)

  # Print the bottom border of the rectangle
  for i in range(width + 2):
    # Print '#' character for each iteration
    printf("#")
  printf("\n") # Print newline character after the bottom border

  # Return 0 to indicate successful execution of the program
  return 0

