#include <stdio.h>
#include <string.h>
#include <math.h>

void calculate(int n, char *s) {
    // Count occurrences of 'R', 'G', and 'B'
    int rNum = 0, gNum = 0, bNum = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R') rNum++;
        else if (s[i] == 'G') gNum++;
        else if (s[i] == 'B') bNum++;
    }

    // Initialize sum to 0
    int sum = 0;

    // Iterate through each step from 0 to the ceiling of N/2
    for (int step = 0; step < ceil(n / 2.0); step++) {
        // Create a string to hold the three consecutive elements
        char temp[4] = {0}; // 3 characters + 1 for null terminator
        for (int i = 0; i < 3 && (step * 3 + i) < n; i++) {
            temp[i] = s[step * 3 + i];
        }
        
        // Check if the string temp is equal to any of the six possible color combinations
        if (strcmp(temp, "RGB") == 0 || strcmp(temp, "RBG") == 0 || 
            strcmp(temp, "BGR") == 0 || strcmp(temp, "BRG") == 0 || 
            strcmp(temp, "GBR") == 0 || strcmp(temp, "GRB") == 0) {
            sum++;
        }
    }

    // Print the result of the calculation
    printf("%d\n", rNum * gNum * bNum - sum);
}

int main() {
    int N;
    scanf("%d", &N);
    char S[N + 1]; // +1 for null terminator
    scanf("%s", S);

    calculate(N, S);
    
    return 0;
}

// <END-OF-CODE>
