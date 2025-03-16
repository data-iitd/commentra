
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Creating a Scanner object to read input from the standard input stream
// Importing the Scanner class from the java.util package
// Importing the Random class from the java.util package
// Importing the Scanner class from the java.util package

// Main method where the execution of the program starts
int main(int argc, char *argv[]) {

  // Reading the first long integer input N
  long N = 0;
  scanf("%ld", &N);

  // Initializing the minimum long integer variable with the first input value
  long min = 0;
  for (int i = 0; i < 5; i++) {
    if (i == 0) { // If it's the first iteration of the loop
      scanf("%ld", &min); // Set the minimum value to the current input value
    } else { // Otherwise
      long temp = 0;
      scanf("%ld", &temp); // Update the minimum value with the current input value if it's smaller
      min = (temp < min) ? temp : min;
    }
  }

  // Printing the answer using the p method
  printf("%ld\n", (long)ceil((double)N/min)+4);

  return 0;
}

// Utility method to print a string as output
void p(char *ans) {
  printf("%s\n", ans);
}

// Utility method to print an integer as output
void p(int ans) {
  printf("%d\n", ans);
}

// Utility method to print nothing as output
void p() {
  printf("\n");
}

// Utility method to print a long integer as output
void p(long ans) {
  printf("%ld\n", ans);
}

// Utility method to print a double as output
void p(double ans) {
  printf("%lf\n", ans);
}

// END-OF-CODE
