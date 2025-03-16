#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>

// Define a helper function 'find' to locate the indices of a character in a string
int *find(char *s, char ch) {
    // Declare a pointer to an integer array
    int *indices = NULL;

    // Initialize the pointer to NULL
    indices = NULL;

    // Find the length of the string's'
    int len = strlen(s);

    // Initialize the index counter as 0
    int i = 0;

    // Initialize the index array as NULL
    indices = (int *) malloc(sizeof(int) * len);

    // Check if the string's' is not empty
    if (s!= NULL) {
        // Iterate through each character in the string's'
        for (i = 0; i < len; i++) {
            // Check if the current character is equal to the character 'ch'
            if (s[i] == ch) {
                // If the current character is equal to the character 'ch', store the index of the current character in the array 'indices'
                indices[i] = i;
            }
        }
    }

    // Return the pointer to the array 'indices'
    return indices;
}

// Define a helper function 'combinations' to generate all possible combinations of indices of '0' characters
int **combinations(int *indices, int len) {
    // Declare a pointer to an integer array
    int **combs = NULL;

    // Initialize the pointer to NULL
    combs = NULL;

    // Check if the array 'indices' is not empty
    if (indices!= NULL) {
        // Find the number of combinations
        int num = pow(2, len);

        // Initialize the index counter as 0
        int i = 0;

        // Initialize the index array as NULL
        combs = (int **) malloc(sizeof(int *) * num);

        // Iterate through each combination
        for (i = 0; i < num; i++) {
            // Initialize the array 'combs' as NULL
            combs[i] = (int *) malloc(sizeof(int) * len);
        }

        // Initialize the index counter as 0
        i = 0;

        // Iterate through each combination
        for (i = 0; i < num; i++) {
            // Initialize the index counter as 0
            int j = 0;

            // Iterate through each index of '0' character
            for (j = 0; j < len; j++) {
                // Check if the current bit is set in the current combination
                if (i & (1 << j)) {
                    // If the current bit is set, store the index of the current '0' character in the array 'combs'
                    combs[i][j] = indices[j];
                }
            }
        }
    }

    // Return the pointer to the array 'combs'
    return combs;
}

// Define a helper function'score' to calculate the score for a given combination
int score(int *comb, int len) {
    // Initialize the score as 0
    int score = 0;

    // Check if the array 'comb' is not empty
    if (comb!= NULL) {
        // Initialize the index counter as 0
        int i = 0;

        // Iterate through each index of '0' character
        for (i = 0; i < len; i++) {
            // Check if the current index of '0' character is not equal to the previous index of '0' character
            if (comb[i]!= comb[i - 1]) {
                // If the current index of '0' character is not equal to the previous index of '0' character, increment the score by 2
                score += 2;
            }
        }

        // Calculate the number of '1's in the string
        int ones = 0;

        // Iterate through each character in the string's'
        for (i = 0; i < len; i++) {
            // Check if the current character is equal to '1'
            if (s[i] == '1') {
                // If the current character is equal to '1', increment the number of '1's by 1
                ones++;
            }
        }

        // Calculate the number of '0's in the string
        int zeros = len - ones;

        // Calculate the number of '1's between the first and last '0' character
        int ones_between = ones - (comb[0] - comb[len - 1] - 1);

        // Calculate the number of '0's between the first and last '0' character
        int zeros_between = zeros - (comb[len - 1] - comb[0] - 1);

        // Calculate the number of '1's between the second and last '0' character
        int ones_between_2 = ones - (comb[1] - comb[len - 1] - 1);

        // Calculate the number of '0's between the second and last '0' character
        int zeros_between_2 = zeros - (comb[len - 1] - comb[1] - 1);

        // Calculate the number of '1's between the third and last '0' character
        int ones_between_3 = ones - (comb[2] - comb[len - 1] - 1);

        // Calculate the number of '0's between the third and last '0' character
        int zeros_between_3 = zeros - (comb[len - 1] - comb[2] - 1);

        // Calculate the number of '1's between the fourth and last '0' character
        int ones_between_4 = ones - (comb[3] - comb[len - 1] - 1);

        // Calculate the number of '0's between the fourth and last '0' character
        int zeros_between_4 = zeros - (comb[len - 1] - comb[3] - 1);

        // Calculate the number of '1's between the fifth and last '0' character
        int ones_between_5 = ones - (comb[4] - comb[len - 1] - 1);

        // Calculate the number of '0's between the fifth and last '0' character
        int zeros_between_5 = zeros - (comb[len - 1] - comb[4] - 1);

        // Calculate the number of '1's between the sixth and last '0' character
        int ones_between_6 = ones - (comb[5] - comb[len - 1] - 1);

        // Calculate the number of '0's between the sixth and last '0' character
        int zeros_between_6 = zeros - (comb[len - 1] - comb[5] - 1);

        // Calculate the number of '1's between the seventh and last '0' character
        int ones_between_7 = ones - (comb[6] - comb[len - 1] - 1);

        // Calculate the number of '0's between the seventh and last '0' character
        int zeros_between_7 = zeros - (comb[len - 1] - comb[6] - 1);

        // Calculate the number of '1's between the eighth and last '0' character
        int ones_between_8 = ones - (comb[7] - comb[len - 1] - 1);

        // Calculate the number of '0's between the eighth and last '0' character
        int zeros_between_8 = zeros - (comb[len - 1] - comb[7] - 1);

        // Calculate the number of '1's between the ninth and last '0' character
        int ones_between_9 = ones - (comb[8] - comb[len - 1] - 1);

        // Calculate the number of '0's between the ninth and last '0' character
        int zeros_between_9 = zeros - (comb[len - 1] - comb[8] - 1);

        // Calculate the number of '1's between the tenth and last '0' character
        int ones_between_10 = ones - (comb[9] - comb[len - 1] - 1);

        // Calculate the number of '0's between the tenth and last '0' character
        int zeros_between_10 = zeros - (comb[len - 1] - comb[9] - 1);

        // Calculate the number of '1's between the eleventh and last '0' character
        int ones_between_11 = ones - (comb[10] - comb[len - 1] - 1);

        // Calculate the number of '0's between the eleventh and last '0' character
        int zeros_between_11 = zeros - (comb[len - 1] - comb[10] - 1);

        // Calculate the number of '1's between the twelfth and last '0' character
        int ones_between_12 = ones - (comb[11] - comb[len - 1] - 1);

        // Calculate the number of '0's between the twelfth and last '0' character
        int zeros_between_12 = zeros - (comb[len - 1] - comb[11] - 1);

        // Calculate the number of '1's between the thirteenth and last '0' character
        int ones_between_13 = ones - (comb[12] - comb[len - 1] - 1);

        // Calculate the number of '0's between the thirteenth and last '0' character
        int zeros_between_13 = zeros - (comb[len - 1] - comb[12] - 1);

        // Calculate the number of '1's between the fourteenth and last '0' character
        int ones_between_14 = ones - (comb[13] - comb[len - 1] - 1);

        // Calculate the number of '0's between the fourteenth and last '0' character
        int zeros_between_14 = zeros - (comb[len - 1] - comb[13] - 1);

        // Calculate the number of '1's between the fifteenth and last '0' character
        int ones_between_15 = ones - (comb[14] - comb[len - 1] - 1);

        // Calculate the number of '0's between the fifteenth and last '0' character
        int zeros_between_15 = zeros - (comb[len - 1] - comb[14] - 1);

        // Calculate the number of '1's between the sixteenth and last '0' character
        int ones_between_16 = ones - (comb[15] - comb[len - 1] - 1);

        // Calculate the number of '0's between the sixteenth and last '0' character
        int zeros_between_16 = zeros - (comb[len - 1] - comb[15] - 1);

        // Calculate the number of '1's between the seventeenth and last '0' character
        int ones_between_17 = ones - (comb[16] - comb[len - 1] - 1);

        // Calculate the number of '0's between the seventeenth and last '0' character
        int zeros_between_17 = zeros - (comb[len - 1] - comb[16] - 1);

        // Calculate the number of '1's between the eighteenth and last '0' character
        int ones_between_18 = ones - (comb[17] - comb[len - 1] - 1);

        // Calculate the number of '0's between the eighteenth and last '0' character
        int zeros_between_18 = zeros - (comb[len - 1] - comb[17] - 1);

        // Calculate the number of '1's between the nineteenth and last '0' character
        int ones_between_19 = ones - (comb[18] - comb[len - 1] - 1);

        // Calculate the number of '0's between the nineteenth and last '0' character
        int zeros_between_19 = zeros - (comb[len - 1] - comb[18] - 1);

        // Calculate the number of '1's between the twentieth and last '0' character
        int ones_between_20 = ones - (comb[19] - comb[len - 1] - 1);

        // Calculate the number of '0's between the twentieth and last '0' character
        int zeros_between_20 = zeros - (comb[len - 1] - comb[19] - 1);

        // Calcu