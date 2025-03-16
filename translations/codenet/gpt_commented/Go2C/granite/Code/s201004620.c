
#include <stdio.h>

int main() {
  // Declare a variable to hold the weather condition input
  char S[10];
  
  // Read the weather condition from standard input
  scanf("%s", S);
  
  // Use a switch statement to determine the next weather condition based on the input
  switch (S) {
  case "Sunny":
    // If the input is "Sunny", print "Cloudy" as the next condition
    printf("Cloudy\n");
    break;
  case "Cloudy":
    // If the input is "Cloudy", print "Rainy" as the next condition
    printf("Rainy\n");
    break;
  case "Rainy":
    // If the input is "Rainy", print "Sunny" as the next condition
    printf("Sunny\n");
    break;
  }
  
  // End the program
  return 0;
}
