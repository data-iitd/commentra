
#include <stdio.h>
#include <string.h>

int main() {
    // Create variables to read input from the console
    int N, K;
    char S[100001];
    
    // Read the integer N (length of the string) and K (number of operations)
    scanf("%d %d", &N, &K);
    
    // Read the initial string and store it in the array S
    scanf("%s", S);
    
    // Flag to check if we are processing the first iteration
    int firstTime = 1;
    // Variable to control the step size for substring extraction
    int step = 1;
    
    // Loop until K operations are performed
    while (K > 0) {
        // Create a reversed copy of the current string S
        char T[100001];
        strcpy(T, S);
        strrev(T);
        
        // Create a new string that combines S and its reverse, then reverse it
        char revU[200001];
        strcpy(revU, S);
        strcat(revU, T);
        strrev(revU);
        
        // Initialize a variable to keep track of the best string found so far
        char sDash[100001];
        strcpy(sDash, S);
        
        // Iterate through the string revU to find the lexicographically smallest substring
        for (int i = N; i >= 0; i -= step) {
            // Extract a substring from revU
            char tmp[100001];
            strncpy(tmp, revU + i, N);
            tmp[N] = '\0';
            
            // Compare and update sDash if a smaller substring is found
            if (strcmp(sDash, tmp) > 0) {
                strcpy(sDash, tmp);
            } else {
                // If we are not in the first iteration, break the loop
                if (firstTime == 0) {
                    break;
                }
            }
        }
        
        // If this is the first iteration, check if we can print a uniform string
        if (firstTime == 1) {
            firstTime = 0;
            // If 2^K is greater than N, print the first character of sDash N times
            if (pow(2, K) > N) {
                for (int i = 0; i < N; i++) {
                    printf("%c", sDash[0]);
                }
                printf("\n");
                return 0;
            }
        } else {
            // Increase the step size for the next iteration
            step *= 2;
        }
        
        // Decrement K and update S for the next operation
        K--;
        strcpy(S, sDash);
        strrev(S);
    }
    
    // Print the final result after all operations
    printf("%s\n", S);
    
    // End of code
    return 0;
}
