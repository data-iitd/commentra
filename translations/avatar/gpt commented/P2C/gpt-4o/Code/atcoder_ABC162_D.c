#include <stdio.h>
#include <string.h>
#include <math.h>

void calculate(int n, char s[]) {
    // Count the occurrences of each color in the string
    int rNum = 0, gNum = 0, bNum = 0;
    
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R') rNum++;
        else if (s[i] == 'G') gNum++;
        else if (s[i] == 'B') bNum++;
    }
    
    // Initialize a variable to keep track of the number of valid RGB combinations found
    int sum = 0;
    
    // Loop through possible steps to form combinations of three characters
    for (int step = 1; step <= ceil(n / 2.0); step++) {
        // Loop through the string to form combinations based on the current step
        for (int i = 0; i <= n - 2 * step; i++) {
            // Create a substring of three characters at the current indices
            char combination[4];
            combination[0] = s[i];
            combination[1] = s[i + step];
            combination[2] = s[i + step * 2];
            combination[3] = '\0'; // Null-terminate the string
            
            // Check if the formed substring is one of the valid RGB permutations
            if (strcmp(combination, "RGB") == 0 || strcmp(combination, "RBG") == 0 ||
                strcmp(combination, "BGR") == 0 || strcmp(combination, "BRG") == 0 ||
                strcmp(combination, "GBR") == 0 || strcmp(combination, "GRB") == 0) {
                // Increment the count of valid combinations found
                sum++;
            }
        }
    }
    
    // Calculate and print the result: total combinations minus the valid RGB combinations found
    printf("%d\n", rNum * gNum * bNum - sum);
}

int main() {
    // Read the integer input N which represents the length of the string
    int N;
    scanf("%d", &N);
    
    // Read the string input S which consists of characters 'R', 'G', and 'B'
    char S[100001]; // Assuming the maximum length of S is 100000
    scanf("%s", S);
    
    // Call the calculate function with the inputs N and S
    calculate(N, S);
    
    return 0;
}

// <END-OF-CODE>
