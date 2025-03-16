#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    // Read the integer N (length of the string) and K (number of operations)
    int N, K;
    scanf("%d %d", &N, &K);
    
    // Read the initial string
    char *S = (char *)malloc((N + 1) * sizeof(char));
    scanf("%s", S);
    
    // Flag to check if we are processing the first iteration
    int firstTime = 1;
    // Variable to control the step size for substring extraction
    int step = 1;
    
    // Loop until K operations are performed
    while (K > 0) {
        // Create a reversed copy of the current string S
        char *T = (char *)malloc((N + 1) * sizeof(char));
        for (int i = 0; i < N; i++) {
            T[i] = S[N - 1 - i];
        }
        T[N] = '\0';
        
        // Create a new string that combines S and its reverse, then reverse it
        char *revU = (char *)malloc((2 * N + 1) * sizeof(char));
        strcpy(revU, S);
        strcat(revU, T);
        
        // Reverse revU
        for (int i = 0; i < 2 * N / 2; i++) {
            char temp = revU[i];
            revU[i] = revU[2 * N - 1 - i];
            revU[2 * N - 1 - i] = temp;
        }
        
        // Initialize a variable to keep track of the best string found so far
        char *sDash = (char *)malloc((N + 1) * sizeof(char));
        strcpy(sDash, S);
        
        // Iterate through the string revU to find the lexicographically smallest substring
        for (int i = N; i >= 0; i -= step) {
            // Extract a substring from revU
            char tmp[N + 1];
            strncpy(tmp, revU + i, N);
            tmp[N] = '\0';
            
            // Compare and update sDash if a smaller substring is found
            if (strcmp(sDash, tmp) > 0) {
                strcpy(sDash, tmp);
            } else {
                // If we are not in the first iteration, break the loop
                if (!firstTime) {
                    break;
                }
            }
        }
        
        // If this is the first iteration, check if we can print a uniform string
        if (firstTime) {
            firstTime = 0;
            // If 2^K is greater than N, print the first character of sDash N times
            if (pow(2, K) > N) {
                char c = sDash[0];
                for (int i = 0; i < N; i++) {
                    printf("%c", c);
                }
                printf("\n");
                free(S);
                free(T);
                free(revU);
                free(sDash);
                return 0;
            }
        } else {
            // Increase the step size for the next iteration
            step += step;
        }
        
        // Decrement K and update S for the next operation
        K--;
        free(S);
        S = (char *)malloc((N + 1) * sizeof(char));
        strcpy(S, sDash);
        // Reverse S
        for (int i = 0; i < N / 2; i++) {
            char temp = S[i];
            S[i] = S[N - 1 - i];
            S[N - 1 - i] = temp;
        }
        
        free(T);
        free(revU);
        free(sDash);
    }
    
    // Print the final result after all operations
    printf("%s\n", S);
    
    // Free allocated memory
    free(S);
    
    return 0;
}

// <END-OF-CODE>
