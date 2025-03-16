
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // Initialize scanner to read input from standard input
  int N, K;
  scanf("%d %d", &N, &K);

  // Read the string S from the standard input
  char S[N + 1];
  scanf("%s", S);

  // Initialize a boolean variable firstTime to true
  int firstTime = 1;

  // Initialize an integer variable step to 1
  int step = 1;

  // Perform the main logic while K is greater than zero
  while (K > 0) {
    // Create a new string T to store the reversed version of S
    char T[N + 1];
    strcpy(T, S);
    int i;
    for (i = 0; i < N; i++) {
      T[i] = S[N - i - 1];
    }
    T[i] = '\0';

    // Create a new string revU to store the concatenation of S and T reversed
    char revU[2 * N + 1];
    strcpy(revU, S);
    strcat(revU, T);
    int j;
    for (j = 0; j < 2 * N; j++) {
      revU[j] = revU[2 * N - j - 1];
    }
    revU[j] = '\0';

    // Create a string variable sDash to store the current substring of revU
    char sDash[N + 1];
    strcpy(sDash, S);

    // Iterate through the substrings of revU starting from the end of S
    for (int i = N; i >= 0; i -= step) {
      // Get the substring of revU starting from the current index i and of length N
      char tmp[N + 1];
      strcpy(tmp, revU + i);

      // Compare the current substring tmp with the current substring sDash
      if (strcmp(sDash, tmp) > 0) {
        // Update the current substring sDash with the new substring tmp
        strcpy(sDash, tmp);
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
          printf("%c", sDash[0]);
        }
        printf("\n");
        exit(0);
      }
    } else {
      // Update the value of step
      step += step;
    }

    // Decrement the value of K
    K--;

    // Update the value of S to be the current substring sDash reversed
    strcpy(S, sDash);
    int k;
    for (k = 0; k < N; k++) {
      S[k] = sDash[N - k - 1];
    }
    S[k] = '\0';
  }

  // Print the reversed version of the final string S
  printf("%s\n", S);

  return 0;
}

