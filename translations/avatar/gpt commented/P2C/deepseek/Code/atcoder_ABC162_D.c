#include <stdio.h>
#include <string.h>
#include <math.h>

void calculate(int n, char s[]) {
    // Initialize variables to count occurrences of each color
    int rNum = 0, gNum = 0, bNum = 0;
    
    // Count the occurrences of each color in the string
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R') rNum++;
        else if (s[i] == 'G') gNum++;
        else if (s[i] == 'B') bNum++;
    }
    
    // Initialize a variable to keep track of the number of valid RGB combinations found
    int sum = 0;
    
    // Loop through possible steps to form combinations of three characters
    for (int step = 1; step <= (n + 1) / 2; step++) {
        // Loop through the string to form combinations based on the current step
        for (int i = 0; i <= n - 2 * step; i++) {
            // Create a substring of three characters at the current indices
            char s1 = s[i];
            char s2 = s[i + step];
            char s3 = s[i + step * 2];
            
            // Check if the formed substring is one of the valid RGB permutations
            if ((s1 == 'R' && s2 == 'G' && s3 == 'B') ||
                (s1 == 'R' && s2 == 'B' && s3 == 'G') ||
                (s1 == 'G' && s2 == 'R' && s3 == 'B') ||
                (s1 == 'G' && s2 == 'B' && s3 == 'R') ||
                (s1 == 'B' && s2 == 'R' && s3 == 'G') ||
                (s1 == 'B' && s2 == 'G' && s3 == 'R')) {
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
    char S[N + 1];
    scanf("%s", S);
    
    // Call the calculate function with the inputs N and S
    calculate(N, S);
    
    return 0;
}
