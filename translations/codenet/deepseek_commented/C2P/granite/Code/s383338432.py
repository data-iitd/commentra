
#include <stdio.h>  // Include the standard input-output library for printf and scanf

int main() {
  int height, width, i;  // Declare integer variables for height, width, and loop index
  scanf("%d %d", &height, &width);  // Read the height and width from the user input
  char input_str[width+1];  // Declare a character array to store the input string

  # Print the top border of the output
  for i in range(width + 2):
    print("#", end="")
  print("\n")

  # Read and print each line of input with borders
  for i in range(height):
    scanf("%s", input_str);  # Read a string from the user
    print("#" + input_str + "#\n", end="")

  # Print the bottom border of the output
  for i in range(width + 2):
    print("#", end="")
  print("\n")

  return 0;  # Return 0 to indicate successful program termination
}


