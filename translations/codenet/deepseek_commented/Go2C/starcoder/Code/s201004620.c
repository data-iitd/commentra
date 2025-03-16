#include <stdio.h>
#include <stdlib.h>

int main() {
  // Declare a string variable S to store the weather input
  char S[100];
  
  // Read a string input from the user and store it in S
  scanf("%s", S);
  
  // Use a switch statement to determine the weather based on the input
  if(strcmp(S, "Sunny") == 0) {
    // If the input is "Sunny", print "Cloudy"
    printf("Cloudy");
  } else if(strcmp(S, "Cloudy") == 0) {
    // If the input is "Cloudy", print "Rainy"
    printf("Rainy");
  } else if(strcmp(S, "Rainy") == 0) {
    // If the input is "Rainy", print "Sunny"
    printf("Sunny");
  }
  
  return 0;
}
