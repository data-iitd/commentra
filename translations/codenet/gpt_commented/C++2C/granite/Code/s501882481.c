
#include <stdio.h>
#include <string.h>

int main() {
  char S[10]; // Variable to store the input weather condition
  scanf("%s", S); // Read the weather condition from standard input

  // Determine the next weather condition based on the current one
  if (strcmp(S, "Sunny") == 0) {
    printf("Cloudy\n"); // If it's sunny, print "Cloudy"
  } else if (strcmp(S, "Cloudy") == 0) {
    printf("Rainy\n"); // If it's cloudy, print "Rainy"
  } else {
    printf("Sunny\n"); // If it's neither, it must be rainy, print "Sunny"
  }

  return 0; // Return 0 to indicate successful execution
}
