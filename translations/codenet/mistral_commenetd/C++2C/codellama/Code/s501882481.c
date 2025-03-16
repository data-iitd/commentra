
#include <stdio.h>
#include <string.h>

int main() {
  char S[100]; // Declare a string variable named S
  scanf("%s", S); // Get input for the string variable S

  if (strcmp(S, "Sunny") == 0) { // Check if the string is equal to "Sunny"
    printf("Cloudy\n"); // If true, print "Cloudy"
  } else if (strcmp(S, "Cloudy") == 0) { // Check if the string is equal to "Cloudy"
    printf("Rainy\n"); // If true, print "Rainy"
  } else { // If neither of the conditions are true
    printf("Sunny\n"); // Print "Sunny"
  }

  return 0; // Return 0 to indicate successful execution
}

