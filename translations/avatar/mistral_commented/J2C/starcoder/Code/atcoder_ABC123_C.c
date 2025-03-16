
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

  // Reading the first long integer input N
  long N = atol(scanf("%ld", &N));

  // Initializing the minimum long integer variable with the first input value
  long min = 0;
  for (int i = 0; i < 5; i++) {
    if (i == 0) { // If it's the first iteration of the loop
      min = atol(scanf("%ld", &min)); // Set the minimum value to the current input value
    } else { // Otherwise
      min = fmin(min, atol(scanf("%ld", &min))); // Update the minimum value with the current input value if it's smaller
    }
  }

  // Printing the answer using the p method
  p((long)ceil((double)N/min)+4);
}

// Utility method to print a string as output
void p(char *ans) {
  printf("%s", ans);
}

// Utility method to print an integer as output
void p(int ans) {
  printf("%d", ans);
}

// Utility method to print nothing as output
void p() {
  printf("\n");
}

// Utility method to print a long integer as output
void p(long ans) {
  printf("%ld", ans);
}

// Utility method to print a double as output
void p(double ans) {
  printf("%lf", ans);
}

