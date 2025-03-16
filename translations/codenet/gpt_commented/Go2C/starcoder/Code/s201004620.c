


#include <stdio.h>
#include <stdlib.h>

int main() {
  // Declare a variable to hold the weather condition input
  char S[100];
  
  // Read the weather condition from standard input
  scanf("%s", S);
  
  // Use a switch statement to determine the next weather condition based on the input
  switch (S) {
  case "Sunny":
    // If the input is "Sunny", print "Cloudy" as the next condition
    printf("Cloudy");
    break;
  case "Cloudy":
    // If the input is "Cloudy", print "Rainy" as the next condition
    printf("Rainy");
    break;
  case "Rainy":
    // If the input is "Rainy", print "Sunny" as the next condition
    printf("Sunny");
    break;
  }
  
  return 0;
}

