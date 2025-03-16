#include <stdio.h>
#include <string.h>
#include <math.h>

void calculate(int n, char s[]) {
    // Counting occurrences of 'R', 'G', and 'B'
    int rNum = 0, gNum = 0, bNum = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R') rNum++;
        else if (s[i] == 'G') gNum++;
        else if (s[i] == 'B') bNum++;
    }

    // Initializing sum to 0
    int sum = 0;

    // Iterating over possible step sizes from 1 to ceil(n / 2)
    for (int step = 1; step <= ceil(n / 2.0); step++) {
        // Iterating over possible starting indices for the substring
        for (int i = 0; i < n - 2 * step; i++) {
            // Forming a substring of length 3
            char substring[4];
            substring[0] = s[i];
            substring[1] = s[i + step];
            substring[2] = s[i + 2 * step];
            substring[3] = '\0'; // Null-terminate the string

            // Checking if the substring matches any of the patterns
            if (strcmp(substring, "RGB") == 0 || strcmp(substring, "RBG") == 0 ||
                strcmp(substring, "BGR") == 0 || strcmp(substring, "BRG") == 0 ||
                strcmp(substring, "GBR") == 0 || strcmp(substring, "GRB") == 0) {
                sum++;
            }
        }
    }

    // Printing the product of the counts of 'R', 'G', and 'B' minus sum
    printf("%d\n", rNum * gNum * bNum - sum);
}

int main() {
    int N;
    scanf("%d", &N);
    char S[100]; // Assuming the maximum length of S is 100
    scanf("%s", S);

    // Calling the function calculate with N and S as arguments
    calculate(N, S);

    return 0;
}

// <END-OF-CODE>
