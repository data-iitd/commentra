

#include <stdio.h>
#include <string.h>

int main() {
  char S[100]; // Declare a character array variable named S with a maximum length of 100
  scanf("%s", S); // Get input for the character array variable S

  if (strcmp(S, "Sunny") == 0) { // Check if the string is equal to "Sunny"
    printf("Cloudy\n"); // If true, print "Cloudy"
  } else if (strcmp(S, "Cloudy") == 0) { // Check if the string is equal to "Cloudy"
    printf("Rainy\n"); // If true, print "Rainy"
  } else { // If neither of the conditions are true
    printf("Sunny\n"); // Print "Sunny"
  }

  return 0; // Return 0 to indicate successful execution
}

