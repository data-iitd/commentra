#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
    int N;
    char S[1000];

    // Read an integer input N and a string input S from the user
    scanf("%d", &N);
    scanf("%s", S);

    // Initialize variables to count the number of occurrences of each color
    int rNum = 0, gNum = 0, bNum = 0;

    // Count the number of occurrences of each color in the string S
    for (int i = 0; i < N; i++) {
        if (S[i] == 'R') rNum++;
        else if (S[i] == 'G') gNum++;
        else if (S[i] == 'B') bNum++;
    }

    // Initialize a variable sum to 0
    int sum = 0;

    // Use a for loop to iterate through each step from 1 to the ceiling of N/2
    for (int step = 1; step <= (int)ceil((double)N / 2); step++) {
        // Initialize a temporary string s
        char s[4] = {0};

        // Copy three consecutive elements of the string S to s
        for (int i = 0; i < 3; i++) {
            s[i] = S[i];
        }

        // Check if the string s is equal to any of the six possible color combinations: "RGB", "RBG", "BGR", "BRG", "GBR", or "GRB"
        if (strcmp(s, "RGB") == 0 || strcmp(s, "RBG") == 0 || strcmp(s, "BGR") == 0 || strcmp(s, "BRG") == 0 || strcmp(s, "GBR") == 0 || strcmp(s, "GRB") == 0) {
            sum += 1;
        }
    }

    // Print the result of the calculation: rNum * gNum * bNum - sum
    printf("%d\n", rNum * gNum * bNum - sum);

    return 0;
}
