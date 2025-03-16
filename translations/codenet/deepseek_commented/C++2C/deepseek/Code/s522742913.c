#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    // Step 1: Input Handling
    // The program starts by taking a string input from the user.
    char source[11];
    if (scanf("%10s", source) != 1) {
        return -1;
    }

    // It checks if the length of the input string is within the valid range (1 to 10 characters).
    // If not, it returns -1.
    if (strlen(source) > 10 || strlen(source) < 1) {
        return -1;
    }

    // Step 2: Calculation Setup
    // The program calculates the maximum number of combinations that can be formed
    // by placing '+' signs between the digits of the input string.
    // This is done using the formula 2^(n-1), where n is the length of the input string.
    int max_i = (int)pow(2, strlen(source) - 1);

    // Step 3: Iterating Over Combinations
    // The program iterates over all possible combinations of placing '+' signs between the digits.
    // For each combination, it calculates the sum of the numbers formed by the substrings separated by '+' signs.
    double sum = 0;

    for (int i = 0; i < max_i; ++i) {
        char working[11];
        strcpy(working, source);
        char plus[11] = {0};
        sprintf(plus, "%b", i);
        int len = strlen(plus);
        int j = 0;
        for (int k = strlen(source) - 1; k >= 0; --k) {
            if (j < len && plus[len - j - 1] == '1') {
                working[k + 1] = '\0';
                sum += atof(working);
                strcpy(working, source + k + 1);
            }
            ++j;
        }
        sum += atof(working);
    }

    // Step 4: Output
    // Finally, the program outputs the sum of all possible combinations.
    printf("%.0f\n", sum);

    return 0;
}
