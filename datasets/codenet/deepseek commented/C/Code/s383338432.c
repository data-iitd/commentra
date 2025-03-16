#include <stdio.h>  // Include the standard input-output library for printf and scanf

int main() {
  int height, width, i;  // Declare integer variables for height, width, and loop index
  scanf("%d %d", &height, &width);  // Read the height and width from the user input
  char input_str[width+1];  // Declare a character array to store the input string

  // Print the top border of the output
  for(i = 0; i < width + 2; i++) {
    printf("#");
  }
  printf("\n");

  // Read and print each line of input with borders
  for(i = 0; i < height; i++) {
    scanf("%s", input_str);  // Read a string from the user
    printf("#%s#\n", input_str);  // Print the string with borders
  }

  // Print the bottom border of the output
  for(i = 0; i < width + 2; i++) {
    printf("#");
  }
  printf("\n");

  return 0;  // Return 0 to indicate successful program termination
}
