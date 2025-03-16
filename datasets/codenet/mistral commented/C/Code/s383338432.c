#include <stdio.h>

// Function main is the entry point of the program
int main() {
  // Declare variables for height and width of the rectangle to be printed
  int height, width;
  // Declare a character array to store the input string
  char input_str[width+1];
  // Initialize a counter variable 'i'
  int i;

  // Read the height and width of the rectangle from the user
  scanf("%d %d", &height, &width);

  // Print the top border of the rectangle
  for(i = 0; i < width + 2; i++) {
    // Print '#' character for each iteration
    printf("#");
  }
  printf("\n"); // Print newline character after the top border

  // Print the body of the rectangle
  for(i = 0; i < height; i++) {
    // Read a string from the user
    scanf("%s", input_str);
    // Print the top and bottom border of each row with '#' character
    printf("#%s#\n", input_str);
  }

  // Print the bottom border of the rectangle
  for(i = 0; i < width + 2; i++) {
    // Print '#' character for each iteration
    printf("#");
  }
  printf("\n"); // Print newline character after the bottom border

  // Return 0 to indicate successful execution of the program
  return 0;
}
