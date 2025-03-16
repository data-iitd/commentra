

#include <stdio.h>
#include <string.h>

int main() {
  // Initialize variables N, K, and S
  int N, K;
  char S[100001];

  // Read the first integer N from the standard input
  scanf("%d", &N);

  // Read the second integer K from the standard input
  scanf("%d", &K);

  // Read the string S from the standard input
  scanf("%s", S);

  // Initialize a boolean variable firstTime to true
  int firstTime = 1;

  // Initialize an integer variable step to 1
  int step = 1;

  // Perform the main logic while K is greater than zero
  while (K > 0) {
    // Create a new string T to store the reversed version of S
    char T[100001];
    strcpy(T, S);
    strrev(T);

    // Create a new string revU to store the concatenation of S and T reversed
    char revU[200001];
    strcpy(revU, S);
    strcat(revU, T);
    strrev(revU);

    // Create a string variable sDash to store the current substring of revU
    char sDash[100001];
    strcpy(sDash, S);

    // Iterate through the substrings of revU starting from the end of S
    for (int i = N; i >= 0; i -= step) {
      // Get the substring of revU starting from the current index i and of length N
      strncpy(sDash, revU + i, N);
      sDash[N] = '\0';

      // Compare the current substring sDash with the current substring S
      if (strcmp(sDash, S) > 0) {
        // Update the current substring sDash with the new substring tmp
        strcpy(S, sDash);
      } else {
        // If this is not the first iteration, break the loop
        if (firstTime == 0) {
          break;
        }
      }
    }

    // Perform some actions based on the comparison of sDash and S
    if (firstTime == 1) {
      firstTime = 0;
      // Check if the length of S raised to the power of K is greater than N
      if (pow(2, K) > N) {
        // Print the first character of S N times and exit the program
        for (int i = 0; i < N; i++) {
          printf("%c", S[0]);
        }
        printf("\n");
        return 0;
      }
    } else {
      // Update the value of step
      step += step;
    }

    // Decrement the value of K
    K--;

    // Update the value of S to be the current substring sDash reversed
    strcpy(S, sDash);
    strrev(S);
  }

  // Print the reversed version of the final string S
  printf("%s\n", S);

  // End of code
  return 0;
}

