#include <stdio.h>

int main() {
  // Declare a variable to hold the weather condition input
  char S[10];
  
  // Read the weather condition from standard input
  scanf("%s", S);
  
  // Use a switch statement to determine the next weather condition based on the input
  switch (S[0]) {
  case 'S':
    // If the input starts with "S", print "Cloudy" as the next condition
    printf("Cloudy\n");
    break;
  case 'C':
    // If the input starts with "C", print "Rainy" as the next condition
    printf("Rainy\n");
    break;
  case 'R':
    // If the input starts with "R", print "Sunny" as the next condition
    printf("Sunny\n");
    break;
  }
  
  return 0;
}
